// Define motor pins (from IN4 to IN1)
int motorX[4] = {5, 4, 3, 2};     // X-axis motor pins
int motorY[4] = {A0, A1, A2, A3}; // Y-axis motor pins
int motorZ[4] = {8, 9, 12, 13};   // Z-axis motor (pen)

const int stepsPerMM = 4;   // Steps per millimeter (adjust based on your setup)
int stepDelay = 2;          // Step speed (lower = faster)

// Current position variables
int posX = 0, posY = 0, posZ = 0;

// Step sequence for 8-step control of stepper motor
const int stepSequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setup() {
  // Initialize all motor pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(motorX[i], OUTPUT);
    pinMode(motorY[i], OUTPUT);
    pinMode(motorZ[i], OUTPUT);
  }

  delay(1000); // Wait for 1 second before starting

  drawSquare(); // Automatically draw the square
}

void loop() {
  // Empty because we don't want to repeat the drawing
}

// ========= Drawing Functions ==========

void drawSquare() {
  moveToZ(10);    // Lift the pen
  moveTo(0, 0);   // Move to starting position
  moveToZ(0);     // Lower the pen
  moveTo(200, 0); // Draw horizontal line
  moveTo(200, 200); // Draw vertical line
  moveTo(0, 200); // Draw horizontal line back
  moveTo(0, 0);   // Draw vertical line back
  moveToZ(10);    // Lift the pen
}

// ========= Core Movement Functions ==========

// Move to specific X,Y coordinates
void moveTo(int xTarget, int yTarget) {
  int dx = xTarget - posX;
  int dy = yTarget - posY;

  moveMotor(motorX, dx);
  moveMotor(motorY, dy);

  posX = xTarget;
  posY = yTarget;
}

// Move to specific Z position (pen up/down)
void moveToZ(int zTarget) {
  int dz = zTarget - posZ;
  moveMotor(motorZ, dz);
  posZ = zTarget;
}

// Move a specific motor by a number of steps
void moveMotor(int motorPins[4], int stepsCount) {
  int dir = (stepsCount > 0) ? 1 : -1; // Determine direction
  stepsCount = abs(stepsCount) * stepsPerMM; // Convert mm to steps

  // Execute each step
  for (int i = 0; i < stepsCount; i++) {
    // Cycle through step sequence
    for (int j = 0; j < 8; j++) {
      int index = (dir > 0) ? j : (7 - j); // Reverse sequence if going backward
      // Activate appropriate motor coils
      for (int k = 0; k < 4; k++) {
        digitalWrite(motorPins[k], stepSequence[index][k]);
      }
      delay(stepDelay);
    }
  }
}