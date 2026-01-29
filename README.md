# FEB CAN Library SN4

## Commands

The following commands reference the [cantools](https://cantools.readthedocs.io) documentation.

Generate DBC file:
```
python3 generate.py
```

Visualize DBC file:
```
python3 -m cantools dump gen/FEB_CAN.dbc
```

Generate C files from DBC file:
```
python3 -m cantools generate_c_source -o gen gen/FEB_CAN.dbc
```

## Files and Directories

* `generate.py`: A Python file that generates a DBC file, using `*_messages.py` Python files.
* `*_messages.py`: A Python file that generates CAN messages for a single board (e.g., `bms_messages.py`).
* `/gen`: A directory for generated code.

## Setup

### Prerequisites

- Python 3.8 or higher
- pip

### Environment Setup

Modern macOS and Linux systems require using a virtual environment for Python packages. Choose one of the following options:

**Option A: Virtual Environment (recommended)**
```bash
cd common/FEB_CAN_Library_SN4
python3 -m venv .venv
source .venv/bin/activate
```

**Option B: Conda Environment**
```bash
conda create -n feb-can python=3.11
conda activate feb-can
```

### Install Dependencies

Install the specific version of cantools that is compatible with this project:

```bash
pip install cantools==39.4.13
```

> **Important:** Version 39.4.13 is required. Newer versions of cantools have removed the `strict` parameter used in the message definition files, which will cause generation to fail.

### Generation Workflow

With your environment activated, run the following commands to regenerate the CAN library:

```bash
# 1. Generate the DBC file from Python message definitions
python generate.py

# 2. Generate C source files from the DBC file
python -m cantools generate_c_source -o gen gen/FEB_CAN.dbc
```

## Troubleshooting

**Error: `ModuleNotFoundError: No module named 'cantools'`**
- Ensure your virtual environment is activated
- Run `pip install cantools==39.4.13`

**Error: `TypeError: Message.__init__() got an unexpected keyword argument 'strict'`**
- You have an incompatible version of cantools installed
- Run `pip install cantools==39.4.13` to install the correct version

**Error: `error: externally-managed-environment`**
- Your system Python requires using a virtual environment
- Follow the "Environment Setup" instructions above
