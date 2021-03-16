#include <MIDI.h>
#include <Servo.h>
#include "config.h"


MIDI_CREATE_DEFAULT_INSTANCE();

Servo arm_right;
Servo arm_left;
Servo eyes;

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
	int v;
    // Do whatever you want when a note is pressed.

    // Try to keep your callbacks short (no delays ect)
    // otherwise it would slow down the loop() and have a bad impact
    // on real-time performance.
    switch( pitch ) {
      case C4 : // LEFT_EYE
		v = map( velocity, 0, 127, 0, 255 );
        analogWrite( EYE_LEFT_PIN, v );
        break;
      case D4 : // RIGHT_EYE
		  v = map(velocity, 0, 127, 0, 255);
		  analogWrite(EYE_RIGHT_PIN, v);
		  break;
      case E4 : // LEFT_ARM
		  
		  break;
      case F4 : // RIGHT_ARM
        digitalWrite( LEG_LEFT_PIN, 1000 );
        break;
      case G4 : // LEFT_LEG
        digitalWrite( LEG_LEFT_PIN, 1000 );
        break;
      case A4 : // RIGHT_LEG
        digitalWrite( LEG_LEFT_PIN, 1000 );
        break;
      case B4 : // HEART
        digitalWrite( LEG_LEFT_PIN, 1000 );
        break;
    }
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
    // Do something when the note is released.
    // Note that NoteOn messages with 0 velocity are interpreted as NoteOffs.
    blink( LEG_RIGHT_PIN, 1000 );
}

// -----------------------------------------------------------------------------

void setup()
{
	config_dof();
	test_movement();

    // Connect the handleNoteOn function to the library,
    // so it is called upon reception of a NoteOn.
    MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function

    // Do the same for NoteOffs
    MIDI.setHandleNoteOff(handleNoteOff);

    // Initiate MIDI communications, listen to all channels
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
    // Call MIDI.read the fastest you can for real-time performance.
    MIDI.read();
//    blink( EYE_RIGHT_PIN, 500 );
    // There is no need to check if there are messages incoming
    // if they are bound to a Callback function.
    // The attached method will be called automatically
    // when the corresponding message has been received.
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

void test_movement() {
	sweep( EYE_LEFT_PIN, 1000 );
	sweep( EYE_RIGHT_PIN, 1000);
	sweep( EYE_RIGHT_PIN, 1000);
	sweep( LEG_LEFT_PIN, 1000 );
	sweep( LEG_RIGHT_PIN, 1000 );
	arm_left.write( ARM_LEFT_UP );
	arm_right.write(ARM_RIGHT_UP);
	delay( 1000 );
	arm_left.write(ARM_LEFT_DOWN);
	arm_right.write(ARM_RIGHT_DOWN);
	delay(1000);
	int p = abs(ARM_LEFT_UP - ARM_LEFT_DOWN) / 2;
	arm_left.write(p);
	p = abs(ARM_RIGHT_UP - ARM_RIGHT_DOWN) / 2;
	arm_right.write(p);
	delay(1000);
}

void sweep(int pin, int t) {
	int T = 255;
	for (int i = 0; i < 255; i++) {
		int v = 255 * sin( 2 * PI * i / T );
		analogWrite( pin, v );
		delay( t / T );
	}
}

void blink( int pin, int t ){
 digitalWrite( pin, HIGH );
 delay( t );
 digitalWrite( pin, LOW );
 delay( t );
}

