#include <SoftwareSerial.h>
#include <Servo.h>
Servo base_servo, shoulder_servo, elbow_servo, wrist_servo, gripper_servo, vertical_wrist_servo;
int base_pos = 90, shoulder_pos = 90, elbow_pos = 14, wrist_pos = 90, gripper_pos = 0, wrist_vertical_pos = 90;

SoftwareSerial SerialBT(8, 7);

void setup() {
  base_servo.attach(3);
  shoulder_servo.attach(5);
  elbow_servo.attach(6);
  wrist_servo.attach(9);
  gripper_servo.attach(10);
  vertical_wrist_servo.attach(11);

  Serial.begin(9600);
  SerialBT.begin(9600);

  base_servo.write(base_pos);
  shoulder_servo.write(shoulder_pos);
  elbow_servo.write(elbow_pos);
  wrist_servo.write(wrist_pos);
  vertical_wrist_servo.write(wrist_vertical_pos);
  gripper_servo.write(gripper_pos);
}

void servo_move(Servo&, bool, int*, int);

void loop() {
  if (SerialBT.available()) {
    //Serial.println(char(SerialBT.read())); //FOR DEBUGGING
    switch (char(SerialBT.read())) {
      case 'r':
        servo_move(base_servo, 0, &base_pos, 15);
        break;
      case 'l':
        servo_move(base_servo, 1, &base_pos, 15);
        break;
      case 'u':
        servo_move(shoulder_servo, 0, &shoulder_pos, 15);
        break;
      case 'd':
        servo_move(shoulder_servo, 1, &shoulder_pos, 15);
        break;
      case 'E':
        servo_move(elbow_servo, 0, &elbow_pos, 15);
        break;
      case 'e':
        servo_move(elbow_servo, 1, &elbow_pos, 15);
        break;
      case 'W':
        servo_move(wrist_servo, 0, &wrist_pos, 15);
        break;
      case 'w':
        servo_move(wrist_servo, 1, &wrist_pos, 15);
        break;
      case 'V':
        servo_move(vertical_wrist_servo, 1, &wrist_vertical_pos, 15);
        break;
      case 'v':
        servo_move(vertical_wrist_servo, 0, &wrist_vertical_pos, 15);
        break;
      case 'G':
        gripper_servo.write(0);
        break;
      case 'g':
        gripper_servo.write(100);
        break;
    }
  }
}