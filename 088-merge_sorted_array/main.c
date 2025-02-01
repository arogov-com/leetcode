#include <stdio.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if(n == 0) {
        return;
    }
    --m;
    --n;
    --nums1Size;
    while(nums1Size >= 0 && n >= 0) {
        if(m < 0) {
            nums1[nums1Size--] = nums2[n--];
            continue;
        }
        if(nums2[n] > nums1[m]) {
            nums1[nums1Size--] = nums2[n--];
        }
        else if(nums2[n] <= nums1[m]) {
            nums1[nums1Size--] = nums1[m--];
        }
    }
}


int main(int argc, char const *argv[]) {
    int nums1[] = {1, 2, 3, 0, 0, 0}, m = 3;
    int nums2[] = {2, 5, 6}, n = 3;
    // int nums1[] = {1}, m = 1;
    // int nums2[] = {}, n = 0;
    // int nums1[] = {0}, m = 0;
    // int nums2[] = {1}, n = 1;
    // int nums1[] = {4,5,6,0,0,0}, m = 3;
    // int nums2[] = {1,2,3}, n = 3;

    merge(nums1, m + n, m, nums2, n, n);

    printf("[");
    for(int i = 0; i < m + n; ++i) {
        printf("%d ", nums1[i]);
    }
    printf("]\n");

    printf("[");
    for(int i = 0; i < n; ++i) {
        printf("%d ", nums2[i]);
    }
    printf("]\n");
    return 0;
}
