#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = malloc(sizeof(int) * (digitsSize + 1));

    char carry = 1;

    for(int i = digitsSize; i > 0; --i) {
        result[i] = digits[i - 1] + carry;
        if(result[i] == 10) {
            result[i] = 0;
            carry = 1;
        }
        else {
            carry = 0;
        }
    }
    result[0] = carry;

    if(result[0] == 0) {
        for(int i = 0; i < digitsSize; ++i) {
            result[i] = result[i + 1];
        }
        *returnSize = digitsSize;
    }
    else {
        *returnSize = digitsSize + 1;
    }

    return result;
}


int main(int argc, char const *argv[]) {
    // int a[] = {4, 3, 2, 1};
    // int a[] = {2, 9};
    // int a[] = {9, 9};
    // int a[] = {9, 1, 9};
    int a[] = {1, 2, 3};
    int result_size;
    int *result;
    result = plusOne(a, sizeof(a) / sizeof(int), &result_size);

    for(int i = 0; i < result_size; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
