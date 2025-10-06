# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a development repository for the **OSEPP Robo Pro Robotic Basics Kit (ROBO-01)**, an Arduino-compatible educational robotics platform. The robot features:
- DC motors controlled via Adafruit Motor Shield
- HC-SR04 ultrasonic distance sensor
- IR line-following sensors
- Aluminum chassis with 6x AA battery power

## Development Workflow

### Arduino CLI Setup

This project uses **Arduino CLI** (not Arduino IDE) for compilation and uploading. The CLI is installed at `~/.local/bin/arduino-cli`.

**FQBN (Fully Qualified Board Name)**: `arduino:avr:uno` (default for ROBO-01)

### Common Commands

**Compile a sketch:**
```bash
./compile.sh examples/01_motor_test
```

**Upload to robot:**
```bash
./upload.sh examples/01_motor_test /dev/ttyACM0
```
Note: Port defaults to `/dev/ttyACM0` but may vary (`/dev/ttyUSB0`, `/dev/ttyACM1`, etc.)

**Find connected boards:**
```bash
~/.local/bin/arduino-cli board list
```

**Monitor serial output (9600 baud):**
```bash
~/.local/bin/arduino-cli monitor -p /dev/ttyACM0 -c baudrate=9600
```

**Install additional libraries:**
```bash
~/.local/bin/arduino-cli lib install "LibraryName"
```

**Direct compile/upload (without helper scripts):**
```bash
~/.local/bin/arduino-cli compile --fqbn arduino:avr:uno path/to/sketch
~/.local/bin/arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno path/to/sketch
```

## Code Architecture

### Directory Structure

- `arduino/sketches/` - Main robot programs
- `arduino/tests/` - Individual component tests
- `examples/` - Tutorial sketches (motor, sensors, behaviors)
- `libraries/` - Documentation for Arduino libraries (actual libs in `~/.arduino15/`)
- `python/` - Python scripts for serial communication and data logging
- `docs/` - Hardware documentation and assembly notes

### Hardware Abstraction

**Motor Control Pattern:**
All motor code uses the Adafruit Motor Shield library (`AFMotor.h`):
```cpp
#include <AFMotor.h>
AF_DCMotor motorLeft(1);   // M1 port
AF_DCMotor motorRight(2);  // M2 port
```

Motor ports (M1-M4) are configurable based on physical wiring. Always verify during assembly.

**Sensor Pin Conventions:**
- Ultrasonic: Trigger on digital pin 9, Echo on pin 10 (verify with kit docs)
- Line sensors: Analog pins A0 (left) and A1 (right) (verify with kit docs)

Pin assignments in example sketches are **placeholders** - actual pins depend on the physical shield/board configuration.

### Code Patterns

**Standard Arduino Sketch Structure:**
- `setup()` - Initialize serial, pins, motor speeds
- `loop()` - Main behavior logic
- Helper functions for movement primitives (forward, backward, turn, stop)

**Serial Debugging:**
All sketches use 9600 baud for serial output. Use `Serial.println()` liberally for debugging since there's no display.

**Autonomous Operation:**
Robot runs on battery power when disconnected from USB. Ensure code doesn't rely on serial communication for core functionality.

## Key Considerations

### When Creating New Sketches

1. **Motor Safety**: Always include a stop/release mechanism. Use `motorLeft.run(RELEASE)` to cut power.
2. **Pin Verification**: Never assume pin numbers - they vary by shield version. Comment pin assignments clearly.
3. **Library Dependencies**: Adafruit Motor Shield library is pre-installed, but document any additional libs needed.
4. **Sketch Naming**: Arduino requires sketch folder name to match `.ino` filename (e.g., `my_robot/my_robot.ino`).

### Testing Workflow

Always test components individually before integration:
1. Motor test → verify movement directions
2. Sensor tests → verify readings and thresholds
3. Combined behaviors → implement robot logic

### Common Pitfalls

- **Permission errors on upload**: User must be in `dialout` group (`sudo usermod -a -G dialout $USER`)
- **Compilation with multiple .ino files**: Arduino CLI compiles entire sketch directory, not individual files
- **Serial monitor conflicts**: Close monitor before uploading new code
- **Battery vs USB power**: Motors draw significant current - use batteries for motor testing, not USB power alone

## Python Integration

Python scripts in `python/` use `pyserial` to communicate with Arduino via USB serial. The robot can accept single-character commands or JSON messages depending on the Arduino sketch's serial protocol.

Install Python dependencies in the existing venv:
```bash
source .venv/bin/activate
pip install pyserial
```

## Additional Resources

- Full Arduino CLI reference: `ARDUINO_CLI_SETUP.md`
- Kit documentation: `README.md`
- Component-specific guides: `docs/README.md`