//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   3

// This source file implements all of the functions of LocationList defined in LocationList.h

#include "LocationList.h"
#include "Location.h"
#include <string>

using namespace std;

/**
 * Defined default constructor.  Creates
 *  a new locationList instance and sets the
 *  size to 8 by default
 */
LocationList::LocationList() {

	arraySize = 8;
	numLocations = 0;
	locations = new Location[8];
}

/**
 * Deconstructor used to deallocate memory
 *  that was used for dynamic array of locations
 */
LocationList::~LocationList() {

	delete[] locations;
	locations = nullptr;
}

/**
 * Getter function for the total number of
 *  Locations currently in LocationList instance
 *
 * @returns the total number of Locations in the LocationList
 */
int LocationList::GetCount() const {

	return numLocations;
}

/**
 * Gets a specified location from the LocationList
 *
 * @param index - the index of the Location to be returned
 * @returns the Location from the specified index
 */
Location LocationList::GetLocation(int index) const {

	return locations[index];
}

/**
 * Adds a location to the LocationList
 *
 * @param new_loc - The Location to be added
 */
void LocationList::AddLocation(const Location& new_loc) {
	
	// Grows the array if it is full
	if (numLocations == arraySize) {
		grow();
	}

	// Adds the new location
	locations[numLocations] = Location(new_loc);
	numLocations++;
}

/**
 * Increases the size of the array by a factor of 2
 */
void LocationList::grow() {

	// Creates a new a heap array larger than locations and
	//  copies all locations into the new locations.
	Location* bigList = new Location[arraySize * 2];

	// Loops through all Locations
	for (int i = 0; i < arraySize; i++) {

		bigList[i] = Location(locations[i]);
	}

	// Deallocates old(small) list
	delete[](locations);

	// Switches locations pointer to the new(big) list
	locations = bigList;
	bigList = nullptr;

	// Updates arraySize to the new arraySize
	arraySize = arraySize * 2;
}