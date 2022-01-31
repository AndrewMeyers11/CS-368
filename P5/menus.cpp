//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   5

// This file is used to initialize and implement all of 
// the menu printing functions declared in menus.h

#include "Menus.h"
#include "User.h"
#include "Location.h"
#include "LocationList.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Prints the main menu
 */
void printMainMenu() {

    cout << "Welcome (back) to Safe-ish Badgers!" << endl;
    cout << "[1] View testing locations" << endl;
    cout << "[2] Make test reservation" << endl;
    cout << "[3] Use symptom checker" << endl;
    cout << "[4] Check for Covid-19 Exposures" << endl;
    cout << "[5] View my reservations" << endl;
    cout << "[6] View my personal data" << endl;
    cout << "[7] Adjust my personal data" << endl;
    cout << "[8] Change settings" << endl;
    cout << "[9] Exit program" << endl;
    cout << "Please enter a menu item:" << endl;
}

/**
 * Prints a list of all of the testing locations
 *
 * @param locations - a LocationList of all Locations to be printed
 */
void printTestingLocations(const LocationList& locations) {

    cout << "Testing Locations:" << endl;

    // Loops through all passed Locations
    for (int i = 0; i < locations.GetCount(); i++) {
        cout << "[" << (i + 1) << "] ";
        cout << locations.GetLocation(i)->to_string() << endl;
    }

    cout << "[" << (locations.GetCount() + 1) << "] " << "Return to main menu" << endl;
    cout << "Choose a location for more information, or return to the menu:" << endl;
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

/**
 * Prints the passed Users data to the console
 *
 * @param user - the User whos data is to be printed
 */
void printUserDataMenu(const User& user) {

    cout << "Set your personal data:" << endl;
    cout << "[1] First name (" << user.getFirstName() << ")" << endl;
    cout << "[2] Lirst name (" << user.getLastName() << ")" << endl;
    cout << "[3] Age (" << user.getAge() << ")" << endl;
    cout << "[4] Height (" << user.getHeight() << ")" << endl;
    cout << "[5] Weight (" << user.getWeight() << ")" << endl;
    cout << "[6] Return to main menu" << endl;
    cout << "Please enter a menu item" << endl;
}

/**
 * Prints the Settings menu to the console
 *
 * @param is_metric - true when in metric mode, false when in imperial mode
 */
void printSettingsMenu(const bool is_metric) {

    cout << "Change your app settings:" << endl;

    if (is_metric) {
        cout << "[1] Switch units (metric)" << endl;
    }
    else {

        cout << "[1] Switch units (imperial)" << endl;
    }

    cout << "[2] Load Data" << endl;
    cout << "[3] Save Data" << endl;

    cout << "[4] Return to main menu" << endl;
    cout << "Please enter a menu item:" << endl;
}

/**
 * Prints reservable locations menu to the console
 *
 * @param locations - a LocationList representing all of the reservable Locations
 */
void printReservationLocations(const LocationList& locations) {

    cout << "Testing Locations:" << endl;

    // Loops through all locations
    for (int i = 0; i < locations.GetCount(); i++) {

        // Prints location if it is reservable
        if (locations.GetLocation(i)->IsReservable()) {
            cout << "[" << i << "] " << locations.GetLocation(i)->to_string() << endl;
        }
    }

    cout << "[" << locations.GetCount() << "] Return to main menu" << endl;
    cout << "Choose a location to reserve, or return to main menu" << endl;
}

/**
 * Clears the users view
 */
void clearMenu() {

    cout << string(100, '\n');
}

/**
 * Helper function used to retrieve an int from
 *  the user in the passed range(inclusive)
 *
 * @param lowerBound - lower bound of the range(inclusive)
 * @param upperBound - upper bound of the range(inclusive)
 * @returns the valid int passed by user
 */
int getIntInputRange(int lowerBound, int upperBound) {

    int inputNum;

    // Reprompts user until valid input is received
    do {
        cin >> inputNum;

        // Prompts user for input of correct type
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input of wrong type, please try again" << endl;
            cin >> inputNum;
        }

        // Prompts user for an int in the passed range
        if ((inputNum < lowerBound) || (upperBound < inputNum)) {

            cout << "Input out of range, please try again" << endl;
        }

    } while ((inputNum < lowerBound) || (upperBound < inputNum));

    return inputNum;
}

/**
 * Helper function used to retrieve a float from
 *  the user in the passed range(inclusive)
 *
 * @param lowerBound - lower bound of the range(inclusive)
 * @param upperBound - upper bound of the range(inclusive)
 * @returns the valid float passed by user
 */
float getFloatInputRange(float lowerBound, float upperBound) {

    double inputNum;

    // Reprompts user until valid input is received
    do {
        cin >> inputNum;

        // Prompts user for input of correct type
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input of wrong type, please try again" << endl;
            cin >> inputNum;
        }

        // Prompts user for an int in the passed range
        if ((inputNum < lowerBound) || (upperBound < inputNum)) {

            cout << "Input out of range, please try again" << endl;
        }

    } while ((inputNum < lowerBound) || (upperBound < inputNum));

    return (float)inputNum;
}

/**
 * Waits for the user to press enter to continue
 */
void waitForEnter() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char temp = 't';

    while (temp != '\n') {
        cin.get(temp);
    }
}
