#include <stdio.h>


void sortColors(int* nums, int numsSize) {
    int colors[3] = {0};
    --numsSize;

    for(int i = 0; i <= numsSize / 2; ++i) {
        ++colors[nums[i]];
        if(i != numsSize - i) {
            ++colors[nums[numsSize - i]];
        }
    }

    for(int i = 0; i <= numsSize / 2; ++i) {
        if(colors[1] && !colors[0]) {
            --colors[1];
            nums[i] = 1;
        }
        if(colors[1] && !colors[2]) {
            --colors[1];
            nums[numsSize - i] = 1;
        }
        if(colors[0]) {
            --colors[0];
            nums[i] = 0;
        }
        if(colors[2]) {
            --colors[2];
            nums[numsSize - i] = 2;
        }
    }
}


int main(int argc, char const *argv[]) {
    // int nums[] = {2, 0, 2, 1, 1, 0};
    // int nums[] = {2, 0, 1, 0, 0};
    // int nums[] = {2, 0, 1, 0, 0, 0};
    // int nums[] = {0, 0};
    int nums[] = {0, 1, 0};

    sortColors(nums, sizeof(nums) / sizeof(int));

    for(int i = 0; i < sizeof(nums) / sizeof(int); ++i) printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
