#include "integrand.h"

volatile double sink;   // definisjon (deklarert extern i integrand.h)

// smoth function. Integrand of this from 0-pi = 2
double f(double x) {
    return sin(x);
}

// hevy function
double g(double x) {
    return 2.0 * x * cos(x * x);             // selve funksjonsverdien
}