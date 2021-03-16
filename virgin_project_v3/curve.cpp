#include "curve.h"

Curve::Curve(){}

Curve::~Curve(){
  this->N = 0;
}

int Curve::get_pos( long time, long &pos ) {
  if( this->N == 0 ) return -1;
  float A, B;
  float p0, p1;
  float t0, t1;
  int i = 0;

  /* get segment from time. Segment is between i-1 and i */
  while( t[i] < time ) {
    i++;
  } 
  
  if( i == 0 ) return -2;
  p0 = float( p[i] );
  p1 = float( p[i-1] );
  t0 = float( t[i] );
  t1 = float( t[i-1] );
  
  A = p1 - p0;
  A = A / (  t1 - t0 );
  B = p0 * t1 - p1 * t0;
  B = B / ( t1 - t0 );
  /*
  A = p[i] - p[i-1];
  A = A / (t[i] - t[i-1]);
  
  B = p[i-1]*t[i] - p[i]*t[i-1];
  B = B / (t[i] - t[i-1]);
  */
  pos = A * float(time) + B;

  return 0;
}

void Curve::load_points( int N, int p[], int t[] ) {
  this->N = N;
  for( int i = 0; i < N; i++ ) {
    this->p[i] = p[i];
    this->t[i] = t[i];
  }
}
