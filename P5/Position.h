//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   5

#include <iostream>

#ifndef POSITION_H
#define POSITION_H

/**
 * This class represents the position of a user
 */
class Position {

private:
	float x;
	float y;

public:
	/**
	* Constructs a new position using the passed coordinates
	*  or defaults to the position (0, 0)
	* 
	* @param init_x - the x position of the Position to be constructed
	* @param init_y - the y position of the Position to be constructed
	*/
	Position(float init_x = 0.0, float init_y = 0.0);

	/**
	* Overload of the - operator used to get the distance
	*  between two Positions
	* 
	* @param other - The other Position used to cacluate the distance
	* @returns a float representing the Euclidean distance between the two Positions
	*/
	float operator-(const Position other);

	/**
	* Reads in position data from the passed stream
	* 
	* @param s - the input stream to read data from
	*/
	void Read(std::istream& s);
};
#endif
