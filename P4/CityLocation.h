//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   4

#include "Location.h"

#ifndef CITY_LOCATION_H
#define CITY_LOCATION_H

/**
 * This sub-class of Location represents a (off-campus)city testing Location.
 *  There are functions to read and write data to passed streams.
 */
class CityLocation : public Location {

private:
	int maxReservations;

public:
	/**
	* Defined default constructor.  Constructs a new instance
	*  of CityLocation and calls defined default constructor of Location
	*/
	CityLocation();

	/**
	* CityLocation Constructor used to initialize a new CityLocation with passed parameters
	* 
	* @param nameP - name of new CityLocation
	* @param addressP - address of new CityLocation
	* @param hoursP - hours of new CityLocation
	* @param reservation - numReservations available for new CityLocation
	*/
	CityLocation(std::string nameP, std::string addressP, std::string hoursP, int reservation);

	/**
	* Reserves a location by Decrementing available locations counter when there is availablity.
	*  Doesn't modify counter if it is already zero.
	* 
	* @returns true when the location is successfully reserved, false otherwise
	*/
	bool Reserve();

	/**
	* Cancels a reservation by incrementing available locations counter
	*  Ensures there are not more locations available than the original maximum.
	*/
	void Cancel();

	/**
	* Prints information about CityLocation instance to the console
	*/
	void Print() const;

	/**
	* Reads CityLocation data from a passed stream to initialize data of CityLocation instance
	* 
	* @param s - the input stream to read data from
	*/
	void Read(std::istream& s);

	/**
	* Writes CityLocation data to a passed stream
	* 
	* @param s - the output stream to write data to
	*/
	void Write(std::ostream& o) const;
};
#endif