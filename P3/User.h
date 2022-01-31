//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   3

#include "LocationList.h"
#include "Location.h"
#include <string>

#ifndef USER_H
#define USER_H

/**
 * This class represents a user of the program.
 *  All of the users data is contained in a User instance.
 *  There are also functions for printing user data.
 */
class User {

private:
	std::string firstName;
	std::string lastName;
	int age;
	float height;
	float weight;
	LocationList reservationsList;

public:

	/**
	 * Defined default constructor used to initialize all user
	 *  data to its empty equivalent. Constructs a new User instance.
	 */
	User();

	/**
	 * Adds a new location to the list of reservations of
	 *  this Users data.
	 *
	 * @param new_reservation - The location to be reserved.
	 */
	void MakeReservation(const Location& new_reservation);

	/**
	 * Prints out the users full name to the console
	 */
	void to_string();

	/**
	 * Prints all of the users data to the console
	 */
	void PrintData() const;

	/**
	 * Prints all of the locations reserved by this User
	 *  and the corresponding data of each.
	 */
	void PrintReservations();

	/**
	 * Getter function for first name
	 *
	 * @returns first name of user instance
	 */
	std::string getFirstName() const;

	/**
	 * Getter function for last name
	 *
	 * @returns last name of user instance
	 */
	std::string getLastName() const;

	/**
	 * Getter function for age
	 *
	 * @returns age of user instance
	 */
	int getAge() const;

	/**
	 * Getter function for height
	 * 
	 * @returns height of user instance
 	 */
	float getHeight() const;

	/**
	 * Getter function for weight
	 *
	 * @returns weight of user instance
	 */
	float getWeight() const;

	/**
	 * Setter function for first name
	 *
	 * @param the new first name
	 */
	void setFirstName(std::string firstNameP);

	/**
	 * Setter function for last name
	 *
	 * @param the new last name
	 */
	void setLastName(std::string lastNameP);

	/**
	 * Setter function for age
	 *
	 * @the new age
	 */
	void setAge(int ageP);

	/**
	 * Setter function for height
	 *
	 * @param the new height
	 */
	void setHeight(float heightP);

	/**
	 * Setter function for weight
	 *
	 * @param the new weight
	 */
	 void setWeight(float weightP);

	 /**
	  * Getter function for reservations
	  * 
	  * @returns the reservation list of user instance
	  */
	 LocationList getReservations();
};
#endif