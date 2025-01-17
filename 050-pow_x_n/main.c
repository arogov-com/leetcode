#include <stdio.h>
#include <math.h>


double myPow(double x, int n) {
    long double result = 1;
    long long absn = n;
    absn = absn >= 0 ? absn : -absn;

    while(absn > 0) {
        if (absn & 1 == 1) {
            result = result * x;
        }
        x *= x;
        absn >>= 1;
    }

    return n >= 0 ? result : 1 / result;
}


int main(int argc, const char *argv[]) {
    // double result = myPow(0.00001, 2147483647);
    // double result = pow(0.00001, 2147483647);
    double result = power(2, -4);

    printf("%g\n", result);

    return 0;
}
