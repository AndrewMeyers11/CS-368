//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   3

#include <string>

#ifndef LOCATION_H
#define LOCATION_H

/**
 * This class represents a Testing Location.
 *  There are functions for accessing data and printing it
 *  in a formatted manner.
 */
class Location {

private:
	std::string name;
	std::string address;
	std::string hours;
	bool allowReservations;

public:

    /**
     * Default constructor for Location.  Constructs a 
     *  new Location instance.
     */
    Location();

	/**
     * Parameterized constructor for Location. 
     *  Constructs a new Location instance.
     *
     * @param name is the name of the new Location
	 * @param address is the address of the new Location
     * @param hours is the hours of the new Locaiton
     * @param allowReservations is the Reservation allowance of the new Location
     */
	Location(std::string name, std::string address, std::string hours, bool allowReservations);

	/**
     * Copy constructor for Location.  Constructs 
     *  a new Location instance from a previous one.
     *
     * @param locationP is the location to be copied from
     */
	Location(const Location&);

	/**
     * Getter function for allowReservations.  Used to determine the
     *  reservability of Location instance.
     *
     * @returns true when function is reservable, false otherwise
     */
	bool IsReservable() const;

    /**
     * Getter function for name. Used to access the name
     *  of Location instance.
     *
     * @returns the name of Location instance
     */
	std::string to_string() const;

    /**
     * Printing function used to output all information
     *  about Location instance to console
     */
	void Print() const;

    /**
     * Getter function used to access a Locations address
     * 
     * @returns the address of Location instance
     */
    std::string getAddress() const;
};

#endif