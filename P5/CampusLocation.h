//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   5

#include "Location.h"

#ifndef CAMPUS_LOCATION_H
#define CAMPUS_LOCATION_H

/**
 * This sub-class of Location represents a on-campus testing Location.
 *  There are functions to read and write data to passed streams.
 */
class CampusLocation : public Location {

public:

	/**
	* Defined default constructor.  Constructs a new instance
	*  of CampusLocation and calls defined default constructor of Location
	*/
	CampusLocation();

	/**
	* Always returns false because CampusLocations are not reservable
	*
	* @returns false always
	*/
	bool Reserve();

	/**
	* Does nothing because CampusLocations are not reservable
	*/
	void Cancel();

	/**
	* Prints information about CampusLocation instance to the console
	*/
	void Print() const;

	/**
	* Reads CampusLocation data from a passed stream to initialize data of CampusLocation instance
	*
	* @param s - the input stream to read data from
	*/
	void Read(std::istream& s);

	/**
	* Writes CampusLocation data to a passed stream
	*
	* @param s - the output stream to write data to
	*/
	void Write(std::ostream& o) const;
};
#endif