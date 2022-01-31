//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   5

// This source file implements all of the functions of CityLocation declared in CityLocation.h

#include "Location.h"
#include "CityLocation.h"
#include <iostream>
#include <string>


CityLocation::CityLocation() : Location() {

	maxReservations = 0;
}

CityLocation::CityLocation(std::string nameP, std::string addressP, std::string hoursP, int reservation)
	: Location(nameP, addressP, hoursP, reservation) {

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
}

void CityLocation::Read(std::istream& s) {

	s.get();
	std::getline(s, name, ',');
	s.get();
	std::getline(s, address, ',');
	s.get();
	std::getline(s, hours, ',');
	s.get();
	s >> availableReservations;
}

void CityLocation::Write(std::ostream& s) const {

	s << "citylocation" << std::endl;
	s << name << ", ";
	s << address << ", ";
	s << hours << ", ";
	s << availableReservations << std::endl;
}