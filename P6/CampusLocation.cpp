//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   6

// This source file implements all of the functions of CampusLocation declared in CampusLocation.h

#include "Location.h"
#include "CampusLocation.h"
#include <iostream>
#include <string>


CampusLocation::CampusLocation() : Location() {}

bool CampusLocation::Reserve() {

	return false;
}

void CampusLocation::Cancel() {}

void CampusLocation::Print() const {

	std::cout << "*** On-Campus ***" << std::endl;
	std::cout << "Location:             " << name << std::endl;
	std::cout << "Address:              " << address << std::endl;
	std::cout << "Hours:                " << hours << std::endl;
	std::cout << "Reservations:         " << availableReservations << std::endl;
	std::cout << "Position:              (" << position.GetX() << "," << position.GetY() << ")" << std::endl;
}

void CampusLocation::Read(std::istream& s) {

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
	std::getline(s, tempY);

	position = Position((std::stof(tempX)), (std::stof(tempY)));
}

void CampusLocation::Write(std::ostream& s) const {

	s << "campuslocation" << std::endl;
	s << name << ", ";
	s << address << ", ";
	s << hours << ", ";
	s << position.GetX() << ", ";
	s << position.GetY() << std::endl;
}