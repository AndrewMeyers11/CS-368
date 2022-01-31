//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   5

#include "Location.h"
#include <string>
#include <vector>

#ifndef LOCATION_LIST_H
#define LOCATION_LIST_H

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


};
#endif
