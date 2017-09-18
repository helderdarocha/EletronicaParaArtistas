#include <Servo.h>

#define SERVO     6
#define LIGHTS    5

#define MOTOR_ENABLE 11
#define MOTOR_1      10
#define MOTOR_2       9

#define LIGHTS_SW 12

#define FWD_SW   7
#define BWD_SW   8
#define RIGHT_SW 2
#define LEFT_SW  3

#define LEFT   80
#define CENTER 90
#define RIGHT 100

#define MAX_SPEED 255

Servo servo;

void setup() {
  servo.attach(SERVO);
  servo.write(90); // centraliza o servo-motor
  
  pinMode(LIGHTS, OUTPUT);
  
  pinMode(MOTOR_1, OUTPUT);
  pinMode(MOTOR_2, OUTPUT);
  pinMode(MOTOR_ENABLE, OUTPUT);
  
  pinMode(FWD_SW, INPUT_PULLUP);
  pinMode(BWD_SW, INPUT_PULLUP);
  pinMode(RIGHT_SW, INPUT_PULLUP);
  pinMode(LEFT_SW, INPUT_PULLUP);

  pinMode(LIGHTS_SW, INPUT_PULLUP);
}

void loop() {
  int left  = digitalRead(LEFT_SW);
  int right = digitalRead(RIGHT_SW);
  int fwd   = digitalRead(FWD_SW);
  int bwd   = digitalRead(BWD_SW);
  int lights = digitalRead(LIGHTS_SW);

  digitalWrite(LIGHTS, !lights);

  if(left == right) {
    servo.write(CENTER);
  } else if (left == LOW) {
    servo.write(LEFT);
  } else { // right == LOW
    servo.write(RIGHT);
  }

  analogWrite(MOTOR_ENABLE, MAX_SPEED); // no speed control

  // if fwd == bwd => stop
  digitalWrite(MOTOR_1, fwd);
  digitalWrite(MOTOR_2, bwd);

  delay(100);

}
