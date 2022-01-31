//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   6

// This source file implements all of the functions of CityLocation declared in CityLocation.h

#include "Location.h"
#include "CityLocation.h"
#include <iostream>
#include <string>


CityLocation::CityLocation() : Location() {

	maxReservations = 0;
}

CityLocation::CityLocation(std::string nameP, std::string addressP, std::string hoursP, float xP, float yP, int reservation)
	: Location(nameP, addressP, hoursP, xP, yP, reservation) {

	maxReservations = 0;
}

bool CityLocation::Reserve() {

	// Returns true when there are available reservations
	if (availableReservations != 0) {

		availableReservations--;
		return true;
	}
	// Retruns false when there are no available locations
	else {

		return false;
	}
}

void CityLocation::Cancel() {

	// Increments the availableReservations counter if it is not at max capacity
	if (availableReservations < maxReservations) {

		availableReservations++;
	}
}

void CityLocation::Print() const {

	std::cout << "*** Off-Campus ***" << std::endl;
	std::cout << "Location:             " << name << std::endl;
	std::cout << "Address:              " << address << std::endl;
	std::cout << "Hours:                " << hours << std::endl;
	std::cout << "Reservations:         " << availableReservations << std::endl;
	std::cout << "Position:              (" << position.GetX() << "," << position.GetY() << ")" << std::endl;
}

void CityLocation::Read(std::istream& s) {
	
	std::string tempX;
	std::string tempY;

	s.get();
	std::getline(s, name, ',');
	s.get();
	std::getline(s, address, ',');
	s.get();
	std::getline(s, hours, ',');
	s.get();
	std::getline(s, tempX, ',');
	s.get();
	std::getline(s, tempY, ',');
	s.get();
	s >> availableReservations;

	position = Position((std::stof(tempX)), (std::stof(tempY)));
}

void CityLocation::Write(std::ostream& s) const {

	s << "citylocation" << std::endl;
	s << name << ", ";
	s << address << ", ";
	s << hours << ", ";
	s << position.GetX() << ", ";
	s << position.GetY() << ", ";
	s << availableReservations << std::endl;
}