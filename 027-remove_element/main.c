#include <stdio.h>


int removeElement(int* nums, int numsSize, int val) {
    int late = 0;
    for(int i = 0; i < numsSize; ++i) {
        if(nums[i] != val) {
            nums[late++] = nums[i];
        }
    }
    return late;
}


int main(int argc, char const *argv[]) {
    int nums[] = {0,1,2,2,3,0,4,2}; int val = 2;

    int size = removeElement(nums, sizeof(nums) / sizeof(nums[0]), val);

    printf("[");
    for(int i = 0; i < size; ++i) {
        printf("%d ", nums[i]);
    }
    printf("]\n");

    return 0;
}
