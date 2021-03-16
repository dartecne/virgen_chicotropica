#include <Servo.h>

#include "functions.h"
#include "gestures.h"

extern gesture_t sexy[NUM_DOF];

Servo servos[NUM_DOF];

void init_gestures() {  
  sexy[ARM_LEFT_ID].curve = &rect_up[0];
  sexy[ARM_LEFT_ID].p_init = 80;
  sexy[ARM_LEFT_ID].p_end = 10;
  sexy[ARM_LEFT_ID].tau = TAU;

  sexy[ARM_RIGHT_ID].curve = &rect_up[0];
  sexy[ARM_RIGHT_ID].p_init = 10;
  sexy[ARM_RIGHT_ID].p_end = 80;
  sexy[ARM_RIGHT_ID].tau = TAU;
}

int check_status() {  
  return 0;
}

void exec_gesture( gesture_t gesture[NUM_DOF] ) {
  long pos = 0;
  int temp = 0;
  for( int j = 0; j < NUM_DOF; j++ ) {
    for( int i = 0; i < NUM_MAX_POINTS; i++ ) {  
      pos = gesture[j].curve[i];
      temp = gesture[j].p_end - gesture[j].p_init;
      pos = temp * pos / POS_MAX + gesture[j].p_init;
      Serial.print( "pos = " ); Serial.println( pos );
      servos[j].write( pos );
      delay( gesture[j].tau );
      if( check_status() ) return;
    }
  }
}

/**
    gestures
*/

void setup() {
  Serial.begin(9600);
  Serial.println( "**** setup ****" );
  init_gestures();
  servos[ARM_LEFT_ID].attach( ARM_LEFT_PIN );
  servos[ARM_RIGHT_ID].attach( ARM_RIGHT_PIN );
  servos[ARM_LEFT_ID].write(90);
  servos[ARM_RIGHT_ID].write(90);
  delay(1000);

  exec_gesture( sexy );
}

void loop() { 
}

