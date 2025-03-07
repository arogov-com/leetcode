#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);

    int numsSz = numsSize;
    int retLen = 0;

    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * numsSize * numsSize);
    int **ret = malloc(sizeof(int*) * numsSize * numsSize);

    for (int i = 0; i < numsSize - 2; ++i) {
        if (i == 0 || nums[i] != nums[i-1]) {
            int l = i + 1;
            int r = numsSize - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < 0) {
                    ++l;
                }
                else if (nums[i] + nums[l] + nums[r] > 0) {
                    --r;
                }
                else {
                    ret[*returnSize] = malloc(sizeof(int) * 3);
                    (*returnColumnSizes)[*returnSize] = 3;
                    ret[*returnSize][0] = nums[i];
                    ret[*returnSize][1] = nums[l++];
                    ret[*returnSize][2] = nums[r];
                    ++(*returnSize);
                    while (l < r && nums[l] == nums[l-1]) {
                        ++l;
                    }
                }
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    int nums[] = {-1, -1, 2, -1, 2, -1};
    // int nums[] = {-1, 0, 1, 2, -1, -4};
    // int nums[] = {0, 0, 0};
    // int nums[] = {0, 0, 0, 0};

    int returnSize;
    int *returnColumnSizes;

    int **ret = threeSum(nums, sizeof(nums) / sizeof(nums[0]), &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; ++i) {
        printf("[%d, %d, %d] %d\n", ret[i][0], ret[i][1], ret[i][2], returnColumnSizes[i]);
    }

    return 0;
}
