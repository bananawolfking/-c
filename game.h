#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define LEF 9
#define ROWS ROW+2
#define LEFS LEF+2
#define Easy_Count 10

void initialize(char mine[ROWS][LEFS], int row, int lef, int key);
void print(char mine[ROWS][LEFS], int row, int lef);
void Lay_mines(char mine[ROWS][LEFS], int row, int lef, int count);
void Find_mines(char mine[ROWS][LEFS], char out[ROWS][LEFS], int row, int lef, int count);
void count_plus(char mine[ROWS][LEFS], char out[ROWS][LEFS], int row, int lef, int x, int y, int ret);