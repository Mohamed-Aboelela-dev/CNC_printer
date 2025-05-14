# Arduino Stepper Motor Drawing Machine

This project controls a basic 2D drawing machine (plotter) using three stepper motors connected to an Arduino board. The system can move a pen in X and Y directions, and lift/lower it using a Z-axis stepper. The code automatically draws a square when powered on.

## Features

- Controls three stepper motors: X, Y, and Z (pen lift)
- Uses an 8-step sequence for smooth motor control
- Automatically draws a square on startup
- Adjustable step speed and precision

## Components

- **1x Arduino Uno**
- **3x Stepper Motor (5V DC)** — Typically 28BYJ-48
- **3x Stepper Motor Driver Board (ULN2003)**
- **2x Linear Axes (X and Y)** — With mounts/sliders for the motors
- **1x 12V Adapter** — To power the stepper motors via the driver boards
- **1x small breedboard**
- Jumper wires and breadboard (optional, for prototyping)
- Drawing surface and pen holder mechanism

## Pin Configuration

| Motor | Arduino Pins       |
|-------|--------------------|
| X     | 5, 4, 3, 2         |
| Y     | A0, A1, A2, A3     |
| Z     | 8, 9, 12, 13       |

## Software Setup

1. Install the Arduino IDE.
2. Upload the provided `.ino` code to your Arduino board.
3. Ensure all motors are wired correctly according to the pin configuration.
4. Power the board and motor drivers.

## Code Overview

- **`motorX`, `motorY`, `motorZ`**: Arrays holding pin assignments for each stepper motor.
- **`stepSequence`**: Defines an 8-step sequence for smooth motion control.
- **`moveTo(x, y)`**: Moves the pen to a specified (X, Y) coordinate.
- **`moveToZ(z)`**: Raises or lowers the pen.
- **`drawSquare()`**: A demo function that draws a square by moving in a square path.

## Adjustable Parameters

- `stepsPerMM`: Number of steps the motor needs to move 1mm. Adjust based on your specific stepper motor and mechanics.
- `stepDelay`: Delay in milliseconds between each step. Lower values = faster motion.

## Example Output

When powered, the system lifts the pen, moves to the origin, lowers the pen, draws a square, and lifts the pen again.

## Future Improvements

- Add serial or SD card support for importing G-code or custom drawings
- Implement acceleration/deceleration profiles
- Add a user interface for manual control

## License

MIT License

---

Created by [Your Name or Project Name]
