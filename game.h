#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define ROW 3
#define LEF 3



void print_chessboard(char chessboard[ROW][LEF],int row, int lef);
void meun(int n);

void initialize(char chessboard[ROW][LEF], int row, int lef);
void playgame(char chessboard[ROW][LEF], int row, int lef);
void computergame(char chessboard[ROW][LEF], int row, int lef, int j);
char judgment(char chessboard[ROW][LEF], int row, int lef);
int computergameend(char chessboard[ROW][LEF], int row, int lef, int n, int ret, int m);
void du_king(char chessboard[ROW][LEF], int row, int lef, int n, int m);
int computer_corner(char chessboard[ROW][LEF], int row, int lef, int j);//ֻ�ڽ����������
int changexy(char chessboard[ROW][LEF], int row, int lef, int ch);//��ת����
int changechess(char chessboard[ROW][LEF], int row, int lef, int n, int ret, int m, int chi);//���Ʒ�ת����