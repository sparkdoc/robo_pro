# Python Code

This directory contains Python scripts for working with the ROBO-01 robot.

## Use Cases

- Serial communication with robot
- Data logging and analysis
- Remote control interfaces
- Vision processing (if camera is added)
- Custom control GUIs

## Setup

A Python virtual environment is already configured in the root `.venv` directory.

### Activate Virtual Environment

**Linux/Mac:**
```bash
source ../.venv/bin/activate
```

**Windows:**
```bash
..\.venv\Scripts\activate
```

### Common Libraries

For serial communication with Arduino:
```bash
pip install pyserial
```

For GUI applications:
```bash
pip install tkinter  # Usually pre-installed
```

For data visualization:
```bash
pip install matplotlib numpy
```

## Example: Serial Communication

```python
import serial
import time

# Connect to Arduino
ser = serial.Serial('/dev/ttyUSB0', 9600)  # Adjust port as needed
time.sleep(2)  # Wait for connection

# Send command
ser.write(b'F')  # Forward

# Read response
response = ser.readline().decode('utf-8').strip()
print(response)

ser.close()
```

## Finding Arduino Port

**Linux:**
```bash
ls /dev/ttyUSB* /dev/ttyACM*
```

**Mac:**
```bash
ls /dev/cu.*
```

**Windows:**
Check Device Manager under "Ports (COM & LPT)"