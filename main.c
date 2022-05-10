#include <stdio.h>
#include <string.h>

struct elem {
    int team;
    char figure;
};

void table_print(struct elem* p);
void table_fill(struct elem* p);

int main()
{
    struct elem board[64];
    table_fill(board);
    table_print(board);
}

void table_print(struct elem* p)
{
    for (int i = 8; i > 0; i--) {
        printf("%d", i);
        for (int j = 0; j < 8; j++) {
            printf(" %c", p[(8 - i) * 8 + j].figure);
        }
        printf("\n");
    }
    printf("  a b c d e f g h");
}

void table_fill(struct elem* p)
{
    for (int i = 0; i < 8; i++) {
        p[8 + i].team = 1;
        p[8 + i].figure = 'p';
        p[8 + i].team = 0;
        p[48 + i].figure = 'p';
    }
    char figures[8] = "rbnkqnbr";
    int color = 1;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 8; k++) {
            p[(j * 2 + 2) * 8 + k].figure = ' ';
            p[(j * 2 + 3) * 8 + k].figure = ' ';
            p[j * 56 + k].figure = figures[k];
            p[j * 56 + k].team = color;
        }
        color = 0;
    }
}
