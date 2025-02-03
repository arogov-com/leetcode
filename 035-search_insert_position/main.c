#include <stdio.h>


int searchInsert(int* nums, int numsSize, int target) {
    int i;
    for(i = 0; i < numsSize; ++i) {
        if(nums[i] >= target) {
            return i;
        }
    }
    return i;
}


int main(int argc, char const *argv[]) {
    int nums[] = {1, 3, 5, 6}, target = 7;

    int result = searchInsert(nums, sizeof(nums) / sizeof(nums[0]), target);

    printf("%d\n", result);
    return 0;
}
