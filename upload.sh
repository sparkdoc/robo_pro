#!/bin/bash
# Helper script to upload Arduino sketches to ROBO-01

ARDUINO_CLI=~/.local/bin/arduino-cli
FQBN="arduino:avr:uno"

if [ -z "$1" ]; then
    echo "Usage: ./upload.sh <sketch_directory> [port]"
    echo "Example: ./upload.sh examples/01_motor_test /dev/ttyACM0"
    echo ""
    echo "Available boards:"
    $ARDUINO_CLI board list
    exit 1
fi

SKETCH_PATH="$1"
PORT="${2:-/dev/ttyACM0}"

echo "Compiling and uploading $SKETCH_PATH to $PORT..."
$ARDUINO_CLI compile --fqbn $FQBN "$SKETCH_PATH" && \
$ARDUINO_CLI upload -p "$PORT" --fqbn $FQBN "$SKETCH_PATH"

if [ $? -eq 0 ]; then
    echo "✓ Upload successful!"
else
    echo "✗ Upload failed!"
    exit 1
fi