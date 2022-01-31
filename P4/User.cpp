//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   4

// This source file implements all of the functions of User declared in User.h

#include "User.h"
#include "LocationList.h"
#include "Location.h"
#include "CityLocation.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


User::User() {

	firstName = "";
	lastName = "";
	age = 0;
	height = 0.0;
	weight = 0.0;
	user_filename = "default.txt";
	reservations_filename = "default_reservations.txt";
}


void User::MakeReservation(Location* new_reservation) {        

	// Makes a deep copy of the passed reservation to avoid double deletion of pointers
	//  upon call of deconstructor at the end of the program
	Location* reservationCopy = new CityLocation(new_reservation->getName(), new_reservation->getAddress(),
		new_reservation->getHours(), new_reservation->getAvailableReservations());

	// Adds passed location to reservationsList
	reservationsList.AddLocation(reservationCopy);
}


void User::to_string() {

	cout << firstName << " " << lastName << endl;
}


void User::PrintData(bool isImperial) const {

	cout << "Your data:" << endl;
	cout << "First name:    " << firstName << endl;
	cout << "Last name:     " << lastName << endl;
	cout << "Age:           " << age << endl;

	if (isImperial) {

		cout << "Height:        " << height << " ft" << endl;
		cout << "Weight:        " << weight << " lbs" << endl;
	}
	else {

		cout << "Height:        " << height << " m" << endl;
		cout << "Weight:        " << weight << " kg" << endl;
	}
	
	cout << "Return to main menu" << endl;
	cout << "Press enter to return to menu." << endl;
}


void User::PrintReservations() {

	cout << "Here are your reservations:" << endl;

	// Loops through all resrvations in resrvationsList
	for (int i = 0; i < reservationsList.GetCount(); i++) {

		reservationsList.GetLocation(i)->Print();
		cout << endl;
	}

	cout << "Press enter to return" << endl;
}

string User::getFirstName() const {

	return firstName;
}


string User::getLastName() const {

	return lastName;
}


int User::getAge() const {

	return age;
}


float User::getHeight() const {

	return height;
}


float User::getWeight() const {

	return weight;
}


void User::setFirstName(std::string firstNameP) {

	firstName = firstNameP;
}


void User::setLastName(std::string lastNameP) {

	lastName = lastNameP;

	user_filename = lastName + ".txt";
	reservations_filename = lastName + "_reservations.txt";
}


void User::setAge(int ageP) {

	age = ageP;
}


void User::setHeight(float heightP) {

	height = heightP;
}


void User::setWeight(float weightP) {

	weight = weightP;
}


LocationList User::getReservations() {

	return reservationsList;
}

void User::Read(bool& is_imperial, std::string fname) {

	std::ifstream inputFile;

	// Opens filestream with user_filename when fname is default value
	if (fname.compare("") == 0) {

		inputFile.open(user_filename);
	}
	else {

		// Opens filestream with passed file name
		inputFile.open(fname);
	}

	if (inputFile.is_open()) {

		inputFile >> firstName;
		inputFile >> lastName;

		reservations_filename = lastName + "_reservations.txt";

		inputFile >> age;;
		inputFile >> height;
		inputFile >> weight;
		inputFile >> is_imperial;

		reservationsList.clearLocations();
		reservationsList.FromFile(reservations_filename);

		cout << "Load successful, please continue:" << endl << endl;
	}
	else {

		cout << "Load unsuccessful, file could not be opened. Please try again:" << endl << endl;
	}

	inputFile.close();
}

void User::Write(const bool is_imperial) {

	std::ofstream writeFile;
	writeFile.open(user_filename);

	writeFile << firstName << " ";
	writeFile << lastName << " ";
	writeFile << age << " ";
	writeFile << height << " ";
	writeFile << weight << " ";

	if (is_imperial) {

		writeFile << 1;
	}
	else {

		writeFile << 0;
	}

	reservationsList.ToFile(reservations_filename);
	cout << "Save successful, please enter another menu item:" << endl << endl;

	writeFile.close();
}

