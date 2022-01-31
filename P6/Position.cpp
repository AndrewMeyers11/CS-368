//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   6

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

Position Position::operator+(Position that) {

	Position resultPosition = Position((x + that.x), (y + that.y));
	return resultPosition;
}

Position Position::operator/(float denominator) {

	Position resultPosition = Position((x / denominator), (y / denominator));
	return resultPosition;
}

void Position::Read(std::istream& s) {

	s >> x;
	s >> y;
}

float Position::GetX() const {

	return x;
}

float Position::GetY() const {

	return y;
}