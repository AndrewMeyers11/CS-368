//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   4

// This source file implements all of the functions of LocationList declared in LocationList.h

#include "LocationList.h"
#include "Location.h"
#include "CampusLocation.h"
#include "CityLocation.h"
#include <string>
#include <fstream>

using namespace std;

LocationList::LocationList() {

	arraySize = 8;
	numLocations = 0;
	locations = new Location*[arraySize];
}

LocationList::~LocationList() {

	// Deletes data of each Location
	for (int i = 0; i < numLocations; i++) {

		delete(locations[i]);
	}
	delete[] locations;
	locations = nullptr;
}

int LocationList::GetCount() const {

	return numLocations;
}

Location* LocationList::GetLocation(int index) const {

	return locations[index];
}

void LocationList::AddLocation(Location* new_loc) {

	// Grows the array if it is full
	if (numLocations == arraySize) {
		grow();
	}

	// Adds the new location
	locations[numLocations] = new_loc;
	numLocations++;
}

void LocationList::grow() {

	// Creates a new a heap array larger than locations and
	//  copies all locations into the new locations.
	Location** bigList = new Location*[arraySize * 2];

	// Makes bigList point to all corresponding contents of locations
	for (int i = 0; i < arraySize; i++) {

		bigList[i] = locations[i];
	}

	// Switches locations pointer to the new(big) list
	locations = bigList;
	bigList = nullptr;

	// Updates arraySize to the new arraySize
	arraySize = arraySize * 2;
}

void LocationList::FromFile(std::string fname) {

	int numFileLocations;
	string locationType;

	std::ifstream inputFile;
	inputFile.open(fname);

	inputFile >> numFileLocations;

	// Loops through each Location input in the file
	for (int i = 0; i < numFileLocations; i++) {

		inputFile >> locationType;

		// Input is for CityLocation
		if ((locationType.compare("citylocation")) == 0) {

			// Creates a new pointer to a CityLocation and adds it the list of Locations
			Location* locationToBeAdded = new CityLocation();
			AddLocation(locationToBeAdded);
			locationToBeAdded->Read(inputFile);
		}
		// Input is for CampusLocation
		else {

			// Creates a new pointer to a CampusLocation and adds it the list of Locations
			Location* locationToBeAdded = new CampusLocation();
			AddLocation(locationToBeAdded);
			locations[i]->Read(inputFile);
		}

	}

	inputFile.close();
}

void LocationList::ToFile(std::string fname) {

	std::ofstream writeFile;
	writeFile.open(fname);

	writeFile << numLocations << std::endl;

	// Writes each Locations data to the file
	for (int i = 0; i < numLocations; i++) {

		locations[i]->Write(writeFile);
	}

	writeFile.close();
}

int LocationList::getNumReservableLocations() const {

	int numReservable = 0;

	for (int i = 0; i < numLocations; i++) {

		if (locations[i]->IsReservable()) {

			numReservable++;
		}
	}

	return numReservable;
}

/**
* Clears the LocationList
*/
void LocationList::clearLocations(){

	for (int i = 0; i < numLocations; i++) {

		delete(locations[i]);
	}

	numLocations = 0;
}
