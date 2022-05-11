#include <libchessviz/chess.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char step[5] = "a1-a1";
    table board;
    table_fill(board);
    printf("\n");
    while (check_input(step)) {
        move(board, step);
        table_print(board);
        printf("\n");
        scanf("%s", step);
    }
    return 0;
}
