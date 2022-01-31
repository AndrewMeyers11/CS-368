//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   3

// This source file implements all of the functions of User defined in User.h

#include "User.h"
#include "LocationList.h"
#include "Location.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * Default constructor used to initialize all user
 *  data to its empty equivalent. Constructs a new User instance.
 */
User::User() {

	firstName = "";
	lastName = "";
	age = 0;
	height = 0.0;
	weight = 0.0;
}

/**
 * Adds a new location to the list of reservations of
 *  this Users data.
 *
 * @param new_reservation - The location to be reserved.
 */
void User::MakeReservation(const Location& new_reservation) {            // BUG HERE LOCATIONS NOT INITIALIZED CORRECTLY

	// Adds passed location to reservationsList
	reservationsList.AddLocation(new_reservation);
}

/**
 * Prints out the users full name to the console
 */
void User::to_string() {
	
	cout << firstName << " " << lastName << endl;
}

/**
 * Prints all of the users data to the console
 */
void User::PrintData() const {

	cout << "Your data:" << endl;
	cout << "First name:    " << firstName << endl;
	cout << "Last name:     " << lastName << endl;
	cout << "Age:           " << age << endl;
	cout << "Height:        " << height << endl;
	cout << "Weight:        " << weight << endl;
	cout << "Return to main menu" << endl;
	cout << "Press enter to return to menu." << endl;
}

/**
 * Prints all of the locations reserved by this User
 *  and the corresponding data of each.
 */
void User::PrintReservations() {

	cout << "Here are your reservations:" << endl;

	// Loops through all resrvations in resrvationsList
	for (int i = 0; i < reservationsList.GetCount(); i++) {

		reservationsList.GetLocation(i).Print();
		cout << endl;
	}

	cout << "Press enter to return" << endl;
}

/**
 * Getter function for first name
 *
 * @returns first name of user instance
 */
string User::getFirstName() const {

	return firstName;
}

/**
 * Getter function for last name
 *
 * @returns last name of user instance
 */
string User::getLastName() const {
	
	return lastName;
}

/**
 * Getter function for age
 *
 * @returns age of user instance
 */
int User::getAge() const {

	return age;
}

/**
 * Getter function for height
 *
 * @returns height of user instance
 */
float User::getHeight() const {

	return height;
}

/**
 * Getter function for weight
 *
 * @returns weight of user instance
 */
float User::getWeight() const {

	return weight;
}

/**
 * Setter function for first name
 *
 * @param the new first name
 */
void User::setFirstName(std::string firstNameP) {

	firstName = firstNameP;
}

/**
 * Setter function for last name
 *
 * @param the new last name
 */
void User::setLastName(std::string lastNameP) {

	lastName = lastNameP;
}

/**
 * Setter function for age
 *
 * @the new age
 */
void User::setAge(int ageP) {

	age = ageP;
}

/**
 * Setter function for height
 *
 * @param the new height
 */
void User::setHeight(float heightP) {

	height = heightP;
}

/**
 * Setter function for weight
 *
 * @param the new weight
 */
void User::setWeight(float weightP) {

	weight = weightP;
}

/**
 * Getter function for reservations
 *
 * @returns the reservation list of user instance
 */
LocationList User::getReservations() {

	return reservationsList;
}