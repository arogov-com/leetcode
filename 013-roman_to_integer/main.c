#include <stdio.h>

int romanToInt(char* s) {
    unsigned short result = 0;
    while(*s) {
        switch(*s) {
            case 'I':
                if(*(s + 1) == 'V' || *(s + 1) == 'X') result -= 1;
                else result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if(*(s + 1) == 'L' || *(s + 1) == 'C') result -= 10;
                else result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if(*(s + 1) == 'D' || *(s + 1) == 'M') result -= 100;
                else result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                break;
        }
        ++s;
    }
    return result;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", romanToInt("LVIII") == 58);
    printf("%d\n", romanToInt("MCMXCIV") == 1994);
    return 0;
}
