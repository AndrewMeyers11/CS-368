//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   3

// This source file implements all of the functions of Location defined in Location.h

#include "Location.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * Default constructor for Location.  Constructs a
 *  new Location instance.
 */
Location::Location() {

	name = "";
	address = "";
	hours = "";
	allowReservations = false;
}


/**
 * Parameterized constructor for Location
 * 
 * @param nameP is the name of the new Location
 * @param addressP is the address of the new Location
 * @param hoursP is the hours of the new Locaiton
 * @param allowReservationsP is the Reservation allowance of the new Location
 * @returns a new Location
 */
Location::Location(string nameP, string addressP, string hoursP, bool allowReservationsP) {

	name = nameP;
	address = addressP;
	hours = hoursP;
	allowReservations = allowReservationsP;
}

/**
 * Copy constructor for Location
 *
 * @param locationP is the location to be copied from
 * @returns a new Location
 */
Location::Location(const Location& locationP) {

	name = locationP.name;
	address = locationP.address;
	hours = locationP.hours;
	allowReservations = locationP.allowReservations;
}


/**
 * Getter function for allowReservations.  Used to determine the 
 *  reservability of Location instance.
 *
 * @returns true when function is rerservable, false otherwise
 */
bool Location::IsReservable() const { 
	
	return allowReservations;
}

/**
 * Get er function for name. Used to access the name
 *  of Location instance.
 *
 * @returns the name of Location instance
 */
string Location::to_string() const { 

	return name;
}

/**
 * Printing function used to output all information
 *  about Location instance to console
 */
void Location::Print() const {

	cout << "Location:            " << name << endl;
	cout << "Address:             " << address << endl;
	cout << "Hours:               " << hours << endl;
	
	if (allowReservations) {

		cout << "Allows Reservations: Yes" << endl;
	}
	else {

		cout << "Allows Reservations: No" << endl;
	}
}

/**
 * Getter function used to access a Locations address
 *
 * @returns the address of Location instance
 */
std::string Location::getAddress() const {

	return address;
}