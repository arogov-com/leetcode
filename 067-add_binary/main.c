#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* addBinary(char* a, char* b) {
    int a_len = 0;
    while(*(a + a_len)) {
        ++a_len;
    }

    int b_len = 0;
    while(*(b + b_len)) {
        ++b_len;
    }

    int r_index = a_len > b_len ? a_len : b_len;

    char *result = malloc(r_index + 1 + 1);
    result[r_index + 1] = '\x0';
    char carry = 0;
    while(a_len || b_len) {
        char s = (a_len ? a[a_len - 1] : '0') + (b_len ? b[b_len - 1] : '0');
        switch(s) {
            case '0' + '0':
                result[r_index] = '0' + carry;
                carry = 0;
                break;
            case '0' + '1':
                result[r_index] = '1' - carry;
                break;
            case '1' + '1':
                result[r_index] = '0' + carry;
                carry = 1;
                break;
        }
        --r_index;
        a_len = a_len > 1 ? --a_len : 0;
        b_len = b_len > 1 ? --b_len : 0;
    }

    result[r_index] = '0' + carry;

    if(result[r_index] == '0') {
        while(result[r_index]) {
            result[r_index] = result[r_index + 1];
            ++r_index;
        }
    }

    return result;
}


int main(int argc, char const *argv[]) {
    char *r;
    // r = addBinary("1010", "110");
    r = addBinary("1", "10");
    printf("%s\n", r);
    return 0;
}
