#include <stdio.h>
#include <stdbool.h>

// An integer number followed by an optional exponent.
//   An integer number is defined with an optional sign '-' or '+' followed by digits  [+-][0-9]*[eE][+-][0-9]*
// A decimal number followed by an optional exponent.
//   A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:
//     Digits followed by a dot '.'  [0-9]*\.
//     Digits followed by a dot '.' followed by digits [0-9]*\.[0-9]*
//     A dot '.' followed by digits  \.[0-9]*
// An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.  [eE][+-][0-9]*
// The digits are defined as one or more digits.

bool isNumber(char* s) {
    enum STATE {
        START,
        START_SIGN,
        START_NUM,
        START_DOT,
        AFTER_DOT,
        AFTER_DOT_CONT,
        EXPONENT,
        EXPONENT1,
        EXPONENT_SIGN,
    } state = START;

    do {
        switch(state) {
            case START:
                if(*s == '+' || *s == '-') {
                    state = START_SIGN;
                    break;
                }
                // Fall through
            case START_SIGN:
                if(*s >= '0' && *s <= '9') {
                    state = START_NUM;
                }
                else if(*s == '.') {
                    state = START_DOT;
                }
                else {
                    return false;
                }
                break;
            case START_NUM:
                if(*s >= '0' && *s <= '9') {
                    break;
                }
                else if(*s == '.') {
                    state = AFTER_DOT_CONT;
                }
                else if(*s == 'e' || *s == 'E') {
                    state = EXPONENT;
                }
                else if(*s == '\x0') {
                    return true;
                }
                else {
                    return false;
                }
                break;
            case START_DOT:
                if(*s >= '0' && *s <= '9') {
                    state = AFTER_DOT_CONT;
                    break;
                }
                return false;
            case AFTER_DOT:
                if(*s >= '0' && *s <= '9') {
                    state = AFTER_DOT_CONT;
                    break;
                }
                else if(*s == 'e' || *s == 'E') {
                    state = EXPONENT;
                }
                else {
                    return false;
                }
                break;
            case AFTER_DOT_CONT:
                if(*s >= '0' && *s <= '9') {
                    break;
                }
                else if(*s == 'e' || *s == 'E') {
                    state = EXPONENT;
                }
                else if(*s == '\x0') {
                    return true;
                }
                else {
                    return false;
                }
                break;
            case EXPONENT:
                if(*s == '+' || *s == '-') {
                    state = EXPONENT_SIGN;
                    break;
                }
                // Fall through
            case EXPONENT_SIGN:
                if(*s >= '0' && *s <= '9') {
                    state = EXPONENT1;
                }
                else {
                    return false;
                }
                break;
            case EXPONENT1:
                if(*s >= '0' && *s <= '9') {
                    break;
                }
                else if(*s == '\x0') {
                    return true;
                }
                return false;
            default:
                return false;
        }
    }while(*(s++));

    return true;
}

int main(int argc, char const *argv[]) {
    // char *s[] = {"-.7e+0435", "3.", "46.e3", "2e0", "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789",
    //              "1", "123", "+1", "-213", "-12e23"};
    char *s[] = {"+.", "+", ".", "4e+", "3.5e+3.5e+3.5", "-inf", ".e1", "abc",  "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", "+12e+4-3", "12e-4e3"};
    for(int i = 0; i != sizeof(s) / sizeof(void*); ++i) {
        bool res = isNumber(s[i]);
        printf("%d: %s\n", res, s[i]);
    }
    return 0;
}
