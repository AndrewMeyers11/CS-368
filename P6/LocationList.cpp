//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   6

// This source file implements all of the functions of LocationList declared in LocationList.h

#include "LocationList.h"
#include "Location.h"
#include "CampusLocation.h"
#include "CityLocation.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

LocationList::~LocationList() {

	// Deletes data of each Location
	for (size_t i = 0; i < locVec.size(); i++) {

		delete(locVec.at(i));
		locVec.at(i) = nullptr;
	}

	locVec.clear();
	locVec.shrink_to_fit();
}

int LocationList::GetCount() const {

	return locVec.size();
}

Location* LocationList::GetLocation(int index) const {

	return locVec.at(index);
}

void LocationList::AddLocation(Location* new_loc) {

	locVec.emplace_back(new_loc);
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
			locVec.at(i)->Read(inputFile);
		}

	}

	inputFile.close();
}

void LocationList::ToFile(std::string fname) {

	std::ofstream writeFile;
	writeFile.open(fname);

	writeFile << locVec.size() << std::endl;

	// Writes each Locations data to the file
	for (size_t i = 0; i < locVec.size(); i++) {

		locVec.at(i)->Write(writeFile);
	}

	writeFile.close();
}

int LocationList::getNumReservableLocations() const {

	int numReservable = 0;

	for (size_t i = 0; i < locVec.size(); i++) {

		if (locVec.at(i)->IsReservable()) {

			numReservable++;
		}
	}

	return numReservable;
}

void LocationList::clearLocations() {

	locVec.clear();
}

void LocationList::Sort(Position P) {

	Closer closerObj = Closer(P);

	std::sort(locVec.begin(), locVec.end(), closerObj);
}
