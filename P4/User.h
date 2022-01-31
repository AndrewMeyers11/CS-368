//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   4

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
	std::string user_filename;
	std::string reservations_filename;

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
	 * @param new_reservation - Pointer to the location to be reserved.
	 */
	void MakeReservation(Location* new_reservation);

	/**
	 * Prints out the users full name to the console
	 */
	void to_string();

	/**
	 * Prints all of the users data to the console
	 * 
	 * @param isImperial specifies the units, default is imperial
	 */
	void PrintData(bool isImperial = true) const;

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

	/**
	* Reads User data through a file stream made from the passed filename
	* 
	* @param is_imperial - true when the Users data is in imperial mode
	* @param fname - the name of the file to be opened
	*/
	void Read(bool& is_imperial, std::string fname = "");

	/**
	* Writes User data through a file stream made from user_filename
	* 
	* @param is_imperial - true when the Users data is in imperial mode
	*/
	void Write(const bool is_imperial);
};
#endif