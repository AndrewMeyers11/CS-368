//Name:		Andrew Meyers
//WiscID:	ajmeyers4
//Class:	CS 368
//Assignment:	2

// This Header File defines all of the menu printing functions

#include <string>

#ifndef PRINT_MAIN_MENU
#define PRINT_MAIN_MENU
void printMainMenu();
#endif

#ifndef PRINT_TESTING_LOCATIONS
#define PRINT_TESTING_LOCATIONS
void printTestingLocations(std::string locations[], int count);
#endif

#ifndef PRINT_DETAILS
#define PRINT_DETIALS
void printDetails(std::string name, std::string address, std::string hours);
#endif

#ifndef PRINT_SYMPTOM_CHECKER
#define PRINT_SYMPTOM_CHECKER
void printSymptomChecker(std::string symptoms[], bool selected[]);
#endif
