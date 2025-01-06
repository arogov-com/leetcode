// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     int* ret = malloc(2 * sizeof(int));
//     if(ret == NULL) {
//         return NULL;
//     }

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i=0; i<numsSize; ++i) {
        for(int j = i + 1; j < numsSize; ++j) {
            if(nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
            if(nums[numsSize - i - 1] + nums[numsSize - j - 1] == target) {
                ret[0] = numsSize - i - 1;
                ret[1] = numsSize - j - 1;
                return ret;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

// 2,7,11,15
//     2 7
//     2 11
//     2 15
//     7 11
//     7 15
//     11 15

//     11 15
//     7 15
//     2 15
//     7 11
//     2 11
//     2 7

int main(int argc, char const *argv[]) {
    // int nums[] = {2,7,11,15}; int numsSize = 4; int target = 9;
    // int nums[] = {3,2,4}; int numsSize = 3; int target = 6;
    int nums[] = {15,11,7,2}; int numsSize = 4; int target = 9;

    int retsz;
    int* retptr = twoSum(nums, numsSize, target, &retsz);
    printf("[");
    for(int i=0; i < retsz; ++i) {
        printf("%d ", retptr[i]);
    }
    printf("]");
    free(retptr);
    return 0;
}
