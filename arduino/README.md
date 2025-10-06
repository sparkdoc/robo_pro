# Arduino Code

This directory contains Arduino sketches for the ROBO-01 robot.

## Structure

- `sketches/` - Main Arduino programs (.ino files)
- `tests/` - Test code for individual components

## Basic Setup

```cpp
// Include required libraries
#include <AFMotor.h>  // Motor control
// or
// #include <OSEPP_Robotics.h>  // OSEPP library

// Pin definitions will depend on your specific wiring
// Refer to the ROBO-01 assembly guide for pin assignments
```

## Common Functions

### Motor Control
- Forward movement
- Backward movement
- Left/right turning
- Speed control

### Sensor Reading
- Ultrasonic distance measurement
- Line sensor detection

## Example Sketches

Check the `examples/` directory in the root of this repository for:
- Basic motor control
- Object avoidance
- Line following
- Combined behaviors