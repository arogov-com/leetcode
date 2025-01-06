#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char* intToRoman(int num) {
    char *ones = "IXCM";
    char *fives = "VLD";
    char *decs = "XCM";

    char *result = malloc(16);
    char dec = 0;
    char pos = 0;

    while(num) {
        char d = num % 10;
        num /= 10;

        switch(d) {
            case 0:
                --pos;
                break;
            case 1:
                result[pos] = ones[dec];
                break;
            case 2:
                result[pos] = ones[dec];
                result[++pos] = ones[dec];
                break;
            case 3:
                result[pos] = ones[dec];
                result[++pos] = ones[dec];
                result[++pos] = ones[dec];
                break;
            case 4:
                result[pos] = fives[dec];
                result[++pos] = ones[dec];
                break;
            case 5:
                result[pos] = fives[dec];
                break;
            case 6:
                result[pos] = ones[dec];
                result[++pos] = fives[dec];
                break;
            case 7:
                result[pos] = ones[dec];
                result[++pos] = ones[dec];
                result[++pos] = fives[dec];
                break;
            case 8:
                result[pos] = ones[dec];
                result[++pos] = ones[dec];
                result[++pos] = ones[dec];
                result[++pos] = fives[dec];
                break;
            case 9:
                result[pos] = decs[dec];
                result[++pos] = ones[dec];
                break;
        }
        ++pos;
        ++dec;
    }

    result[pos] = 0;
    --pos;
    dec = 0;
    while(pos > dec) {
        char tmp = result[dec];
        result[dec] = result[pos];
        result[pos] = tmp;
        --pos;
        ++dec;
    }

    return result;
}

int main(int argc, char const *argv[]) {
    // int n = 3749; char *r = "MMMDCCXLIX";
    // int n = 1994; char *r = "MCMXCIV";
    // int n = 58; char *r = "LVIII";
    // int n = 103; char *r = "CIII";
    int n = 6; char *r = "VI";
    int n = 3888; char *r = "MMMDCCCLXXXVIII";

    char *result = intToRoman(n);
    printf("%s\n%s\n%d", r, result);

    free(result);
    return 0;
}
