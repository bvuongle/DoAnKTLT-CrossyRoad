// variables and libraries
#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <conio.h>
#include <string>
using namespace std;

const int  MAX_CAR = 21;
const int  MAX_CAR_LENGTH = 40;
const int  MAX_SPEED = 3;
const int PLAYGROUND_SECTION_HEIGHT = 24, INFO_SECTION_HEIGHT = 4;
const int WIDTH_CONSOLE = 118, HEIGHT_CONSOLE = 28;
const POINT DEFAULT_CHARACTER_POS = { 58,24 };

POINT** carArray;
POINT player;
int cnt = 0;
int direction, speed, step; //direction = W, A, S, D; speed = level = 1, 2, 3;
bool state; // Dead = 0, Alive = 1;
int currpos[2];
string player_name;
