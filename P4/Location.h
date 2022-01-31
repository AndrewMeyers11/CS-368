//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   4

#include <string>

#ifndef LOCATION_H
#define LOCATION_H

/**
 * This class represents a Testing Location.
 *  There are functions for accessing data and printing it
 *  in a formatted manner.
 */
class Location {

protected:
    std::string name;
    std::string address;
    std::string hours;
    int availableReservations;

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
     * @param reservation is the amount of reservations available
     */
    Location(std::string name, std::string address, std::string hours, int reservation);

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
     * Pure virtual printing function used to output all information
     *  about Location instance to console
     */
    virtual void Print() const = 0;

    /**
     * Getter function used to access a Locations address
     *
     * @returns the address of Location instance
     */
    std::string getAddress() const;

    /**
    * Pure virtual reader function used to read Location data from a file
    * 
    * @param s - an input stream used to read from a data file
    */
    virtual void Read(std::istream& s) = 0;

    /**
    * Pure virtual writer function used to write Location data to a file
    * 
    * @param s - an output stream used to write to a data file
    */
    virtual void Write(std::ostream& s) const = 0;

    /**
    * Pure virtual function used to reserve appointments at Location
    * 
    * @returns true when the reservation was successful, false otherwise
    */
    virtual bool Reserve() = 0;

    /**
    * Pure virtual function used to cancel location appointment
    */
    virtual void Cancel() = 0;

    /**
    * Getter function for name
    * 
    * @returns name of Location instance
    */
    std::string getName() const;

    /**
    * Getter function for hours
    *
    * @returns hours of Location instance
    */
    std::string getHours() const;

    /**
    * Getter function for number of available reservations
    *
    * @returns number of available reservations at Location instance
    */
    int getAvailableReservations() const;
};
#endif