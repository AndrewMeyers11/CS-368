//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   2

// This file is used to initialize and implement all of 
// the menu printing functions defined in menus.h

#include "menus.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Prints the main menu
 */
void printMainMenu() {

    cout << "Welcome (back) to Safe-ish Badgers!" << endl;
    cout << "[1] View testing locations" << endl;
    cout << "[2] Use symptom checker" << endl;
    cout << "[3] Exit program" << endl;
    cout << "Please enter a menu item:" << endl;
}

/**
 * Prints a list of all of the testing locations
 *
 * @param locations - A String array containing each location
 * @param count - The total number of locations
 */
void printTestingLocations(std::string locations[], int count) {

    cout << "Testing Locations:" << endl;

    // Iterates for every testing location
    //  and prints them in menu format
    for (int i = 0; i < count; i++) {
	cout << "[" << (i + 1) << "] " <<  locations[i] << endl;
    }

    cout << "[" << (count + 1) << "] " << "Return to main menu" << endl;
    cout << "Choose a location for more information, or return to the menu:" << endl;
}

/**
 * Prints the details a user selected location
 *
 * @param name - Name of the location
 * @param address - Address of the location
 * @param hours - Hours of the location
 */
void printDetails(std::string name, std::string address, std::string hours) {

    cout << "Location: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Hours: " << hours << endl;
    cout << "Press enter to return to menu." << endl;
}

/**
 * Prints the Symptom Checker menu
 *
 * @param symptoms - String array of possible symptoms
 * @param selected - Bool array parallel to symptoms representing presence of symptoms
 */
void printSymptomChecker(std::string symptoms[], bool selected[]) {

    cout << "Select Your Symptoms:" << endl;

    // Iterates through all symptoms
    //  and prints them in menu format
    for (int i = 0; i < 6; i++) {
	
	// Checks if the symptom is currently selected
	if (selected[i]) {
	
	    cout << "[" << (i + 1) << "*] " << symptoms[i] << endl;
	}
	else {

	    cout << "[" << (i + 1) << "] " << symptoms[i] << endl;
	}
    }

    cout << "[7] Submit Symptoms" << endl;
    cout << "[8] Cancel and return to main menu" << endl;
}
