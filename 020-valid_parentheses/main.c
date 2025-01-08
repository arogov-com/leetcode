#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s) {
    short index = 0;
    short stack = 0;

    while(s[index]) {
        switch(s[index]) {
            case '(':  // Case fall
            case '{':  // Case fall
            case '[':
                s[stack++] = s[index];
                break;
            case ')':
                if(stack == 0 || s[--stack] != '(') return false;
                break;
            case '}':
                if(stack == 0 || s[--stack] != '{') return false;
                break;
            case ']':
                if(stack == 0 || s[--stack] != '[') return false;
                break;
            default:
                return false;
        }
        ++index;
    }

    if(stack) {
        return false;
    }

    return true;
}

int main(int argc, char const *argv[]) {
    {
        char s[] = "()";
        printf("%d\n", isValid(s) == true);
    }
    {
        char s[] = "()[]{}";
        printf("%d\n", isValid(s) == true);
    }
    {
        char s[] = "(]";
        printf("%d\n", isValid(s) == false);
    }
    {
        char s[] = "([])";
        printf("%d\n", isValid(s) == true);
    }
    {
        char s[] = "([)]";
        printf("%d\n", isValid(s) == false);
    }
    {
        char s[] = "[[]]{{}}({})";
        printf("%d\n", isValid(s) == true);
    }
    {
        char s[] = "[";
        printf("%d\n", isValid(s) == false);
    }
    {
        char s[] = "((";
        printf("%d\n", isValid(s) == false);
    }
    {
        char s[] = "[])";
        printf("%d\n", isValid(s) == false);
    }
    {
        char s[] = "){";
        printf("%d\n", isValid(s) == false);
    }
    {
        char s[] = "(){}}{";
        printf("%d\n", isValid(s) == false);
    }
    {
        char s[] = "(([]){})";
        printf("%d\n", isValid(s) == true);
    }

    return 0;
}
