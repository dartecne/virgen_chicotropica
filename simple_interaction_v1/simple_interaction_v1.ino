/**
 * simple_interaction_v1
 * Movimientos sencillos reactivos a un telemetro IR colocado en la espalda
 */

#include <Servo.h>
#include "config.h"

Servo arm_right;
Servo arm_left;
Servo eyes;

void setup() {
  config_dof();
//  blink_eyes(1000);
  digitalWrite( EYES_PIN, 0 );
  delay(3000);
//  test_movement();
  Serial.begin( 9600 );
  randomSeed( analogRead( A1 ) );
}
int d = 0;
int i = 0;
int t = 0;
int T = T_MAX;
int left_arm = 0, right_arm = 0;
int legs = HIGH;
int pitch = 440;

void loop() {
  d = analogRead( A0 );
//  Serial.println( d );
  int r = random( 1, 60 ); // cada 30 loops (3 segs) probabilidad de parpadeo
  if( r == 12 ) blink_eyes( 200 );
  if( d > IR_MIN ) {
    T = map( d, IR_MIN, IR_MAX, T_MIN, T_MAX );
    left_arm = map( d, IR_MIN, IR_MAX, ARM_LEFT_DOWN, ARM_LEFT_UP );
    right_arm = map( d, IR_MIN, IR_MAX, ARM_RIGHT_UP, ARM_RIGHT_DOWN );
    pitch = map( d, IR_MIN, IR_MAX, PITCH_MIN, PITCH_MAX);
    tone( SPEAKER, pitch );
  } else {
    T = T_MAX;
    left_arm = ARM_LEFT_DOWN;
    right_arm = ARM_RIGHT_DOWN;
    pitch = map( d, IR_MIN, IR_MAX, PITCH_MIN, 2*PITCH_MIN);
    noTone( SPEAKER );
  }
  int N = T / TAU;
  int heart_beat = 255 * (1 + sin( 2 * PI * i / N ));
  i++;
  if( i > N ) i = 0;
  
  int eyes_light = 255 * (1 + sin( 2 * PI * i * TAU / ( 2 * T_MAX )  ));

  analogWrite( EYE_LEFT_PIN, eyes_light );
  analogWrite( EYE_RIGHT_PIN, eyes_light );
  
  analogWrite( HEART_PIN, heart_beat );
//  analogWrite( HEART_PIN, LOW );
  digitalWrite( LEG_LEFT_PIN, HIGH );
  digitalWrite( LEG_RIGHT_PIN, HIGH );

  arm_left.write( left_arm );
  arm_right.write( right_arm );

  delay( TAU );
}

void blink_eyes( int d ) {
  digitalWrite( EYES_PIN, EYES_OPEN );
  delay(d);
  digitalWrite( EYES_PIN, EYES_CLOSE );
}

void test_movement() {
  eyes.write( EYES_CLOSE );
  blink( LEG_LEFT_PIN, 1000 );
  blink( LEG_RIGHT_PIN, 1000 );
  digitalWrite( LEG_LEFT_PIN, HIGH );
  digitalWrite( LEG_RIGHT_PIN, HIGH );
  sweep( HEART_PIN, 2000  );
  
  arm_left.write( ARM_LEFT_UP );
  arm_right.write(ARM_RIGHT_UP);
  eyes.write( EYES_OPEN );
  sweep( EYE_LEFT_PIN, 1000 );
  sweep( EYE_RIGHT_PIN, 1000);
  delay( 1000 );
/**/  arm_left.write(ARM_LEFT_DOWN);
  arm_right.write(ARM_RIGHT_DOWN);
  delay(1000);
  int p = abs(ARM_LEFT_UP - ARM_LEFT_DOWN) / 2;
  arm_left.write(p);
  p = abs(ARM_RIGHT_UP - ARM_RIGHT_DOWN) / 2;
  arm_right.write(p);
  delay(1000);
 /* */
}

void blink( int pin, int t ){
 digitalWrite( pin, HIGH );
 delay( t );
 digitalWrite( pin, LOW );
 delay( t );
}

void sweep(int pin, int t) {
  int T = 255;
  for (int i = 0; i < 255; i++) {
    int v = 255 * sin( 2 * PI * i / T );
    analogWrite( pin, v );
    delay( t / T );
  }
}

void config_dof() {
  arm_right.attach(ARM_RIGHT_PIN);
  arm_left.attach(ARM_LEFT_PIN);
  eyes.attach(EYES_PIN);
  pinMode(HEART_PIN, OUTPUT);
  pinMode(LEG_LEFT_PIN, OUTPUT);
  pinMode(LEG_RIGHT_PIN, OUTPUT);
  pinMode(EYE_LEFT_PIN, OUTPUT);
  pinMode(EYE_RIGHT_PIN, OUTPUT);
}

int my_square(double f) {
  if(sin(f) > 0.5) return HIGH;
  else return LOW;
}

