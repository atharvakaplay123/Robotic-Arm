void servo_move(Servo &servo, bool direction, int *pos, int delay_time) {
  if (direction) {
    for (int pan_pos = *pos; pan_pos < 180; pan_pos += 1) {
      servo.write(pan_pos);
      *pos = servo.read();
      Serial.println(servo.read());  //FOR DEBUGGING
      if (SerialBT.available() > 0) {
        char BT = SerialBT.read();
        if (BT == 's') {
          break;
        }
      }
      delay(delay_time);
    }
  } else {
    for (int pan_pos = *pos; pan_pos > 0; pan_pos -= 1) {
      servo.write(pan_pos);
      *pos = servo.read();
      Serial.println(servo.read());  //FOR DEBUGGING
      if (SerialBT.available() > 0) {
        char BT = SerialBT.read();
        if (BT == 's') {
          break;
        }
      }
      delay(delay_time);
    }
  }
}
void set_arm_position(int base, int shoulder, int elbow, int wrist, int gripper) {
  base_servo.write(base);
  shoulder_servo.write(shoulder);
  elbow_servo.write(elbow);
  wrist_servo.write(wrist);
  gripper_servo.write(gripper);
}

void set_arm_position(int *value_array) {
  if (value_array == nullptr) {
    return;
  }
  for (int i = 0; i < 5; i++) {
    if (value_array[i] < 0 || value_array[i] > 180) {
      // All servos accept angles between 0 and 180 degrees
      return;
    }
  }
  base_servo.write(value_array[0]);
  shoulder_servo.write(value_array[1]);
  elbow_servo.write(value_array[2]);
  wrist_servo.write(value_array[3]);
  gripper_servo.write(value_array[4]);
}