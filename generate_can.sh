#!/bin/bash
#
# CAN Library Generation Script
#
# Usage:
#   ./generate_can.sh          # Generate CAN library files
#   ./generate_can.sh --check  # Check if files are up to date (for CI)
#
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
VENV_DIR="$SCRIPT_DIR/.venv"
CANTOOLS_VERSION="39.4.13"
GEN_DIR="$SCRIPT_DIR/gen"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

log_info() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

log_warn() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Set up virtual environment and install cantools
setup_env() {
    if [ ! -d "$VENV_DIR" ]; then
        log_info "Creating virtual environment..."
        python3 -m venv "$VENV_DIR"
    fi

    # Activate venv
    source "$VENV_DIR/bin/activate"

    # Check if cantools is installed with correct version
    INSTALLED_VERSION=$(python -c "import cantools; print(cantools.__version__)" 2>/dev/null || echo "none")
    if [ "$INSTALLED_VERSION" != "$CANTOOLS_VERSION" ]; then
        log_info "Installing cantools==$CANTOOLS_VERSION..."
        pip install --quiet cantools==$CANTOOLS_VERSION
    fi
}

# Strip the file header for comparison
# cantools generates different header comments on different platforms,
# so we strip everything before the actual code starts.
# For .h files: keep from #ifndef onwards
# For .c files: keep from #include onwards
strip_header() {
    local file="$1"
    local temp_file="${file}.tmp"

    # Check if filename contains .h (handles both .h and .h.orig)
    if [[ "$file" == *".h"* ]]; then
        # For header files, keep from #ifndef onwards
        sed -n '/#ifndef/,$p' "$file" > "$temp_file"
    else
        # For source files, keep from first #include onwards
        sed -n '/#include/,$p' "$file" > "$temp_file"
    fi

    mv "$temp_file" "$file"
}

# Generate CAN library files
generate() {
    cd "$SCRIPT_DIR"

    log_info "Generating DBC file from Python definitions..."
    python generate.py

    log_info "Generating C source files from DBC..."
    python -m cantools generate_c_source -o gen gen/FEB_CAN.dbc

    log_info "Stripping headers from generated files..."
    strip_header "$GEN_DIR/feb_can.h"
    strip_header "$GEN_DIR/feb_can.c"

    log_info "Generation complete!"
}

# Check mode for CI - compares generated files without modifying committed files
check() {
    cd "$SCRIPT_DIR"

    # Create temp directory for fresh generation
    TEMP_DIR=$(mktemp -d)
    trap "rm -rf $TEMP_DIR" EXIT

    # Copy current gen files to temp for comparison
    cp "$GEN_DIR/FEB_CAN.dbc" "$TEMP_DIR/FEB_CAN.dbc.orig"
    cp "$GEN_DIR/feb_can.h" "$TEMP_DIR/feb_can.h.orig"
    cp "$GEN_DIR/feb_can.c" "$TEMP_DIR/feb_can.c.orig"

    # Strip timestamps from originals for comparison
    strip_header "$TEMP_DIR/feb_can.h.orig"
    strip_header "$TEMP_DIR/feb_can.c.orig"

    log_info "Generating fresh files for comparison..."
    log_info "Using cantools version: $(python -c 'import cantools; print(cantools.__version__)')"
    log_info "Python version: $(python --version)"
    python generate.py

    python -m cantools generate_c_source -o "$TEMP_DIR" gen/FEB_CAN.dbc

    # Strip timestamps from newly generated files
    strip_header "$TEMP_DIR/feb_can.h"
    strip_header "$TEMP_DIR/feb_can.c"

    # Copy DBC to temp for comparison
    cp "$GEN_DIR/FEB_CAN.dbc" "$TEMP_DIR/FEB_CAN.dbc"

    # Compare files
    DIFF_FOUND=false

    log_info "Comparing generated files..."

    if ! diff -q "$TEMP_DIR/FEB_CAN.dbc" "$TEMP_DIR/FEB_CAN.dbc.orig" > /dev/null 2>&1; then
        log_error "gen/FEB_CAN.dbc differs from committed version"
        echo "--- Diff output ---"
        diff "$TEMP_DIR/FEB_CAN.dbc.orig" "$TEMP_DIR/FEB_CAN.dbc" | head -50 || true
        echo "-------------------"
        DIFF_FOUND=true
    else
        echo "  gen/FEB_CAN.dbc: OK"
    fi

    if ! diff -q "$TEMP_DIR/feb_can.h" "$TEMP_DIR/feb_can.h.orig" > /dev/null 2>&1; then
        log_error "gen/feb_can.h differs from committed version"
        echo "--- Diff output ---"
        diff "$TEMP_DIR/feb_can.h.orig" "$TEMP_DIR/feb_can.h" | head -50 || true
        echo "-------------------"
        DIFF_FOUND=true
    else
        echo "  gen/feb_can.h: OK"
    fi

    if ! diff -q "$TEMP_DIR/feb_can.c" "$TEMP_DIR/feb_can.c.orig" > /dev/null 2>&1; then
        log_error "gen/feb_can.c differs from committed version"
        echo "--- Diff output ---"
        diff "$TEMP_DIR/feb_can.c.orig" "$TEMP_DIR/feb_can.c" | head -50 || true
        echo "-------------------"
        DIFF_FOUND=true
    else
        echo "  gen/feb_can.c: OK"
    fi

    if [ "$DIFF_FOUND" = true ]; then
        echo ""
        log_error "CAN library files are out of date!"
        echo ""
        echo "To fix, run:"
        echo "  cd common/FEB_CAN_Library_SN4"
        echo "  ./generate_can.sh"
        echo ""
        exit 1
    else
        echo ""
        log_info "All generated files are up to date."
    fi
}

# Main
main() {
    setup_env

    if [ "$1" = "--check" ]; then
        check
    else
        generate
    fi
}

main "$@"
