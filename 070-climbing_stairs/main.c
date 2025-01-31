#include <stdio.h>


int climbStairs(int n) {
    ++n;
    if(n == 1) {
        return 1;
    }
    int a = 0;
    int b = 1;
    for(int i = 0; i < n; ++i) {
        a = a + b;
        b = a - b;
    }
    return a;
}


int main(int argc, char const *argv[]) {
    for(int i = 0; i < 10; ++i) {
        printf("%i = %i\n", i, climbStairs(i));
    }
    return 0;
}
