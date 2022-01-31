//Name:		Andrew Meyers
//WiscID:	ajmeyers4
//Class:	CS 368
//Assignment:	2

// This is the main File for Assignment2.  It handles all user input
//  and prints the corresponding output to the console.  Most of the 
//  printing is handled by functions definted in 
//  menus.h and initialized in menus.cpp.

#include "menus.h"
#include <iostream>
#include <string> 
#include <ios>
#include <limits>

using namespace std;

/**
 * Clears the users view
 */
void clearMenu() {

    cout << string( 100, '\n' );
}


/*
 * The main funciton handles all user input
 *  and processing. The printing functions implemented
 *  in menus.cpp are utalized in this function.
 */
int main() {
    int inputNum;
    string locationsParam[] = {"Kohl Center, Gate C", "Dejope Hall, 1165", "21 N Park St, 1106", 
	"Shell, 110", "Mechanical Engineering Building, 1184"};
    string symptomsParam[] = {"Fever", "Cough", "Shortness of breath", 
	"Loss of taste or smell", "Fatigue", "Sore throat"};
    char temp = 't';

    // Loops until the user opts to exit the main-menu
    do {
	
	// Repeatedly prints the main-menu 
	//  and gets user input until valid input is received
	do {

            clearMenu();
	    printMainMenu();

	    cin >> inputNum;

	    // Reprints the main-menu if the input is of wrong type
	    //  and reprompts the user
	    while (cin.fail()) {
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');

	        clearMenu();
		printMainMenu();
	        cin >> inputNum;
	    }

	} while ((inputNum < 1) || (3 < inputNum));

	
	clearMenu();
	

	// Selects what menu to continue to
	switch (inputNum) {

	    // Switch to Testing Locations Menu
	    case 1 :
	
		// Loops until 6 is entered to exit locations-menu
		do {

		    // Repeatedly prints the testing locations menu
		    //  and gets user input until valid input is received
		    do {

			clearMenu();
		        printTestingLocations(locationsParam, 5);

		        cin >> inputNum;

		        // Reprints the testing locations menu if the input is of wrong type
                        //  and reprompts the user
                        while (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            clearMenu();
                            printTestingLocations(locationsParam, 5);
                            cin >> inputNum;
                        }

		     } while ((inputNum < 1) || (6 < inputNum));

		    clearMenu();

		    // Prints info for Kohl Center location
		    if (inputNum == 1) {

			printDetails("Kohl Center, Gate C", "601 W Dayton St", "8:30am-4:30pm");
		    }
		    // Prints info for Dejope location
		    else if (inputNum == 2) {

			printDetails("Dejope Hall, 1165", "640 Elm Dr", "9:30am-5:30pm");
		    }
		    // Prints info for N Park location
		    else if (inputNum == 3) {

			printDetails("21 N Park St, 1106", "21 N Park St", "7:30am-3:30pm");
		    }
		    // Prints info for Shell location
		    else if (inputNum == 4) {

			printDetails("Shell, 110", "1430 Monroe St", "8:30am-4:30pm");
		    }
		    // Prints info for Mechanical Engineering location
		    else if (inputNum == 5) {

			printDetails("Mechanical Engineering Building, 1184", "1513 University Ave", "6:30am-2:30pm");
		    }


		    // Returns to previous menu when enter is pressed
		    if (inputNum != 6) { 
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		        temp = 't';
			while (temp != '\n') {
			    cin.get(temp);
			}
		    }

		    clearMenu();

		} while (inputNum != 6);

		// Returns to main-menu
		clearMenu();
	        printMainMenu();
	        break;

	    // User selected symptoms menu
	    case 2:

		bool presentSymptoms[6] = {false};

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

			// Waits for user to press enter to return to main menu
			cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        temp = 't';
                        while (temp != '\n') {
                            cin.get(temp);
                        }
		    }
		} while (inputNum != 8);
	        
		// Returns to main-menu
		clearMenu();
		printMainMenu();
	        break;
	}
    } while (inputNum != 3);
}
