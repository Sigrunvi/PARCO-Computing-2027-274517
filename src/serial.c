#include <math.h>
#include <stdio.h>
#include "integrand.h"

double trapezoid(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

double simpson(double (*f)(double), double a, double b, int n) {
    if (n % 2 != 0) {
        n++; // Simpson's rule requires an even number of intervals
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        sum += 4 * f(a + i * h);
    }
    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * f(a + i * h);
    }
    return sum * h / 3.0;
}

int main() {
    double a = 0.0;
    double b = M_PI;
    double c = 10.0;
    int n = 1000; // Number of intervals

    double result_trapezoid_smooth = trapezoid(f, a, b, n);
    double result_simpson_smooth = simpson(f, a, b, n);

    double result_trapezoid_heavy = trapezoid(g, a, c, n);
    double result_simpson_heavy = simpson(g, a, c, n);

    printf("Trapezoid Rule Result for smooth function: %.10f\n", result_trapezoid_smooth);
    printf("Simpson's Rule Result for smooth function: %.10f\n", result_simpson_smooth);
    printf("Exact Result for smooth function: %.10f\n", exact_smooth);

    printf("\n");

    printf("Trapezoid Rule Result for heavy function: %.10f\n", result_trapezoid_heavy);
    printf("Simpson's Rule Result for heavy function: %.10f\n", result_simpson_heavy);
    printf("Exact Result for heavy function: %.10f\n", exact_heavy);
    return 0;
}