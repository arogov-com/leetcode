#include <stdio.h>
#include <stdlib.h>


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ret = malloc(sizeof(int) * 2);
    ret[0] = ret[1] = -1;
    *returnSize = 2;

    int left = 0;
    int right = numsSize - 1;
    int first = -1;
    while(left <= right) {
        int center = (left + right) / 2;
        if(nums[center] > target) {
            right = center - 1;
        }
        else if(nums[center] < target) {
            left = center + 1;
        }
        else if(nums[center] == target) {
            first = center;
            right = center - 1;
        }
    }
    if(first != -1) {
        ret[0] = ret[1] = first;
        while(ret[1] < numsSize && nums[ret[1]] == target) {
            ++ret[1];
        }
        --ret[1];
    }

    return ret;
}


int main(int argc, char const *argv[]) {
    int returnSize;
    // int nums[] = {5,7,7,8,8,10}; int target = 8;
    // int nums[] = {5,7,8,8,8,10}; int target = 8;
    // int nums[] = {5,7,7,8,8,10}; int target = 6;
    int nums[] = {}; int target = 2;
    int *ret = searchRange(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);

    printf("[%d,%d]\n", ret[0], ret[1]);
    free(ret);
    return 0;
}
