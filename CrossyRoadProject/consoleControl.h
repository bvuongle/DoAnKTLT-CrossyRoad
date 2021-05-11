﻿#pragma once
#include "varsANDlibs.h"
#include "gameMovement.h"
using namespace std;

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void subThread() {
	bool stop = false;
	int demstop = 49;
	while (1) {
		if (state) {
			switch (direction) {
			case 'A': moveLeft(); break;
			case 'D': moveRight(); break;
			case 'W': moveUp(); break;
			case 'S': moveDown(); break;
			}
			direction = ' ';
			if (stop)	demstop++;
			else	demstop--;
			if (demstop == 0 || demstop == 50)	stop = !stop;
			if (!stop) {
				eraseCars();
				moveCars();
				drawCars("=");
				drawBoard(0, 0, WIDTH_CONSOLE, PLAYGROUND_SECTION_HEIGHT);
			}
			if (isImpact(player, player.y)) {
				processDead();
			}
			if (player.y == 2) {
				if (player.x == currpos[0] || player.x == currpos[1]) 
					processDead();
				else
					processPass(player);
			}
			Sleep(10);
		}
	}
}