#pragma once

#define UP 72
#define DOWN 80
#define ENTER 13

#define MAIN 0
#define START 1
#define LOAD 2
#define QUIT 3

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <vector>

using std::cout;
using std::endl;
using std::setw;
using std::vector;

void Start();
void gotoXY(int x, int y);
void MainInit(int currentstatus);
void Screen(int statusnum);
//void StartInit();
int MenuSelect();
int menuNum;