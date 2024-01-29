#pragma once

#define UP 72
#define DOWN 80
#define ENTER 13

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

using std::cout;
using std::endl;
using std::setw;

void StartGame();
void gotoXY(int x, int y);
void init();
int MenuSelect();