#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "complexMaze.h"

complexMaze::complexMaze(int row, int col, std::vector<robot*> rblist) :
	maze(row, col, rblist) {
	this->row = row;
	this->col = col;
}

complexMaze::~complexMaze() {
}

void complexMaze::mazeStructure() {
    maze::mazeStructure();
}

void complexMaze::visit(int x, int y) {
	map[x][y] = 1;

    int dir[4];
    dir[0] = 0;
    dir[1] = 1;
    dir[2] = 2;
    dir[3] = 3;

    for (int i = 0; i < 4; ++i){
        int r = rand() % 3;
        int temp = dir[r];
        dir[r] = dir[i];
        dir[i] = temp;
    }

    for (int i = 0; i < 4; ++i){
        int dx = 0, dy = 0;

        switch (dir[i]){
            case 0: 
                dy = -1; 
                break;

            case 1:
                dx = 1;
                break;
            
            case 2: 
                dy = 1; 
                break;
            
            case 3: 
                dx = -1; 
                break;
        }

        int x2 = x + 2 * dx;
        int y2 = y + 2 * dy;

        if (x2 < 0 || x2 >= row || y2 < 0 || y2 >= col) {
            return;
        }
        else {
            if (map[x2][y2] == 0) {
                map[x2 - dx][y2 - dy] = 1;
                visit(x2, y2);
            }
        }
    }
}

void complexMaze::generateWall() {
    //srand(time(NULL));
    if ((row / 2) % 2 == 0 || (col / 2) % 2 == 0) {
        visit(row / 2 + 1, col / 2 + 1);
    }
    else {
        visit(row / 2, col / 2);
    }

    //trim all the border, make it become a path around the maze 
    //so robot can move freely outside
    for (int i = 0; i < col; i++) {
        map[0][i] = 0;
        map[row - 1][i] = 0;
    }

    for (int i = 0; i < row; i++) {
        map[i][0] = 0;
        map[i][col - 1] = 0;
    }

    //generate exit
    srand(time(NULL));
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j) {
            int x = rand() % (row - 1);
            int y = rand() % (col - 1);

            if (map[x][y] != 1){
                map[x][y] = 2;
                break;
            }
        }
        break;
    }
}

void complexMaze::display() {
	maze::display();
}