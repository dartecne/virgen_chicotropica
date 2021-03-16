#ifndef CURVE_H
#define CURVE_H

#define NUM_MAX_POINTS  16

class Curve {
public:
  Curve();
  ~Curve();

  int N; /* number of points */
  int p[NUM_MAX_POINTS];  /* points defined by the user */
  int t[NUM_MAX_POINTS];
  
  int p_max;
  int p_min;
  
  int get_pos(long time, long & pos);   /* return position depending on time */
  void load_points( int N, int p[], int t[] );
  
};


#endif

