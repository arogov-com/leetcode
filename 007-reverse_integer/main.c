#include <stdio.h>
#include <stdint.h>

int reverse(int x) {
    #define    NUM1    214748364
    #define    NUM2    -8
    #define    NUM3    7

    int32_t result = 0;

    while(x) {
        if(result >= NUM1 || result <= -NUM1) {
            if(result == -NUM1 && x <= NUM2) {
                return 0;
            }
            else if(result < -NUM1) {
                return 0;
            }
            if(result == NUM1 && x >= NUM3) {
                return 0;
            }
            else if(result > NUM1) {
                return 0;
            }
        }
        result *= 10;
        result += x % 10;
        x /= 10;
    }

    return result;
}

int main(int argc, char const *argv[]) {
    // for(int i = 0; i >= -128; --i) {
    //     printf("%d: %d\n", i, reverse(i));
    // }
    for(int i = 0; i <= 128; ++i) {
        printf("%d: %d\n", i, reverse(i));
    }

    // printf("%d\n", reverse(-102));
    // printf("%d\n", reverse(-121));
    return 0;
}
