#include <stdio.h>


int removeDuplicates(int* nums, int numsSize) {
    short late = 0;
    for(int i = 0; i < numsSize; ++i) {
        if(nums[i] != nums[late]) {
            nums[++late] = nums[i];
        }
    }

    return late + 1;
}


int main(int argc, char const *argv[]) {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};

    int size = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));

    printf("[");
    for(int i = 0; i < size; ++i) {
        printf("%d ", nums[i]);
    }
    printf("]\n");
    return 0;
}
