#include <stdio.h>
#include <stdint.h>

int32_t myAtoi(char* s) {
    #define    MIN    (1U << (sizeof(uint32_t) * 8 - 1))

    int i = 0;

    while(s[i] == ' ') {
        ++i;
    }

    int sign = 1;
    if(s[i] == '-') {
        sign = -1;
        ++i;
    }
    else if(s[i] == '+') {
        sign = 1;
        ++i;
    }

    uint64_t num = 0;

    for(; s[i] >= '0' && s[i] <= '9'; ++i) {
        num *= 10;
        num += (s[i] - '0');
        if(num >= MIN) {
            if(sign == 1) {
                return MIN - 1;
            }
            else {
                return MIN;
            }
        }
    }

    return num * sign;
}

int main(int argc, char const *argv[]) {
    // int n = myAtoi("91283472332");
    int n = myAtoi("125"); printf("%d\n", n);
    n = myAtoi("126"); printf("%d\n", n);
    n = myAtoi("127"); printf("%d\n", n);
    n = myAtoi("128"); printf("%d\n", n);
    n = myAtoi("129"); printf("%d\n", n);

    n = myAtoi("-126"); printf("%d\n", n);
    n = myAtoi("-127"); printf("%d\n", n);
    n = myAtoi("-128"); printf("%d\n", n);
    n = myAtoi("-129"); printf("%d\n", n);
    return 0;
}
