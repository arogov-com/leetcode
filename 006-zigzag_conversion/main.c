#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* convert(char* s, int numRows) {
    int len = strlen(s);
    char *result = malloc(len + 1);
    result[len] = '\x0';
    char *ptr = result;

    int skip = (numRows - 2) * 2 + 1;
    int low = skip;
    int high = -1;

    int row = 0;
    while(low >= -1) {
        int t = 0;
        int i = row;

        while(i < len) {
            *(ptr++) = s[i];

            if(t++ & 1 && high != -1) {
                i += high + 1;
            }
            else if(high == -1 && low == -1) {
                i += 1;
            }
            else if(low == -1) {
                i += high + 1;
            }
            else {
                i += low + 1;
            }
        }

        low -= 2;
        high += 2;
        ++row;
    }

    return result;
}


int main(int argc, char const *argv[]) {
    char s[] = "PAYPALISHIRING"; int numRows = 5;
    // char s[] = "PAYPALISHIRING"; int numRows = 4;
    // char s[] = "PAYPALISHIRING"; int numRows = 3;
    // char s[] = "ABC"; int numRows = 2;
    // char s[] = "ABC"; int numRows = 1;
    char *r = convert(s, numRows);
    printf("%s\n", r);
    return 0;
}
