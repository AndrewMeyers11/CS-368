//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   3

#include "Menus.h"
#include "User.h"
#include "Location.h"
#include "LocationList.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * The main function handles all user input and uses
 *  the Menu, User, Location, and LocationList clases to
 *  make the porgram more object oriented(more abstraction) than previous implementations.
 */
int main() {

	int inputNum;
	string inputString;
	float inputFloat;

	LocationList allLocations = LocationList();
	User user = User();

	bool imperial = true;
	bool presentSymptoms[6] = { false };
	bool locationAdded = false;

	// Fills in allLocations with each Locations data
	allLocations.AddLocation(Location("Kohl Center, Gate C", "601 W Dayton St", "8:30am-4:30pm", true));
	allLocations.AddLocation(Location("Dejope Hall, 1165", "640 Elm Dr", "9:30am-5:30pm", true));
	allLocations.AddLocation(Location("21 N Park St, 1106", "21 N Park St", "7:30am-3:30pm", false));
	allLocations.AddLocation(Location("Shell, 110", "1430 Monroe St", "8:30am-4:30pm", false));
	allLocations.AddLocation(Location("Mechanical Engineering Building, 1184", "1513 University Ave", "6:30am-2:30pm", true));

	string symptomsParam[] = { "Fever", "Cough", "Shortness of breath", "Loss of taste or smell", "Fatigue", "Sore throat" };

	// Loops until the user opts to exit the main-menu
	do {

		clearMenu();
		printMainMenu();

		// Gets an int from the user in range of the main-menu
		inputNum = getIntInputRange(1, 8);
		clearMenu();

		// Switch to Testing Locations Menu
		switch (inputNum) {

		// View Testing Locations Menu
		case 1:

			// Loops until 6 is entered to exit locations-menu
			do {

				printTestingLocations(allLocations);
				inputNum = getIntInputRange(1, 6);
				clearMenu();

				// Prints locations info and waits for user to press enter
				//  to return to locations menu
				if (inputNum != 6) {

					allLocations.GetLocation(inputNum - 1).Print();
					cout << "Press enter to return to locations menu" << endl;

					// Returns to previous menu when enter is pressed
					waitForEnter();
				}

				clearMenu();
			} while (inputNum != 6);

			inputNum = 0;
			break;

			// Make test Reservation Menu
		case 2:

			// Loops until user opts to exit make reservations menu
			do {

				// Prints all reservable locations
				printReservationLocations(allLocations);

				// Prompts user for input of correct type
				inputNum = getIntInputRange(0, 6);

				// Loops until input Num is valid
				while ((inputNum == 2) || (inputNum == 3)) {

					cout << "invalid input, please try again" << endl;
					inputNum = getIntInputRange(0, 6);
				}

				// Adds location to reservations if user is not exiting
				if (inputNum != 6) {

					user.MakeReservation(allLocations.GetLocation(inputNum));
					clearMenu();
					cout << "Reservation successfully made!" << endl;
				}
			} while (inputNum != 6);

			inputNum = 0;
			break;

			// Use Symptom Checker Menu
		case 3:

			// Resets all symptoms to not present
			for (int i = 0; i < 6; i++) {

				presentSymptoms[i] = false;
			}

			do {

				// Loops until the user selects to exit the menu
				do {

					clearMenu();
					printSymptomChecker(symptomsParam, presentSymptoms);

					cin >> inputNum;

					// Reprints the symptoms menu if the input is of wrong type
					//  and reprompts the user
					while (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						clearMenu();
						printSymptomChecker(symptomsParam, presentSymptoms);
						cin >> inputNum;
					}

				} while ((inputNum < 1) || (8 < inputNum));

				// Fever selected
				if (inputNum == 1) {

					// Selects/deselects fever
					if (!presentSymptoms[0]) {

						presentSymptoms[0] = true;
					}
					else {

						presentSymptoms[0] = false;
					}
				}
				// Cough selected
				else if (inputNum == 2) {

					// Selects/deselects Cough
					if (!presentSymptoms[1]) {

						presentSymptoms[1] = true;
					}
					else {
						presentSymptoms[1] = false;
					}
				}
				// Shortness of breath selected
				else if (inputNum == 3) {

					// Selects/deselects Shortness of breath
					if (!presentSymptoms[2]) {

						presentSymptoms[2] = true;
					}
					else {

						presentSymptoms[2] = false;
					}
				}
				// Loss of taste or smell selected
				else if (inputNum == 4) {

					// Selects/deselects Loss of taste of smell
					if (!presentSymptoms[3]) {

						presentSymptoms[3] = true;
					}
					else {

						presentSymptoms[3] = false;
					}
				}
				// Fatigue selected
				else if (inputNum == 5) {

					// Selects/deselects Shortness Fatigue
					if (!presentSymptoms[4]) {

						presentSymptoms[4] = true;
					}
					else {

						presentSymptoms[4] = false;
					}
				}
				// Sore throat selected
				else if (inputNum == 6) {

					// Selects/deselects Shortness of breath
					if (!presentSymptoms[5]) {

						presentSymptoms[5] = true;
					}
					else {

						presentSymptoms[5] = false;
					}
				}

				clearMenu();

				// Submit symptoms selected
				if (inputNum == 7) {

					// Gets total present symptoms
					int totSymptoms = 0;
					for (int i = 0; i < 6; i++) {

						if (presentSymptoms[i]) {
							totSymptoms++;
						}
					}

					// No symptoms selected
					if (totSymptoms == 0) {

						cout << "You seem to be feeling fine. Remember to test regularly for Covid-19." << endl;
					}
					// One or two symptoms selected
					else if ((totSymptoms == 1) || (totSymptoms == 2)) {

						cout << "Please stay home and monitor your symptoms. If your symptoms persist" <<
							" or you develop new symptoms, please go to an available testing site to be tested for Covid-19." << endl;
					}
					// Three or more symptoms selected
					if (totSymptoms > 2) {

						cout << "Please go to an available testing site to be tested for Covid-19." << endl;
					}

					cout << "Press enter to return to main menu." << endl;

					inputNum = 8;
					waitForEnter();
				}
			} while (inputNum != 8);

			// Returns to main-menu
			inputNum = 0;
			break;

			// View my Reservations menu
		case 4:

			// Prints users reservations
			user.PrintReservations();

			// Waits for user to press enter to return
			waitForEnter();

			inputNum = 0;
			break;

			// View my Personal Data menu
		case 5:

			// Prints out user data menu
			user.PrintData();
			waitForEnter();

			inputNum = 0;
			break;

			// Adjust Personal Data Menu
		case 6:

			// Loops unitl the user exits the data-modification menu
			do {

				// Prints the data modification menu
				cout << "Set your personal data:" << endl;
				cout << "[1] First name (" << user.getFirstName() << ")" << endl;
				cout << "[2] Last name (" << user.getLastName() << ")" << endl;
				cout << "[3] Age (" << user.getAge() << ")" << endl;

				if (imperial) {
					cout << "[4] Height (" << user.getHeight() << " ft)" << endl;
					cout << "[5] Weight (" << user.getWeight() << " lbs)" << endl;
				}
				else {
					cout << "[4] Height (" << user.getHeight() << " m)" << endl;
					cout << "[5] Weight (" << user.getWeight() << " kg)" << endl;
				}

				cout << "[6] Return to main menu" << endl;

				// Gets menu option input from user
				inputNum = getIntInputRange(1, 6);

				switch (inputNum) {

					// Modify first name 
				case 1:

					// Gets name from user and updates user data
					cout << "Please enter your first name:" << endl;
					cin >> inputString;
					user.setFirstName(inputString);
					inputNum = 0;
					break;

					// Modify last name
				case 2:

					// Gets name from user and updates user data
					cout << "Please enter your last name" << endl;
					cin >> inputString;
					user.setLastName(inputString);
					inputNum = 0;
					break;

					// Modify age	   
				case 3:

					// Gets age from user and updates user data
					cout << "Please enter your age" << endl;
					inputNum = getIntInputRange(0, 122);
					user.setAge(inputNum);
					inputNum = 0;
					break;

					// Modify height
				case 4:

					cout << "Please enter your height" << endl;

					// Gets valid imperial height
					if (imperial) {

						inputFloat = getFloatInputRange(0.01, 9.00);
					}
					// Gets valid metric height
					else {

						inputFloat = getFloatInputRange(0.01, 2.75);
					}

					cout << "inputFloat is " << inputFloat << endl;

					// Updates height
					user.setHeight(inputFloat);

					inputNum = 0;
					break;

					// Modify weight
				case 5:

					cout << "Please enter your weight" << endl;

					// Gets valid imperial height
					if (imperial) {

						inputFloat = getFloatInputRange((float)0.01, (float)975.00);
					}
					// Gets valid metric height
					else {

						inputFloat = getFloatInputRange((float)0.01, (float)445.00);
					}

					// Updates height
					user.setWeight(inputFloat);

					inputNum = 0;
					break;
				}

				clearMenu();
			} while (inputNum != 6);

			inputNum = 0;
			break;

			// Settings menu
		case 7:

			do {

				clearMenu();
				printSettingsMenu(!imperial);
				inputNum = getIntInputRange(1, 2);

				// Switches units
				if (inputNum == 1) {

					// Converts height and weight to opposite units
					if (imperial) {

						user.setHeight((float)(user.getHeight() / 3.28));
						user.setWeight((float)(user.getWeight() / 2.20));
					}
					else {

						user.setHeight((float)(user.getHeight() * 3.28));
						user.setWeight((float)(user.getWeight() * 2.20));
					}

					imperial = !imperial;
				}

			} while (inputNum != 2);

			inputNum = 0;
			break;
		}
	} while (inputNum != 8);

	return 0;
}