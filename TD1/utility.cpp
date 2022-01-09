#include "utility.h"
#include <Windows.h>
#include <iostream>

//fixed position
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

//display the robot to the maze
void robotDisplay(int x, int y, int val) {
    gotoxy(y* 2, x + 4); 
    if (val != 2) { //if not exit, robot will display with the number have been given in each robot class
        std::cout << val;
    } //if robot move to exit point, it will disappear
}
