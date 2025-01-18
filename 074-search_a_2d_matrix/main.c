#include <stdio.h>
#include <stdbool.h>


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int left = 0;
    int right = matrixSize - 1;
    int center = right / 2;
    while(left <= right) {
        if(matrix[center][0] > target) {
            right = center - 1;
            center = (right - left) / 2;
        }
        else if(matrix[center][0] < target) {
            left = center + 1;
            center = (right - left) / 2 + left;
        }
        else if(matrix[center][0] == target) {
            return true;
        }
    }

    if(right < 0) {
        return false;
    }

    int col = right;

    left = 0;
    right = *matrixColSize - 1;
    center = right / 2;
    while(left <= right) {
        if(matrix[col][center] > target) {
            right = center - 1;
            center = (right - left) / 2;
        }
        else if(matrix[col][center] < target) {
            left = center + 1;
            center = (right - left) / 2 + left;
        }
        else if(matrix[col][center] == target) {
            return true;
        }
    }

    return false;
}


int main(int argc, char const *argv[]) {
    int *matrix[] = {(int []){1,3,5,7},
                     (int []){10,11,16,20},
                     (int []){22,30,34,60},
                     (int []){61,62,64,65}};
    int matrixSize = 4;
    int matrixColSize = 4;
    int target = 65;

    printf("%d\n", searchMatrix(matrix, matrixSize, &matrixColSize, target));

    return 0;
}