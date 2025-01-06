#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool isMatch(char* s, char* p) {
    int pattern_quant;
    while(*p && *s) {
        char pattern_next = '\x0';
        char pattern_char = *(p++);

        pattern_quant = 1;
        if(*p == '*') {
            pattern_quant = -1;
            pattern_next = *(++p);
        }

        while(*s && pattern_quant) {
            if(*s != pattern_char && pattern_next == '.') {
                break;
            }
            if(*s != pattern_char && *s == pattern_next) {
                break;
            }

            if(*s == pattern_char || pattern_char == '.') {
                ++s;
                --pattern_quant;
                continue;
            }
            return false;
        }
    }

    if(*(s - 1) == *p && pattern_quant < 0) {
        ++p;
    }
    return !*s && !*p ? true : false;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", isMatch("aaa", "ab*a*c*a") == true);
    // printf("%d\n", isMatch("aaa", "aaaa") == false);
    // printf("%d\n", isMatch("aab", "a*b") == true);
    // printf("%d\n", isMatch("aaa", "a*a") == true);
    // printf("%d\n", isMatch("aab", "a*b") == true);
    // printf("%d\n", isMatch("ab", ".*c") == false);
    // printf("%d\n", isMatch("mississippi", "mis*is*ip*.") == true);
    // printf("%d\n", isMatch("asdjqqqknv", ".*qqq.*") == true);
    // printf("%d\n", isMatch("aa", "a") == false);
    // printf("%d\n", isMatch("aa", "a*") == true);
    // printf("%d\n", isMatch("ab", ".*") == true);
    // printf("%d\n", isMatch("aab", "c*a*b*") == true);
    return 0;
}
