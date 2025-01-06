#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char *result = malloc(200 * sizeof(char));
    char *tmp = result;

    int pos = 0;
    while(1) {
        char c = strs[0][pos];
        if(c == '\x0') {
            *tmp = '\x0';
            return result;
        }
        for(int i = 1; i < strsSize; ++i) {
            if(strs[i][pos] != c) {
                *tmp = '\x0';
                return result;
            }
        }
        *(tmp++) = c;
        ++pos;
    }
}

int main(int argc, char const *argv[]) {
    // char *strs[] = {"flower","flow","flight"}; int sz = 3;
    // char *strs[] = {""}; int sz = 1;
    char *strs[] = {"a"}; int sz = 1;

    char *result = longestCommonPrefix(strs, sz);

    printf("%s\n", result);
    free(result);
    return 0;
}
