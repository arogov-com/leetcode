#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    unsigned short left = 0;

    while(s[left]) {
        unsigned short l = left, r = left + 1;

        while(l < r) {
            if(s[l] != s[r]) {
                break;
            }
            ++l;
            --r;
        }
        printf("sd\n");
    }

}

int main(int argc, char const *argv[]) {
    char *s = "babad";
    // char *s = "skdfj12344321bknrtabad";

    char *res = longestPalindrome(s);
    printf("%s %s\n", s, res);
    free(res);
    return 0;
}

