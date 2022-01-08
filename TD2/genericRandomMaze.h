#ifndef GENERICRANDOMMAZE_
#define GENERICRANDOMMAZE_

#include "genericMaze.h"

template <class X>

class randomMaze : public maze<X> {
private:
	X wallNumber, wallLength;
	X col, row;

public:
	//Constructor
	randomMaze(X row, X col, X wallNumber, X wallLength, std::vector<robot*> rblist) 
		: maze<X>::maze (row, col, rblist) {
		this->row = row;
		this->col = col;
		this->wallNumber = wallNumber;
		this->wallLength = wallLength;
	}

	//Destructor
	~randomMaze(){
	}

	//Getter
	X getWallNumber() const {
		return this->wallLength;
	}
	X getWallLength() const {
		return this->wallNumber;
	}

	//Setter
	void setWallNumber(X wallNumber) {
		this->wallNumber = wallNumber;
	}
	void setWallLength(X wallLength) {
		this->wallLength = wallLength;
	}

	void mazeStructure() override {
		maze<X>::mazeStructure();
	}

	void display() override {
		if (wallLength < 0) { //wallLength cannot negative
			std::cout << "Your input is invalid" << std::endl;
			return;
		}
		else if (wallLength > map.size()) { //wallLength cannot larger than row
			std::cout << "Your input is invalid" << std::endl;
			return;
		}
		else if (wallLength > map[0].size()) { //wallLength cannot larger than col
			std::cout << "Your input is invalid" << std::endl;
			return;
		}
		else {
			maze<X>::display();
		}
	}

	void generateWall() override {
		if (wallLength < 0) { //wallLength cannot negative
			return;
		}
		else if (wallLength > map.size()) { //wallLength cannot larger than row
			return;
		}
		else if (wallLength > map[0].size()) { //wallLength cannot larger than col
			return;
		}

		X vw = 0; // number of vertical wall 
		X hw = 0; // number of horizontal wall
		srand(time(NULL));
		for (X i = 0; i < wallNumber; ++i) { // genenrate number of vw and hw
			if (rand() % 2 == 0) {
				vw += 1;
			}
			else {
				hw += 1;
			}
		}

		X valid = true; //valid position, object can't get through valid

		//main function
		X cvw = 0; //current vw
		if (vw != 0) {
			do {
				//random wall starter position
				X x = rand() % (map.size() - 1);
				X y = rand() % (map[0].size() - 1);
				X vos = x + wallLength; // vertical wall oversize
				if (vos > map.size()) { //checking
					continue; //vertical wall cannot be outsize of maze
				}
				else {
					for (X j = 0; j < wallLength; j++) {
						if (map[x + j][y] == valid) {
							break;
						}
					}
					for (X k = 0; k < wallLength; k++) {
						map[x + k][y] = valid;
					}
				}
				++cvw; //increase vw each time create a vertical wall
			} while (cvw < vw);
		}

		X chw = 0; //current hw
		if (hw != 0) {
			do {
				//random wall starter position
				X x = rand() % (map.size() - 1);
				X y = rand() % (map[0].size() - 1);
				X hos = y + wallLength; // horizontal wall oversize
				if (hos > map.size()) { //checking
					continue; //horizontal wall cannot be outsize of maze
				}
				else {
					for (X j = 0; j < wallLength; j++) {
						if (map[x][y + j] == valid) {
							break;
						}
					}
					for (X k = 0; k < wallLength; k++) {
						map[x][y + k] = valid;
					}
				}
				++chw; //increase hw each time create a horizontal wall
			} while (chw < vw);
		}

		//generate exit poX
		srand(time(NULL));
		for (X i = 0; i < row; i++) {
			for (X j = 0; j < col; j++) {
				X x = rand() % (row - 1);
				X y = rand() % (col - 1);
				if (map[x][y] != true) {
					map[x][y] = 2;
					//std::cout << "Exit at x = " << x << ", y = " << y << std::endl << std::endl;
					break;
				}
			}
			break;
		}
	}

	friend class robot;
};

#endif

