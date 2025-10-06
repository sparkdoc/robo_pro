# OSEPP Robo Pro Robotic Basics Kit (ROBO-01)

This repository contains code and documentation for working with the OSEPP Robo Pro Robotic Basics Kit.

## About the Kit

The OSEPP Robo Pro (ROBO-01) is an Arduino-compatible educational robotics kit designed for ages 10+ to learn programming, coding, and electronics fundamentals.

### Included Components

- Aluminum chassis
- Arduino-compatible microcontroller
- Motor driver
- Ultrasonic sensor (for object detection)
- Line sensor (for line following)
- Learning guide and assembly instructions

### Features

- **Object Avoidance**: Using ultrasonic sensor
- **Line Following**: Using line sensor
- **Basic Robot Control**: Movement and turning
- **Arduino Compatible**: Program with Arduino IDE or OSEPP Block IDE

## Programming Options

### Arduino CLI (Installed & Ready!) ✓

Command-line Arduino development - write code in your favorite IDE!

- **Location**: `~/.local/bin/arduino-cli`
- **Installed Libraries**: Adafruit Motor Shield library
- **Supported Boards**: Arduino Uno, Nano, and compatible
- **Quick Start**: See [ARDUINO_CLI_SETUP.md](ARDUINO_CLI_SETUP.md)
- **Helper Scripts**: `./compile.sh` and `./upload.sh`

### OSEPP Block IDE (Graphical - Optional)

A drag-and-drop graphical programming interface based on Blockly/Scratch Blocks.

- **Download**: https://osepp.com/oseppblock-ide
- **GitHub**: https://github.com/DIYOSEPP/oseppBlock
- **Requirements**: Node.js, Java, Python 2, Arduino IDE 1.8.9

### Arduino IDE (GUI - Optional)

Traditional Arduino IDE with graphical interface.

- **Required Library**: OSEPP_Robotics library
- **Download**: http://osepp.com/files/OSEPP_Robotics_101K.zip

## Repository Structure

```
.
├── arduino/          # Arduino sketches and programs
├── libraries/        # Arduino libraries (OSEPP_Robotics, etc.)
├── docs/            # Documentation and guides
├── examples/        # Example code and tutorials
└── python/          # Python scripts (if using Python interface)
```

## Getting Started

**Arduino CLI is already installed and configured!** You're ready to start programming.

### Quick Start

1. **Connect robot** via USB
2. **Compile an example**:
   ```bash
   ./compile.sh examples/01_motor_test
   ```
3. **Upload to robot**:
   ```bash
   ./upload.sh examples/01_motor_test /dev/ttyACM0
   ```
4. **Monitor serial output**:
   ```bash
   ~/.local/bin/arduino-cli monitor -p /dev/ttyACM0 -c baudrate=9600
   ```

See [ARDUINO_CLI_SETUP.md](ARDUINO_CLI_SETUP.md) for detailed commands and workflow.

### Stopping a Running Program

Programs run automatically on power-up. To stop motors:
- **Emergency stop via serial**: Type `S` in serial monitor (most motor sketches support this)
- **Physical stop**: Remove battery pack or unplug USB
- **Upload blank sketch**: Prevents motors from running on startup

See [examples/README.md](examples/README.md) for detailed stop instructions.

### Assembly

1. **Assemble the robot** following the included instructions
2. **Note pin connections** for motors and sensors
3. **Power with 6x AA batteries** for autonomous operation

## Power Requirements

- 6x AA batteries (not included)

## Resources

- **Official Product Page**: https://osepp.com/robotic-kits/258-robo-01-robo-pro-robotic-basics-kit
- **OSEPP Block IDE**: https://github.com/DIYOSEPP/oseppBlock
- **Adafruit Motor Shield Library**: https://github.com/adafruit/Adafruit-Motor-Shield-library
- **IR Remote Library**: https://github.com/shirriff/Arduino-IRremote

## License

Open Source - Educational Use