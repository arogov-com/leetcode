#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

static inline uint64_t get_cycles() {
  uint64_t t;
  __asm volatile ("rdtsc" : "=A"(t));
  return t;
}

bool isPalindrome(int x) {
uint64_t start = get_cycles();
    if(x < 0) {
        return 0;
    }
    if(x < 10) {
        return 1;
    }

    int divider = 1000000000;
    int left;
    while((left = x / divider) == 0) {
        divider /= 10;
    }
uint64_t point1 = get_cycles();
    while(x) {
        int right = x % 10;
        if(left != right) {
uint64_t point2 = get_cycles();
printf("start - point1: %ld; point1 - point2: %ld; start - point2: %ld\n", point1 - start, point2 - point1, point2 - start);
            return 0;
        }
        x -= divider * left;
        x /= 10;
        divider /= 100;
        left = x / (divider ? divider : 1);
    }
uint64_t point2 = get_cycles();
printf("start - point1: %ld; point1 - point2: %ld; start - point2: %ld\n", point1 - start, point2 - point1, point2 - start);
    return 1;
}

// bool isPalindrome(int x) {
// uint64_t start = get_cycles();
//     if(x < 0) {
//         return 0;
//     }
//     if(x < 10) {
//         return 1;
//     }

//     int64_t divider = 10;
//     int nums = 2;
// uint64_t point1 = get_cycles();
//     while(x / divider > 9) {
//         divider *= 10;
//         ++nums;
//     }

//     nums /= 2;
// uint64_t point2 = get_cycles();

//     while(nums--) {
//         int right = x % 10;
//         int left = x / divider;
//         if(left != right) {
//             uint64_t point3 = get_cycles();
//             printf("start - point1: %ld; point1 - point2: %ld; point2 - point3: %ld\n", point1 - start, point2 - point1, point3 - point2);

//             return 0;
//         }

//         x -= divider * left;
//         x /= 10;
//         divider /= 100;
//     }
// uint64_t point3 = get_cycles();
// printf("start - point1: %ld; point1 - point2: %ld; point2 - point3: %ld\n", point1 - start, point2 - point1, point3 - point2);
//     return 1;
// }

int main(int argc, char const *argv[]) {
    printf("%d\n", isPalindrome(-1));
    printf("%d\n", isPalindrome(6));
    printf("%d\n", isPalindrome(10));
    printf("%d\n", isPalindrome(44));
    printf("%d\n", isPalindrome(2322));
    printf("%d\n", isPalindrome(2322));
    printf("%d\n", isPalindrome(101));
    printf("%d\n", isPalindrome(1001));
    printf("%d\n", isPalindrome(1000021));
    printf("%d\n", isPalindrome(1220321));
    printf("%d\n", isPalindrome(1230321));
    printf("%d\n", isPalindrome(1234567899));
    printf("%d\n", isPalindrome(1234554321));
    printf("%d\n", isPalindrome(122221));
    return 0;
}
