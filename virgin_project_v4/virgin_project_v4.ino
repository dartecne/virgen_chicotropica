/**
 * v4
 * Includes MIDI input as a geture program
 * It also includes some simple gestures
 * 
 */

#include <Servo.h>
#include "config.h"

byte incomingByte;
byte note;
byte velocity;
int action=1; //0 =note off ; 1=note on ; 2= nada

Servo arm_right;
Servo arm_left;
Servo eyes;

//setup: declaring iputs and outputs and begin serial 
void setup() {

 //start serial with midi baudrate 31250 or 38400 for debugging
 Serial.begin(31250);        
 init_dof();
 blink( EYE_LEFT_PIN, 500 );
 blink( EYE_RIGHT_PIN, 500 );
 blink( LEG_LEFT_PIN, 500 );
 blink( LEG_RIGHT_PIN, 500 );
}

//loop: wait for serial data, and interpret the message 
void loop () {
 if (Serial.available() > 0) {
   // read the incoming byte:
   incomingByte = Serial.read();

   // wait for as status-byte, channel 1, note on or off
   if (incomingByte== 144){ // note on message starting starting
     action=1;
   }else if (incomingByte== 128){ // note off message starting
     action=0;
   }else if (incomingByte== 208){ // aftertouch message starting
      //not implemented yet
   }else if (incomingByte== 160){ // polypressure message starting
      //not implemented yet
   }else if ( (action==0)&&(note==0) ){ // if we received a "note off", we wait for which note (databyte)
     note=incomingByte;
     playNote(note, 0);
     note=0;
     velocity=0;
     action=2;
   }else if ( (action==1)&&(note==0) ){ // if we received a "note on", we wait for the note (databyte)
     note=incomingByte;
   }else if ( (action==1)&&(note!=0) ){ // ...and then the velocity
     velocity=incomingByte;
     playNote(note, velocity);
     note=0;
     velocity=0;
     action=0;
   }else{
     //nada
   }
 }
}

void blink( int pin, int t ){
 digitalWrite( pin, HIGH );
 delay( t );
 digitalWrite( pin, LOW );
 delay( t );
}


void playNote(byte note, byte velocity){
 int value=LOW;
 if (velocity >10){
     value=HIGH;
 }else{
  value=LOW; 
 }

//since we don't want to "play" all notes we wait for a note between 36 & 44
//if(note>=36 && note<44){
//  byte myPin=note-34; // to get a pinnumber between 2 and 9
  byte myPin=13; // to get a pinnumber between 2 and 9
  digitalWrite(myPin, value);
//} 

}

void init_dof(){
  /* arms */
  arm_right.attach( ARM_RIGHT_PIN );
  arm_left.attach( ARM_LEFT_PIN );
  arm_right.write( 90 );
  arm_left.write( 90 );
  delay( 500 );
  
  /* eyes */
  eyes.attach( EYES_PIN );
  eyes.write( EYES_CLOSE );
  delay( 500 );
  
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
  
  delay(500);

  analogWrite( HEART_PIN, 0 );
  digitalWrite( LEG_LEFT_PIN, LOW );
  digitalWrite( LEG_RIGHT_PIN, LOW );
  analogWrite( EYE_RIGHT_PIN, 0 );
  analogWrite( EYE_LEFT_PIN, 0 );
  eyes.write( EYES_OPEN );

}


