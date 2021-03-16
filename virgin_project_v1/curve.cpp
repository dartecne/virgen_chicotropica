#include "curve.h"

Curve::Curve(){}

Curve::~Curve(){
  this->N = 0;
}

int Curve::get_pos( int time, float &pos ) {
  if( this->N == 0 ) return -1;
  float A, B;
  int i = 0;

  /* get segment from time. Segment is between i-1 and i */
  while( t[i] < time ) {
    i++;
  } 
  
  if( i == 0 ) return -2;
  
  A = p[i] - p[i-1];
  A = A / (t[i] - t[i-1]);
  
  B = p[i-1]*t[i] - p[i]*t[i-1];
  B = B / (t[i] - t[i-1]);
  
  pos = A * time + B;
  
  return 0;
}

void Curve::load_points( int N, int p[], int t[] ) {
  this->N = N;
  for( int i = 0; i < N; i++ ) {
    this->p[i] = p[i];
    this->t[i] = t[i];
  }
}
