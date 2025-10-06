#!/bin/bash
# Helper script to compile Arduino sketches for ROBO-01

ARDUINO_CLI=~/.local/bin/arduino-cli
FQBN="arduino:avr:uno"

if [ -z "$1" ]; then
    echo "Usage: ./compile.sh <sketch_directory>"
    echo "Example: ./compile.sh examples/01_motor_test"
    exit 1
fi

SKETCH_PATH="$1"

echo "Compiling $SKETCH_PATH for Arduino Uno..."
$ARDUINO_CLI compile --fqbn $FQBN "$SKETCH_PATH"

if [ $? -eq 0 ]; then
    echo "✓ Compilation successful!"
else
    echo "✗ Compilation failed!"
    exit 1
fi
