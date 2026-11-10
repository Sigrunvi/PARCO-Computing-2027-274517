#pragma once
#include <math.h>

extern volatile double sink;  // hindrer at kompilatoren fjerner dummy-arbeidet
static const double exact_smooth = 2.0; // eksakt integral av f fra 0 til pi
static const double exact_heavy = -0.50636564110975879; // sin(100)

// smooth function
double f(double x); 

// heavy function
double g(double x);