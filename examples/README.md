# Examples

This directory contains example code and tutorials for the ROBO-01 robot.

## Beginner Examples

1. **Motor Test** - Test basic motor control
2. **Ultrasonic Test** - Test distance sensor
3. **Line Sensor Test** - Test line detection sensor
4. **LED Blink** - Basic Arduino test

## Intermediate Examples

5. **Forward/Backward** - Basic movement
6. **Turn Test** - Rotation and steering
7. **Speed Control** - Variable speed movement
8. **Distance Measurement** - Read and display distances

## Advanced Examples

9. **Object Avoidance** - Detect and avoid obstacles
10. **Line Following** - Follow a black line on white surface
11. **Maze Solver** - Navigate through a maze
12. **Remote Control** - Control via Bluetooth or IR (if equipped)

## Using Examples

1. Open example in Arduino IDE
2. Connect robot via USB
3. Select correct board and port (Tools menu)
4. Upload to robot
5. Disconnect USB and power with batteries for autonomous operation

## Stopping a Running Program

When a sketch is uploaded, it runs automatically on power-up. To stop motors:

### Method 1: Emergency Stop via Serial (Recommended)
Most motor sketches include a serial stop command:
1. Connect via serial monitor: `~/.local/bin/arduino-cli monitor -p /dev/ttyUSB0 -c baudrate=9600`
2. Type `S` and press Enter
3. Motors will stop immediately

### Method 2: Physical Stop (Immediate)
- **Remove battery pack** - Motors can't run without power
- **Unplug USB** - Cuts all power to Arduino

### Method 3: Upload Blank Sketch
Upload a do-nothing sketch to prevent motors from running on power-up.

## Programming Tips

- Always test individual components before combining
- Start with slow speeds for testing
- Use Serial.print() for debugging
- Keep battery pack disconnected during programming
- Remove batteries when not testing to prevent accidental motor activation