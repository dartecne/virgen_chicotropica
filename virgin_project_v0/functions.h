#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "gestures.h"

void move_left_arm( unsigned int pos);
void move_right_arm( unsigned int pos );

void exec_gesture( gesture_t gesture[NUM_DOF] );

int check_status();

#endif

