//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   3

#include "Location.h"
#include <string>

#ifndef LOCATION_LIST_H
#define LOCATION_LIST_H

/**
 * This class represents a list of Locations.
 *  Basic list functions and growablity
 *  are availible via this list class.
 */
class LocationList {

private:
	Location* locations;
	int numLocations;
	int arraySize;

	/**
	 * Increases the size of the array by a factor of 2
	 */
	void grow();

public:

	/**
	 * Defined default constructor.  Creates 
	 *  a new locationList instance and sets the
	 *  size to 8 by default
	 */
	LocationList();

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
	 * @returns the Location from the specified index
	 */
	Location GetLocation(int index) const;

	/**
	 * Adds a location to the LocationList
	 * 
	 * @param new_loc - The Location to be added
	 */
	void AddLocation(const Location& new_loc);

	/**
	 * Gets the indeces of the all reservable locations
	 * 
	 * @returns an int array of the indeces of reservable locations
	 */
	int* getReservableIndeces();
};
#endif
