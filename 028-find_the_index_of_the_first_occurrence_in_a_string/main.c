#include <stdio.h>


int strStr(char* haystack, char* needle) {
    int i = 0;
    int j = 0;
    int f = -1;
    while(haystack[i] != '\x0') {
        if(haystack[i] == needle[j]) {
            if(f == -1) {
                f = i;
            }
            if(needle[++j] == '\x0') {
                return f;
            }
        }
        else if(f != -1) {
            i = f + 1;
            f = -1;
            j = 0;
            continue;
        }
        ++i;
    }

    return -1;
}


int main(int argc, char const *argv[]) {
    // char *s = "sadbutsad", *n = "sad"; int a = 0;
    // char *s = "satbutsad", *n = "sad"; int a = 6;
    // char *s = "mississippi", *n = "issip"; int a = 4;
    // char *s = "aaa", *n = "aaaa"; int a = -1;
    char *s = "mississippi", *n = "pi"; int a = 9;

    int result = strStr(s, n);

    printf("%d %d\n", result, result == a);
    return 0;
}
