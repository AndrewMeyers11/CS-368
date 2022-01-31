//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   5

// This source file implements all of the functions of Position declared in Position.h

#include "Position.h"
#include <iostream>
#include <math.h>


Position::Position(float init_x, float init_y) {

	x = init_x;
	y = init_y;
}


float Position::operator-(const Position other) {

	return sqrt(((x - other.x) * (x - other.x)) + ((y - other.y) * (y - other.y)));
}


void Position::Read(std::istream& s) {

	s >> x;
	s >> y;
}