#include "maze.h"
#include "randomMaze.h"
#include "robot.h"
#include "crazyRobot.h"
#include "Point2D.hpp"
#include "utility.h"
#include "leftRobot.h"
#include "rightRobot.h"
#include "upRobot.h"
#include "downRobot.h"
#include "jumpRobot.h"
#include "smartRobot.h"
#include "verySmartRobot.h"
#include "complexMaze.h"

#include <iostream>
#include <Windows.h>

int main() {
	std::vector<robot*> robots;
	std::vector<bool> check_list; //check if robot is on the field or not

	std::cout << "EXERCISE 1: CREATE MAZE" << std::endl << std::endl;

	maze* M = new maze(15, 20, robots);
	M->mazeStructure();
	M->display();

	std::cout << "Press ENTER to continue..." << std::endl;
	getchar();

	std::system("cls");

	std::cout << "EXERCISE 2: CREATE RANDOMMAZE WITH WALL" << std::endl << std::endl;

	//wallLength restrict: it's can't be larger than row or col
	//format: row, col wallNumber, wallLength, list of robot
	maze* RM = new randomMaze(15, 20, 10, 5, robots);
	RM->mazeStructure();
	RM->generateWall();
	RM->display();

	std::cout << "Press ENTER to next excercise..." << std::endl;

	getchar();

	std::system("cls");

	//create robot and add it to robot list
	robot* cr = new crazyRobot(); robots.push_back(cr); //ex3
	robot* lr = new leftRobot(); robots.push_back(lr); //ex4
	robot* rr = new rightRobot(); robots.push_back(rr); //ex5
	robot* ur = new upRobot(); robots.push_back(ur); //ex5
	robot* dr = new downRobot(); robots.push_back(dr); //ex5
	robot* jr = new jumpRobot(); robots.push_back(jr); //ex6
	//put every kind of step if you want how robot to jump here
	//remember if your input larger than maze height or length, your robot won't move
	jr->setJumpStep(2);
	robot* sr = new smartRobot(); robots.push_back(sr); //ex8
	robot* vsr = new verySmartRobot(); robots.push_back(vsr);//ex9

	RM->setRblist(robots);
	for (int i = 0; i < RM->getRblist().size(); i++) {
		check_list.push_back(false); //check_list will add the status of robot to false (false mean not on the field)
	}

	gotoxy(0, 0);
	std::cout << "EXERCISE 10: TEST ALL ROBOTS AND THEIR MOMEVENT";

	gotoxy(0, 2);
	std::cout << "Press ENTER to make robot move | Press ESC then ENTER to next excercise";

	while (true) {
		gotoxy(0, 4);
		RM->display();
		for (unsigned int i = 0; i < RM->getRblist().size(); i++) {
			RM->getRblist()[i]->readMaze(RM);

			if (check_list[i] == 0) {
				RM->getRblist()[i]->setInitPos(); //spawn robot
				check_list[i] = 1; //robot spawn and check_list will turn to 1
			}
			RM->getRblist()[i]->go();

			robotDisplay(RM->getRblist()[i]->getInitPos().getX(),
				RM->getRblist()[i]->getInitPos().getY(),
				RM->getRblist()[i]->public_map_r[robots[i]->getInitPos().getX()][RM->getRblist()[i]->getInitPos().getY()]);

			///* Set cursor */
			//gotoxy(0, RM->getRblist()[i]->public_map_r.size() + 2);
		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
		else {
			getchar();
		}
	}

	std::system("cls");

	maze* cm = new complexMaze(15, 20, robots);
	cm->mazeStructure();
	cm->generateWall();

	gotoxy(0, 0);
	std::cout << "EXERCISE 11: COMPLEX MAZE";

	gotoxy(0, 2);
	std::cout << "Press ENTER to make robot move | Press ESC then ENTER to next excercise";

	check_list.clear();
	cm->setRblist(robots);
	for (int i = 0; i < cm->getRblist().size(); i++) {
		check_list.push_back(false); //check_list will add the status of robot to false (false mean not on the field)
	}

	while (true) {
		gotoxy(0, 4);
		cm->display();
		for (unsigned int i = 0; i < cm->getRblist().size(); i++) {
			cm->getRblist()[i]->readMaze(cm);

			if (check_list[i] == 0) {
				cm->getRblist()[i]->setInitPos(); //spawn robot
				check_list[i] = 1; //robot spawn and check_list will turn to 1
			}
			cm->getRblist()[i]->go();

			robotDisplay(cm->getRblist()[i]->getInitPos().getX(),
				cm->getRblist()[i]->getInitPos().getY(),
				cm->getRblist()[i]->public_map_r[robots[i]->getInitPos().getX()][cm->getRblist()[i]->getInitPos().getY()]);

			///* Set cursor */
			//gotoxy(0, cm->getRblist()[i]->public_map_r.size() + 2);
		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
		else {
			getchar();
		}
	}


}