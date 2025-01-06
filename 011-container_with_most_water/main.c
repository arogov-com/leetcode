#include <stdio.h>
#include <sys/param.h>

int maxArea(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int volume = 0;
    while(l != r) {
        int min = MIN(height[l], height[r]);
        volume = min * (r - l) > volume ? min * (r - l) : volume;

        if(height[l] <= height[r]) {
            ++l;
        }
        else if(height[r] < height[l]) {
            --r;
        }
    }
    return volume;
}

int main(int argc, char const *argv[]) {
    int array[] = {1,8,6,2,5,4,8,3,7}; int len = 9;
    maxArea(array, len);
    return 0;
}
