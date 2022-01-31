//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   6

#include "Location.h"
#include <string>
#include <vector>

#ifndef LOCATION_LIST_H
#define LOCATION_LIST_H

/** Functor Class used to calculate the proximity of Locations to a position */
class Closer {

private:
	Position posVariable;

public:
	/**
	* Parameterized constructor for Closer.  Sets 
	*/
	Closer(Position p) {
		posVariable = p;
	}

	/**
	* Opator overload for () used to compare the two passed Positions
	*  to posVariable
	* 
	* @param a - First Location to check distance between itself and posVariable
	* @parm b - Second Location to check distance between itself and posVariable
	* @returns true when a is closer to posVariable than b
	*/
	bool operator()(Location* a, Location* b) {

		if ((*a - posVariable) < (*b - posVariable)) {

			return true;
		}
		else {

			return false;
		}
	}
};


/**
 * This class represents a list of Locations.
 *  Basic list functions and growablity
 *  are availible via this list class.
 */
class LocationList {

private:
	std::vector<Location*> locVec;

public:

	/**
	 * Deconstructor used to deallocate memory
	 *  that was used for dynamic array of locations
	 */
	~LocationList();

	/**
	 * Getter function for the total number of
	 *  Locations currently in LocationList instance
	 *
	 * @returns the total number of Locations in the LocationList
	 */
	int GetCount() const;

	/**
	 * Gets a specified location from the LocationList
	 *
	 * @param index - the index of the Location to be returned
	 * @returns a pointer to the specified Location
	 */
	Location* GetLocation(int index) const;

	/**
	 * Adds a location to the LocationList
	 *
	 * @param new_loc - Pointer to the Location to be added
	 */
	void AddLocation(Location* new_loc);

	/**
	* Opens a filestream to read Locations data from a file
	*  with the passed name
	*
	* @param fname - the name of the file to be opened
	*/
	void FromFile(std::string fname);

	/**
	* Opens a filestream and writes to a file with the passed name
	*
	* @param fname - the name of the file to be written to
	*/
	void ToFile(std::string fname);

	/**
	* Gets the number of reservable locations(CityLocations)
	*
	* @returns the number of reservable locations(CityLocations)
	*/
	int getNumReservableLocations() const;

	/**
	* Clears the LocationList
	*/
	void clearLocations();

	/**
	* Sorts the Vector of Locations of this LocationList instance by proximity
	* 
	* @param p - a Position instance 
	*/
	void Sort(Position P);
};
#endif
