#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int n = nums1Size + nums2Size;
    int left = (nums1Size + nums2Size + 1) / 2;

    int low = 0;
    int high = nums1Size;
    while(low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int r1 = INT_MAX;
        int l2 = INT_MIN;
        int r2 = INT_MAX;
        if(mid1 < nums1Size) {
            r1 = nums1[mid1];
        }
        if(mid2 < nums2Size) {
            r2 = nums2[mid2];
        }
        if(mid1 - 1 >= 0) {
            l1 = nums1[mid1 - 1];
        }
        if(mid2 - 1 >= 0) {
            l2 = nums2[mid2 - 1];
        }

        if(l1 <= r2 && l2 <= r1) {
            if(n % 2 == 1) {
                return MAX(l1, l2);
            }
            else {
                return ((double)(MAX(l1, l2) + MIN(r1, r2))) / 2.0;
            }
        }
        else if(l1 > r2) {
            high = mid1 - 1;
        }
        else {
            low = mid1 + 1;
        }
    }

    return 0;
}


int main(int argc, char **argv) {
    // int array1[] = {0, 1, 2, 3, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21}; int array2[] = {4, 5, 6, 7, 8, 9};
    // int array1[] = {0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14}; // sleft = 4 sright = 3 scenter = 4
    // int array2[] = {4, 5, 6, 7};
    // int array1[] = {0,0,0,0,0}; // sleft = 0 sright = 6 scenter = 3
    // int array2[] = {-1,0,0,0,0,0,1};
    // int array1[] = {1, 3}; // sleft = 1 sright = 0 scenter = 1
    // int array2[] = {2};
    // int array1[] = {0, 1, 2, 3, 4, 5, 6, 7, 11, 12, 13}; // sleft = 8 sright = 7 scenter = 7
    // int array2[] = {8, 9, 10};
    // int array1[] = {0, 1, 2, 3, 4, 5, 6, 11, 12, 13, 14, 15}; // sleft = 7 sright = 6 scenter = 7
    // int array2[] = {7, 8, 9, 10};
    // int array1[] = {0, 1, 2, 3, 4, 5, 6, 10, 11, 12, 13, 14}; // sleft = 7 sright = 6 scenter = 7
    // int array2[] = {7, 8, 9};
    // int array1[] = {0, 1, 2, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // sleft = 3 sright = 2 scenter = 3
    // int array2[] = {3, 4, 5};
    // int array1[] = {1, 3}, array2[] = {2, 7};
    // int array2[] = {1, 2, 3, 6, 7}, array1[] = {4, 5}; // 4
    // int array1[] = {1, 2}; int array2[] = {1, 2, 3}; // 2
    // int array1[] = {1, 3}; int array2[] = {2, 4, 5}; // 3
    // int array1[] = {0, 1, 2, 3, 4, 5, 6, 10, 11, 12, 13, 14}; int array2[] = {7, 8, 9, 9}; // 12 4 16
    int array1[] = {1, 2}; int array2[] = {3, 4};

    double median = findMedianSortedArrays(array1, sizeof(array1) / sizeof(array1[0]), array2, sizeof(array2) / sizeof(array2[0]));
    printf("median = %f\n", median);

    return 0;
}
