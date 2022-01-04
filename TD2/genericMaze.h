#ifndef GENERICMAZE_
#define GENERICMAZE_

#include <vector>
#include <iostream>

class robot;

template <class X>

class maze {
protected:
	X row, col; // row and column
	std::vector<std::vector<X>> map; //use vector of vector to contain maze info
	std::vector<robot*> rblist; //list of robot

public:
	//contructor
	maze() {

	}
	maze(X row, X col, std::vector<robot*> rblist) {
		this->row = row;
		this->col = col;
		this->rblist = rblist;
	}

	//destructor
	~maze() {

	}

	//getters
	X getRow() const {
		return this->row;
	}
	X getCol() const {
		return this->col;
	}
	std::vector<robot*> getRblist() const {
		return this->rblist;
	}

	//setter
	void setRow(X row) {
		this->row = row;
	}
	void setCol(X col) {
		this->col = col;
	}
	void setRblist(std::vector<robot*> rblist) {
		this->rblist = rblist;
	}

	virtual void mazeStructure() {
		std::vector<std::vector<X>> map(row, std::vector<X>(col, 0));
		this->map = map;
	} //create maze
	virtual void generateWall() {

	} //generate wall
	virtual void display() {
		char dot = '.';
		char plus = '+';
		char x = 'x';

		for (auto i : map) {
			for (int j : i) {
				if (j == 0) {
					std::cout << dot << " ";
				}
				else if (j == 1) {
					std::cout << plus << " ";
				}
				else if (j == 2) {
					std::cout << x << " ";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	} //display

	friend class robot;
};

#endif
