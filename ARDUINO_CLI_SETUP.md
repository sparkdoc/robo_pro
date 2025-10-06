# Arduino CLI Setup

Arduino CLI has been successfully installed and configured!

## Installation Details

- **Location**: `~/.local/bin/arduino-cli`
- **Version**: 1.3.1
- **Config**: `~/.arduino15/arduino-cli.yaml`
- **Architecture**: ARM64 (aarch64)

## Installed Components

✅ **Arduino AVR Core** (v1.8.6)
- Supports Arduino Uno, Nano, and compatible boards
- Includes avr-gcc compiler and avrdude uploader

✅ **Adafruit Motor Shield Library** (v1.0.1)
- For controlling DC motors on ROBO-01

## Quick Reference Commands

### Compile a Sketch
```bash
~/.local/bin/arduino-cli compile --fqbn arduino:avr:uno path/to/sketch
```

### Upload to Board
```bash
~/.local/bin/arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno path/to/sketch
```

### List Connected Boards
```bash
~/.local/bin/arduino-cli board list
```

### Install Additional Libraries
```bash
~/.local/bin/arduino-cli lib install "LibraryName"
```

### Search for Libraries
```bash
~/.local/bin/arduino-cli lib search keyword
```

### Monitor Serial Output
```bash
~/.local/bin/arduino-cli monitor -p /dev/ttyACM0
```

## Usage with ROBO-01

1. **Connect robot via USB**
2. **Find the port**: `~/.local/bin/arduino-cli board list`
3. **Compile**: `~/.local/bin/arduino-cli compile --fqbn arduino:avr:uno examples/01_motor_test`
4. **Upload**: `~/.local/bin/arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno examples/01_motor_test`

## Adding to PATH (Optional)

To use `arduino-cli` without the full path, add this to your `~/.bashrc`:

```bash
export PATH="$HOME/.local/bin:$PATH"
```

Then reload: `source ~/.bashrc`

## Typical Workflow

```bash
# Write code in PyCharm/your IDE
vim examples/01_motor_test/01_motor_test.ino

# Compile
~/.local/bin/arduino-cli compile --fqbn arduino:avr:uno examples/01_motor_test

# Upload
~/.local/bin/arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno examples/01_motor_test

# Monitor serial output
~/.local/bin/arduino-cli monitor -p /dev/ttyACM0 -c baudrate=9600
```

## Common Board FQBNs

- Arduino Uno: `arduino:avr:uno`
- Arduino Nano: `arduino:avr:nano`
- Arduino Mega: `arduino:avr:mega`

## Troubleshooting

### Permission Denied on Upload
Add your user to the dialout group:
```bash
sudo usermod -a -G dialout $USER
```
Then log out and back in.

### Board Not Found
Check USB connection and permissions:
```bash
ls -l /dev/ttyACM* /dev/ttyUSB*
```

### Library Not Found
Update library index:
```bash
~/.local/bin/arduino-cli lib update-index
```
