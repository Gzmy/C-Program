#pragma once
#ifndef __CHESS_H__
#define __CHESS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

enum iswin {
	X,//玩家赢
	O,//电脑赢
	P,//平局
	J};

void InitBoard(char arr[ROW][COL], int row, int col);
void Display(char arr[ROW][COL], int row, int col);
void PlayerMove(char arr[ROW][COL], int row, int col);
void ComputerMove(char arr[ROW][COL], int row, int col);
char IsWin(char arr[ROW][COL], int row, int col);

#endif
