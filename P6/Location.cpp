//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   6

// This source file implements all of the functions of Location defined in Location.h

#include "Location.h"
#include <string>
#include <iostream>

using namespace std;

Location::Location() {

	name = "";
	address = "";
	hours = "";
	availableReservations = 0;
}


Location::Location(string nameP, string addressP, string hoursP, float xP, float yP, int reservation) {

	name = nameP;
	address = addressP;
	hours = hoursP;
	position = Position(xP, yP);
	availableReservations = reservation;
}


Location::Location(const Location& locationP) {

	name = locationP.name;
	address = locationP.address;
	hours = locationP.hours;
	availableReservations = locationP.availableReservations;
}


bool Location::IsReservable() const {

	// Returns true if there are one or more reservations availble
	//  false if otherwise
	if (availableReservations > 0) {

		return true;
	}
	return false;
}

string Location::to_string() const {

	return name;
}


std::string Location::getAddress() const {

	return address;
}


std::string Location::getName() const {

	return name;
}


std::string Location::getHours() const {

	return hours;
}
int Location::getAvailableReservations() const {

	return availableReservations;
}

float Location::operator-(const Position other) {

	return position - other;
}

Position Location::getPosition() {

	return position;
}