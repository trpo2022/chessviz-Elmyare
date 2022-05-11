#include <libchessviz/chess.h>
#include <stdio.h>
#include <string.h>

void table_print(table board)
{
    int i, j;
    for (i = 8; i > 0; i--) {
        printf("%d", i);
        for (j = 0; j < 8; j++) {
            printf(" %c", board[(8 - i) * 8 + j].figure);
        }
        printf("\n");
    }
    printf("  a b c d e f g h");
}

void table_fill(table board)
{
    int i, j, k;
    for (i = 0; i < 8; i++) {
        board[8 + i].color = 1;
        board[8 + i].figure = 'p';
        board[8 + i].color = 0;
        board[48 + i].figure = 'p';
    }
    char figures[8] = "rbnkqnbr";
    int color = 1;
    for (j = 0; j < 2; j++) {
        for (k = 0; k < 8; k++) {
            board[(j * 2 + 2) * 8 + k].figure = ' ';
            board[(j * 2 + 3) * 8 + k].figure = ' ';
            board[(j * 2 + 2) * 8 + k].color = 3;
            board[(j * 2 + 3) * 8 + k].color = 3;
            board[j * 56 + k].figure = figures[k];
            board[j * 56 + k].color = color;
        }
        color = 0;
    }
}

void move(table board, const char figure_step[5])
{
    int cell_1 = (figure_step[0] - 'a') + ((8 - (figure_step[1] - '0')) * 8);
    int cell_2 = (figure_step[3] - 'a') + ((8 - (figure_step[4] - '0')) * 8);
    // printf("%d %d\n", cell_1, cell_2);
    int buf_color = board[cell_1].color;
    char buf_figure = board[cell_1].figure;
    board[cell_1].figure = ' ';
    board[cell_1].color = 3;
    board[cell_2].figure = buf_figure;
    board[cell_2].color = buf_color;
}

int check_input(const char figure_step[5])
{
    int result = 0;
    if (figure_step[0] >= 'a' && figure_step[0] <= 'h' && figure_step[1] >= '1'
        && figure_step[1] <= '8' && figure_step[2] == '-'
        && figure_step[3] >= 'a' && figure_step[3] <= 'h'
        && figure_step[4] >= '1' && figure_step[4] <= '8') {
        result = 1;
    }
    return result;
}