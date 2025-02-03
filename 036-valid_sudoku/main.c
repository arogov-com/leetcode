#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>


bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    uint16_t row = 0;
    uint16_t col = 0;
    uint16_t cube[3] = {0};

    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < *boardColSize; ++j) {
            int8_t c = board[i][j] - '0';
            if(c != '.' - '0') {
                if(cube[j / 3] & (1 << c)) {
                    return false;
                }
                cube[j / 3] |= 1 << c;

                if(row & (1 << c)) {
                    return false;
                }
                row |= 1 << c;
            }

            c = board[j][i] - '0';
            if(c != '.' - '0') {
                if(col & (1 << c)) {
                    return false;
                }
                col |= 1 << c;
            }
        }

        if(i % 3 == 2) {
            cube[0] = cube[1] = cube[2] = 0;
        }

        row = 0;
        col = 0;
    }

    return true;
}


int main(int argc, char const *argv[]) {
    char *board[] = {{"53..7...."},
                     {"6..195..."},
                     {".98....6."},
                     {"8...6...3"},
                     {"4..8.3..1"},
                     {"7...2...6"},
                     {".6....28."},
                     {"...419..5"},
                     {"....8..79"}};
    int boardColSize = 9;

    bool result = isValidSudoku(board, boardColSize, &boardColSize);

    printf("%d\n", result);
    return 0;
}
