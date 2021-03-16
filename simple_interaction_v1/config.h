#ifndef CONFIG_H
#define CONFIG_H

// Se cambia el pin de left leg al pin8 y se añade speaker al pin13

#define SPEAKER    13
#define LEG_LEFT_PIN    8
#define LEG_RIGHT_PIN  12
#define ARM_LEFT_PIN   11
#define ARM_RIGHT_PIN  10
#define EYES_PIN        9
#define EYE_LEFT_PIN      6
#define EYE_RIGHT_PIN      5
#define HEART_PIN      3
#define GSING_1     7
#define GSING_2    4
#define GSING_3    2

#define IR  A0

#define C4  60
#define D4  62
#define E4  64
#define F4  65
#define G4  67
#define A4  69
#define B4  71

#define EYES_OPEN  10
#define EYES_CLOSE  110

#define ARM_LEFT_DOWN  90
#define ARM_RIGHT_DOWN  90
#define ARM_LEFT_UP  10
#define ARM_RIGHT_UP  170
#define PITCH_MAX 2000
#define PITCH_MIN 100


#define IR_MIN  400
#define IR_MAX  560

#define T_MIN 300 // minimum period of heart beat in ms
#define T_MAX 2000 // maximum period of heart beat in ms

#define TAU  30 // ms, period of loop
#define NUM_DOF  8

#define CONTROL_CHANGE  0xB0
#define CC  CONTROL_CHANGE
#define NOTE_ON  0x90
#define NOTE_OFF  0x80
#define BPM  0xC0


#endif
