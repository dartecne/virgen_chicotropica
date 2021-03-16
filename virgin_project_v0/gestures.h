#ifndef GESTURES_H
#define GESTURES_H
/**
* Se definen los gestos 
*/

#define ARM_LEFT_PIN  10
#define ARM_RIGHT_PIN  11

#define ARM_LEFT_ID  0
#define ARM_RIGHT_ID  1

#define NUM_GESTURES  1
#define NUM_DOF  2
#define SEXY_1  0

#define NUM_MAX_POINTS 32
#define POS_MAX  1000

#define TAU  40  /* ms between analog writes */

typedef struct gesture{
  unsigned int * curve;
  unsigned int p_init;
  unsigned int p_end;
  unsigned int tau;
  unsigned int pin;
} gesture_t;

gesture_t  sexy[NUM_DOF];

unsigned int rect_up[NUM_MAX_POINTS] = {
//  0, 66, 132, 198, 264, 330, 396, 462, 528, 660, 726, 792, 858, 924, 990
  0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480, 512, 544, 576,
  608, 640, 672, 704, 736, 768, 800, 832, 864, 896, 926, 960, 992
};

unsigned int rect_down[NUM_MAX_POINTS] = {
//  990, 924, 858, 792, 726, 660, 528, 462, 396, 330, 264, 198, 132, 66, 0
};


#endif
