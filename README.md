# FEB CAN Library SN4

## Quick Start

Generate/regenerate the CAN library files:

```bash
cd common/FEB_CAN_Library_SN4
./generate_can.sh
```

The script automatically:
- Creates a Python virtual environment
- Installs the correct version of cantools (39.4.13)
- Generates the DBC file from Python message definitions
- Generates C source files from the DBC
- Normalizes timestamps for consistent diffs

## Commands

Visualize DBC file:
```bash
source .venv/bin/activate
python3 -m cantools dump gen/FEB_CAN.dbc
```

Check if generated files are up to date (used by CI):
```bash
./generate_can.sh --check
```

## Files and Directories

* `generate_can.sh`: Main script for generating CAN library files
* `generate.py`: Python script that generates a DBC file from `*_messages.py` files
* `*_messages.py`: CAN message definitions for each board (e.g., `bms_messages.py`)
* `/gen`: Directory containing generated code (DBC, C source, C header)

## Prerequisites

- Python 3.8 or higher
- pip

## Troubleshooting

**Error: `ModuleNotFoundError: No module named 'cantools'`**
- Run `./generate_can.sh` which will set up the environment automatically

**Error: `TypeError: Message.__init__() got an unexpected keyword argument 'strict'`**
- You have an incompatible version of cantools
- Delete `.venv/` and run `./generate_can.sh` to recreate with the correct version

**Error: `error: externally-managed-environment`**
- Run `./generate_can.sh` which uses a virtual environment automatically
