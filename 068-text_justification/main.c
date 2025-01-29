#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int *wordsLens = malloc(sizeof(int) * wordsSize);
    char **result = NULL;
    *returnSize = 0;

    int stringLen = 0;
    int wordsCount = 0;
    int start_idx = 0;
    for(int i = 0; i < wordsSize; ++i) {
        wordsLens[i] = strlen(words[i]);
        stringLen += wordsLens[i];
        ++wordsCount;
        printf("%s %d\n", words[i], wordsLens[i]);

        if(stringLen + i - start_idx > maxWidth) {
            stringLen -= wordsLens[i];

            result = realloc(result, (*returnSize + 1) * sizeof(char *));
            result[*returnSize] = malloc(maxWidth + 1);
            char *string = result[*returnSize];
            result[*returnSize][maxWidth] = '\x0';

            int spaces = (maxWidth - stringLen) / ((wordsCount - 2) ? (wordsCount - 2) : 1);
            int spaces_extra = (maxWidth - stringLen) % ((wordsCount - 2) ? (wordsCount - 2) : 1);
            int j;
            for(j = start_idx; j < i - 1; ++j) {
                memcpy(string, words[j], wordsLens[j]);
                string += wordsLens[j];
                memset(string, ' ', spaces + (spaces_extra > 0 ? 1 : 0));
                string += spaces + (spaces_extra > 0 ? 1 : 0);
                --spaces_extra;
            }
            memcpy(string, words[j], wordsLens[j]);
            if(wordsCount == 2) {
                memset(string + stringLen, ' ', maxWidth - stringLen);
            }
            printf("[%s]\n", result[*returnSize]);
            stringLen = 0;
            wordsCount = 0;
            start_idx = i--;
            ++(*returnSize);
        }
    }

    result = realloc(result, (*returnSize + 1) * sizeof(char *));
    result[*returnSize] = malloc(maxWidth + 1);
    stringLen = 0;
    for(int i = start_idx; i < wordsSize; ++i) {
        int len = strlen(words[i]);
        memcpy(&result[*returnSize][stringLen], words[i], len);
        stringLen += len;
        result[*returnSize][stringLen++] = ' ';
        printf("[%s] %d\n", words[i], len);
    }
    if(stringLen < maxWidth) {
        memset(&result[*returnSize][stringLen], ' ', maxWidth - stringLen);
    }
    result[*returnSize][maxWidth] = '\x0';
    ++(*returnSize);

    free(wordsLens);
    return result;
}


int main(int argc, char const *argv[]) {
    // char *words[] = {"This", "is", "an", "example", "of", "text", "justification."}; int maxWidth = 16;
    // char *words[] = {"What","must","be","acknowledgment","shall","be"}; int maxWidth = 16;
    // char *words[] = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}; int maxWidth = 20;
    char *words[] = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"}; int maxWidth = 16;
    int returnSize;
    char **res = fullJustify(words, sizeof(words) / sizeof(char*), maxWidth, &returnSize);

    if(res == NULL) {
        return 1;
    }
    printf("-------------------------------------\n");
    for(int i = 0; i < returnSize; ++i) {
        printf("[%s]\n", res[i]);
    }
    printf("\n");

    return 0;
}

