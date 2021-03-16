#include "dof.h"

Dof::Dof( int pin ) {
  this->attach( pin );
  this->write( 90 );;
  this->write( 120 );
  this->write( 90 );
}
//Dof::~Dof() {}

long Dof::move_to_pos( long time ) {
  long pos;
  this->get_pos( time, pos );
  this->write( pos );
  return pos;
}

void Dof::set_pos( int pos ) {
  this->write( pos );
}
