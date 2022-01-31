//Name:			Andrew Meyers
//WiscID:		ajmeyers4
//Class:		CS 368
//Assignment:	4

// This Header File defines all of the menu printing functions

#include "Location.h"
#include "LocationList.h"
#include "User.h"
#include <string>

#ifndef MENUS_H
#define MENUS_H

/**
 * Prints the main menu
 */
void printMainMenu();

/**
 * Prints a list of all of the testing locations
 *
 * @param locations - a LocationList of all Locations to be printed
 */
void printTestingLocations(const LocationList& locations);

/**
 * Prints the Symptom Checker menu
 *
 * @param symptoms - String array of possible symptoms
 * @param selected - Bool array parallel to symptoms representing presence of symptoms
 */
void printSymptomChecker(std::string symptoms[], bool selected[]);

/**
 * Prints the passed Users data to the console
 *
 * @param user - the User whos data is to be printed
 */
void printUserDataMenu(const User& user);

/**
 * Prints the Settings menu to the console
 *
 * @param is_metric - true when in metric mode, false when in imperial mode
 */
void printSettingsMenu(const bool is_metric);

/**
 * Prints reservable locations menu to the console
 *
 * @param locations - a LocationList representing all of the reservable Locations
 */
void printReservationLocations(const LocationList& locations);

/**
 * Clears the user views
 */
void clearMenu();

/**
 * Helper function used to retrieve an int from
 *  the user in the passed range(inclusive)
 *
 * @param lowerBound - lower bound of the range(inclusive)
 * @param upperBound - upper bound of the range(inclusive)
 * @returns a valid int passed by the user
 */
int getIntInputRange(int lowerBound, int upperBound);

/**
 * Waits for the user to press enter to continue
 */
void waitForEnter();

/**
 * Helper function used to retrieve a float from
 *  the user in the passed range(inclusive)
 *
 * @param lowerBound - lower bound of the range(inclusive)
 * @param upperBound - upper bound of the range(inclusive)
 * @returns the valid float passed by user
 */
float getFloatInputRange(float lowerBound, float upperBound);

#endif