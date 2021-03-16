#ifndef DOF_H
#define DOF_H

#include <Servo.h>
#include "Curve.h"

class Dof: public Servo, public Curve {
  public:
  Dof( int pin );
//  ~Dof();

  long move_to_pos( long time );
  void set_pos( int pos );
//  void set_pin( int pin );
  int pin;
//  int p_max;
//  int p_min;
};

#endif
