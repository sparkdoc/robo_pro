# Libraries

This directory contains Arduino libraries required for the ROBO-01 robot.

## Required Libraries

### OSEPP_Robotics Library
- **Download**: http://osepp.com/files/OSEPP_Robotics_101K.zip
- **Description**: Official OSEPP robotics library
- **Note**: May have compatibility issues with Arduino IDE 1.6.6+

### Adafruit Motor Shield Library (Alternative)
- **GitHub**: https://github.com/adafruit/Adafruit-Motor-Shield-library
- **Description**: Compatible motor control library
- **Installation**: Use Arduino Library Manager or clone from GitHub

### Additional Libraries

#### IR Remote (Optional)
- **GitHub**: https://github.com/shirriff/Arduino-IRremote
- **Description**: For IR remote control functionality

## Installation

### Method 1: Arduino Library Manager
1. Open Arduino IDE
2. Go to Sketch → Include Library → Manage Libraries
3. Search for "Adafruit Motor Shield"
4. Click Install

### Method 2: Manual Installation
1. Download the library ZIP file
2. Extract to Arduino libraries folder:
   - Windows: `Documents/Arduino/libraries/`
   - Mac: `~/Documents/Arduino/libraries/`
   - Linux: `~/Arduino/libraries/`
3. Restart Arduino IDE

### Method 3: Git Clone
```bash
cd ~/Arduino/libraries/
git clone https://github.com/adafruit/Adafruit-Motor-Shield-library.git
```

## Troubleshooting

If you encounter "invalid library" errors:
- Use Arduino IDE 1.8.9 (recommended by OSEPP)
- Ensure library is in correct directory
- Check library folder structure (should contain .h and .cpp files)