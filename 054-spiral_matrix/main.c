#include <stdio.h>
#include <stdlib.h>


int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = matrixSize * (*matrixColSize);
    int *ret = malloc(*returnSize * sizeof(int));

    char ret_idx = 0;

    char i = 0;
    char j = 0;
    char inc_i = 0;
    char inc_j = 1;
    char left = 0;
    char top = 1;

    enum direction {
        LEFT_RIGHT,
        TOP_BOTTPM,
        RIGHT_LEFT,
        BOTTOM_TOP,
    }state = LEFT_RIGHT;

    while(ret_idx < *returnSize) {
        ret[ret_idx++] = matrix[i][j];

        switch(state) {
            case LEFT_RIGHT:
                if(j >= *matrixColSize - 1) {
                    inc_j = 0;
                    inc_i = 1;
                    --(*matrixColSize);
                    state = TOP_BOTTPM;
                }
                break;
            case TOP_BOTTPM:
                if(i >= matrixSize - 1) {
                    inc_i = 0;
                    inc_j = -1;
                    --matrixSize;
                    state = RIGHT_LEFT;
                }
                break;
            case RIGHT_LEFT:
                if(j <= left) {
                    inc_i = -1;
                    inc_j = 0;
                    ++left;
                    state = BOTTOM_TOP;
                }
                break;
            case BOTTOM_TOP:
                if(i <= top) {
                    inc_i = 0;
                    inc_j = 1;
                    ++top;
                    state = LEFT_RIGHT;
                }
                break;
        }

        i += inc_i;
        j += inc_j;
    }

    return ret;
}


int main(int argc, char const *argv[]) {
    // int *matrix[] = {(int []){ 1,  2,  3,  4},
    //                  (int []){ 5,  6,  7,  8},
    //                  (int []){ 9, 10, 11, 12},
    //                  (int []){12, 13, 14, 15}};
    // int result_check[] = {1,2,3,4,8,12,15,14,13,12,9,5,6,7,11,10};
    int *matrix[] = {(int []){ 1, 2, 3, 4},
                     (int []){ 5, 6, 7, 8},
                     (int []){ 9,10,11,12},
                     (int []){13,14,15,16},
                     (int []){17,18,19,20},
                     (int []){21,22,23,24}};
    int result_check[] = {1,2,3,4,8,12,16,20,24,23,22,21,17,13,9,5,6,7,11,15,19,18,14,10};

    int matrixSize = 6; // Collumns
    int matrixColSize = 4; // Rows
    int returnSize;

    int *result = spiralOrder(matrix, matrixSize, &matrixColSize, &returnSize);
    for(int i = 0; i < returnSize; ++i) {
        if(result[i] != result_check[i]) {
            printf("Error at index %d\n", i);
            break;
        }
    }

    printf("PASSED\n");
    free(result);
    return 0;
}
