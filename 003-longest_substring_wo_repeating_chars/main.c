#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    if(s[0] == '\x0') {
        return 0;
    }
    if(s[1] == '\x0') {
        return 1;
    }

    unsigned int bitmask[8];
    int max = 0;

    for(int i = 0; s[i] != '\x0'; ++i) {
        for(int c = 0; c < 8; bitmask[c++] = 0);
        int len = 1;

        bitmask[s[i] / 32] = 1UL << (s[i] - ((s[i] >> 5) << 5));
        for(int j = i + 1; s[j] != '\x0'; ++j) {
            if((bitmask[s[j] / 32]) & (1 << (s[j] - ((s[j] >> 5) << 5)))) {
                max = len > max ? len : max;
                break;
            }
            else {
                bitmask[s[j] / 32] |= 1 << (s[j] - ((s[j] >> 5) << 5));
                ++len;
            }
            max = len > max ? len : max;
        }
    }

    return max;
}

int main(int argc, char const *argv[]) {
    // char *s = "abcabcbb"; int out = 3;
    // char *s = "bbbbb"; int out = 1;
    // char *s = "pwwkew"; int out = 3;
    char *s = "au"; int out = 2;

    int res = lengthOfLongestSubstring(s);

    printf("%d == %d\n", res, out);
    return 0;
}