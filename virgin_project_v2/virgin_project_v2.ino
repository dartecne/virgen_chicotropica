#include <Servo.h>

#include "config.h"
#include "dof.h"

//#define DEBUG
#define NUM_GESTURES 4

Servo arm_right;
Servo arm_left;
Servo eyes;

void init_dof(){
  /* arms */
  arm_right.attach( ARM_RIGHT_PIN );
  arm_left.attach( ARM_LEFT_PIN );
  arm_right.write( 90 );
  arm_left.write( 90 );
  
  /* eyes */
  eyes.attach( EYES_PIN );
  eyes.write( EYES_CLOSE );
  
  /*LEDS*/
  pinMode( HEART_PIN, OUTPUT );
  pinMode( LEG_LEFT_PIN, OUTPUT );
  pinMode( LEG_RIGHT_PIN, OUTPUT );
  pinMode( EYE_LEFT_PIN, OUTPUT );
  pinMode( EYE_RIGHT_PIN, OUTPUT );
  
  analogWrite( HEART_PIN, 127 );
  digitalWrite( LEG_LEFT_PIN, HIGH );
  digitalWrite( LEG_RIGHT_PIN, HIGH );
  analogWrite( EYE_RIGHT_PIN, 127 );
  analogWrite( EYE_LEFT_PIN, 127 );
  
  delay(1000);

  analogWrite( HEART_PIN, 0 );
  digitalWrite( LEG_LEFT_PIN, LOW );
  digitalWrite( LEG_RIGHT_PIN, LOW );
  analogWrite( EYE_RIGHT_PIN, 0 );
  analogWrite( EYE_LEFT_PIN, 0 );
  eyes.write( EYES_OPEN );

}

int check_status() {
 
 return 0;
}
Curve curve[NUM_DOF];


void exec_gesture( int duration ) {
  long time = 0;
  long pos = 0;
  for( int i = 0; duration > TAU * i; i++ ) {
    for( int j = 0; j < NUM_DOF; j++ ) {
      curve[j].get_pos( time, pos );
      switch(j) {
        case LEG_LEFT_ID :
#ifdef DEBUG
          Serial.println( "    LEG_LEFT_ID" );
#endif      
          digitalWrite( LEG_LEFT_PIN, pos );  
          break;
        case LEG_RIGHT_ID :
#ifdef DEBUG
          Serial.println( "    LEG_RIGHT_ID" );
#endif      
          digitalWrite( LEG_RIGHT_PIN, pos );  
          break;
        case ARM_LEFT_ID :
#ifdef DEBUG
          Serial.println( "    ARM_LEFT_ID" );
#endif      
          constrain(pos, ARM_LEFT_UP, ARM_LEFT_DOWN );
          arm_left.write( pos );
          break;
        case ARM_RIGHT_ID :
#ifdef DEBUG
          Serial.println( "    ARM_RIGHT_ID" );
#endif      
          constrain(pos, ARM_RIGHT_DOWN, ARM_RIGHT_UP );
          arm_right.write( pos );  
          break;
        case EYES_ID :
#ifdef DEBUG
          Serial.println( "    EYES_ID" );
#endif      
          constrain(pos, EYES_OPEN, EYES_CLOSE );
          eyes.write( pos );  
          break;
        case EYE_LEFT_ID :
#ifdef DEBUG
          Serial.println( "    EYE_LEFT_ID" );
#endif      
          constrain( pos, 0, 255 );
          analogWrite( EYE_LEFT_PIN, pos );
          break;
        case EYE_RIGHT_ID :
#ifdef DEBUG
          Serial.println( "    EYE_RIGHT_ID" );
#endif      
          constrain( pos, 0, 255 );
          analogWrite( EYE_RIGHT_PIN, pos );
          break;
        case HEART_ID :
#ifdef DEBUG
          Serial.println( "    HEART_ID" );
#endif      
          constrain( pos, 0, 255 );
          analogWrite( HEART_PIN, pos );
          break;
      } // case
      if( check_status() < 0 ) return;

/**/
#ifdef DEBUG
      Serial.print( "t = " ); Serial.print( time );
      Serial.print( "  p = " ); Serial.println( pos );
#endif      
/**/
    } // for all DOF
    time += TAU;
    delay( TAU );
  }   //  in a DOF
}

void do_all_range() {
  curve[LEG_LEFT_ID].load_points( 2, p_digital_led_all_range, t_digital_led_all_range );
  curve[LEG_RIGHT_ID].load_points( 2, p_digital_led_all_range, t_digital_led_all_range );
  curve[ARM_LEFT_ID].load_points( 2, p_arm_left_all_range, t_servo_all_range );
  curve[ARM_RIGHT_ID].load_points( 2, p_arm_right_all_range, t_servo_all_range );
  curve[EYES_ID].load_points( 2, p_eyes_all_range, t_eyes_all_range );
  curve[EYE_LEFT_ID].load_points( 2, p_analog_led_all_range, t_analog_led_all_range );
  curve[EYE_RIGHT_ID].load_points( 2, p_analog_led_all_range, t_analog_led_all_range );
  curve[HEART_ID].load_points( 2, p_analog_led_all_range, t_analog_led_all_range );
  exec_gesture( 2000 );
}
/*
  curve[LEG_LEFT_ID].load_points(  );
  curve[LEG_RIGHT_ID].load_points( );
  curve[ARM_LEFT_ID].load_points( );
  curve[ARM_RIGHT_ID].load_points( );
  curve[EYES_ID].load_points( );
  curve[EYE_LEFT_ID].load_points( );
  curve[EYE_RIGHT_ID].load_points( );
  curve[HEART_ID].load_points( );
*/
void do_sexy() {
  curve[ARM_LEFT_ID].load_points(2, p_arm_left_up, t_arm_up);
  curve[ARM_RIGHT_ID].load_points(2, p_arm_right_up, t_arm_up);
  curve[EYES_ID].load_points(6, p_eyes_double_blink, t_eyes_double_blink);  
  curve[EYE_LEFT_ID].load_points(2, p_eye_led_on, t_arm_up);
  curve[EYE_RIGHT_ID].load_points(2, p_eye_led_on, t_arm_up);
  curve[LEG_LEFT_ID].load_points( 5, p_leg_blink_at_end, t_leg_blink_at_end );
  curve[LEG_RIGHT_ID].load_points( 5, p_leg_blink_at_end, t_leg_blink_at_end );
  curve[HEART_ID].load_points(8, p_heart_pulse, t_heart_pulse );
  exec_gesture( 4000 );
  curve[ARM_LEFT_ID].load_points(2, p_arm_left_down, t_arm_up);
  curve[ARM_RIGHT_ID].load_points(2, p_arm_right_down, t_arm_up);
  curve[LEG_LEFT_ID].load_points( 9, p_leg_blink_at_end, t_leg_blink_at_begin );
  curve[LEG_RIGHT_ID].load_points( 9, p_leg_blink_at_end, t_leg_blink_at_begin );
  exec_gesture( 4000 );
}


void do_sexy_2() {
  curve[LEG_LEFT_ID].load_points( 16, p_leg_blink_at_end_long, t_leg_blink_at_end_long );
  curve[LEG_RIGHT_ID].load_points(16, p_leg_blink_at_end_contra_long, t_leg_blink_at_end_long );
  curve[ARM_LEFT_ID].load_points( 4, p_arm_left_vibra, t_arm_up );
  curve[ARM_RIGHT_ID].load_points( 4, p_arm_right_vibra, t_arm_up );
  curve[EYES_ID].load_points(6, p_eyes_double_blink, t_eyes_double_blink );
  curve[EYE_LEFT_ID].load_points( 4, p_eye_led_vibra_1, t_eye_led_vibra);
  curve[EYE_RIGHT_ID].load_points( 4, p_eye_led_vibra_2, t_eye_led_vibra);
  curve[HEART_ID].load_points( 8, p_heart_pulse, t_heart_pulse);
  exec_gesture( 4000 );
}

void do_idle() {
  curve[ARM_LEFT_ID].load_points(2, p_arm_left_up_down, t_arm_up);
  curve[ARM_RIGHT_ID].load_points(2, p_arm_right_down_up, t_arm_up);
  curve[EYES_ID].load_points(6, p_eyes_double_blink, t_eyes_double_blink);  
  curve[EYE_LEFT_ID].load_points(8, p_heart_pulse, t_heart_pulse);
  curve[EYE_RIGHT_ID].load_points(8, p_heart_pulse, t_heart_pulse);
  curve[LEG_LEFT_ID].load_points( 9, p_leg_blink_at_end, t_leg_blink_at_begin_fast );
  curve[LEG_RIGHT_ID].load_points( 9, p_leg_blink_at_end, t_leg_blink_at_begin_fast );
  curve[HEART_ID].load_points(8, p_heart_pulse, t_heart_pulse );
  exec_gesture( 4000 );
  
}

void setup() {
  Serial.begin(9600);
  Serial.println( "**** setup ****" );
  delay( 1000 ); 
  
  randomSeed(analogRead(0));
  Serial.println( "  init_dof" );
  init_dof();
  delay( 1000 );
  
  Serial.println( "  do_all_range" );
  do_all_range();
  do_sexy();
  do_idle();
  do_sexy_2();
  init_dof();
}

void loop() { 
  long randNumber = random( NUM_GESTURES );
  Serial.println(randNumber);
  switch( randNumber ) {
    case 0:
      do_sexy();
      break;  
    case 1:
      do_idle();
      break;  
    case 2:
      do_sexy_2();
      break;  
    case 3:
      do_all_range();
      break;  
  }  
}

