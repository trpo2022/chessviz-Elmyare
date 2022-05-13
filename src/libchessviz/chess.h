#pragma once

#ifndef CHESS_H
#define CHESS_H

typedef struct {
    int color; // 0 = black, 1 = white
    char figure;
} cell;

typedef cell table[64];

void table_print(table board);

void table_fill(table board);

void move(table board, const char figure_step[5]);

int check_input(const char figure_step[5]);

void get_coordinates(
        int* first_cell, int* second_cell, const char figure_step[5]);

#endif