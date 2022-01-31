//Name:		Andrew Meyers
//WiscID:	ajmeyers4
//Class:	CS 368
//Assignment:	1

#include <iostream>

using namespace std;

/*
 * The main function holds all of the code for the program.
 * This program using a terminal interface to mock some of
 *  the features of the Safer Badgers Application.
 */
int main() {

    // Input tracking variables
    int inputNum;
    double inputDecimal;
    string inputString;
    bool inputValid = false;

    // Unit-mode tracking variable
    bool imperial = true;;

    // User-data tracking variables
    string firstName = "";
    string lastName = "";
    int age = 0;
    double heightFeet = 0;
    double heightMeters = 0; 
    double weightPounds = 0; 
    double weightKilograms = 0;

    // Loops until the user exits the main menu
    do {
        // Prints main menu
        cout << "Welcome to Safe-ish Badgers!" << endl;
        cout << "[1] View my personal data" << endl;
        cout << "[2] Adjust my personal data" << endl;
        cout << "[3] Change settings" << endl;
        cout << "[4] Exit program" << endl;

    	// Gets input from user
    	cout << "Please enter a menu item:" << endl;
    	cin >> inputNum;


	// Clears the users view of the ouput terminal
	cout << string( 100, '\n' );

	// Checks input
    	switch(inputNum) {

            // View my personal data ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    case 1 :		
		// Prints personal data menu
		cout << "Your data:" << endl;

		cout << "Name:   ";
		if (!firstName.empty()) {
		    cout << firstName << " " << lastName;
		}
		cout << endl;

                cout << "Age:    ";
		if (age != 0) {
		    cout << age;
		}
		cout << endl;

		cout << "Height: ";
		if (heightFeet != 0) {
		    if (imperial) { 
		        cout << heightFeet << " (ft)";
		    } 
		    else {
			cout << heightMeters << " (m)";
		    }
		}
		cout << endl;

		cout << "Weight: ";
		if (weightPounds != 0) {
		    if (imperial) {
			cout << weightPounds << " (lbs)";
		    }
		    else {
			cout << weightKilograms << " (kg)";
		    }
		}
		cout << endl;

		// Exits the user-data menu any number is inputed  
		cout << "Enter any number to return to menu." << endl;
		cin >> inputNum;

		// Prevents exiting the main menu
		if (inputNum == 4) {
		    inputNum = 0;
		}
	    	break;


	    // Adjust my personal data /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 2 :
	    
	       // Loops unitl the user exits the data-modification menu
	       do {

	           // Prints the data modification menu
		   cout << "Set your personal data:" << endl;
	           cout << "[1] First name (" << firstName << ")" << endl;
	           cout << "[2] Last name (" << lastName << ")" << endl;
	           cout << "[3] Age (" << age << ")" << endl;
		   
	           if (imperial) {
	               cout << "[4] Height (" << heightFeet << " ft)" << endl;
	               cout << "[5] Weight (" << weightPounds << " lbs)" << endl;
		   }
                   else {
                       cout << "[4] Height (" << heightMeters << " m)" << endl;
                       cout << "[5] Weight (" << weightKilograms << " kg)" << endl;
		   }	

		   cout << "[6] Return to main menu" << endl;

		   // Gets menu option input from user
		   cout << "Please enter a menu item:" << endl;
		   cin >> inputNum;

		   switch (inputNum) {
			
		       // Modify first name 
		       case 1:

			   // Gets name from user and updates user data
			   cout << "Please enter your first name:" << endl;
			   cin >> firstName;
		           break;

		       // Modify last name
		       case 2:

			   // Gets name from user and updates user data
			   cout << "Please enter your last name" << endl;
			   cin >> lastName;
			   break;

		       // Modify age	   
		       case 3:
			
			   inputValid = false;

			   // Loops until a valid age has been entered
			   do {

			       cout << "Please enter your age" << endl;
	                       cin >> inputNum;
                         
			       // Checks the validity of the passed age
			       if ((inputNum >= 0) && (inputNum <= 122)) {
			           age = inputNum;
				   inputValid = true; 
			       }

			       // Prevents exiting the data modification menu
			       if (inputNum == 6) {
                                   inputNum = 0;
                               }

			   } while (!inputValid);
			   break;
                           
		       // Modify height
		       case 4:
			   inputValid = false;

                           // Loops until a valid height has been entered
                           do {

                               cout << "Please enter your height" << endl;
                               cin >> inputDecimal;

                               // Checks the validity of the passed height
			       if (imperial && (inputDecimal > 0) && (inputDecimal <= 9)) {   

			           heightFeet = inputDecimal;
                                   heightMeters = heightFeet / 3.28;
				   inputValid = true;
			       }
			       else if ((inputDecimal > 0) && (inputDecimal <= 2.75)){
			           heightMeters = inputDecimal;
				   heightFeet = heightMeters * 3.28;
				   inputValid = true;
		               }
                               
			       // Prevents exiting the data modification menu
                               if (inputNum == 6) {
                                   inputNum = 0;
                               }

                           } while (!inputValid);
                           break;

		       // Modify weight
		       case 5:
			   inputValid = false;

                           // Loops until a valid height has been entered
                           do {

                               cout << "Please enter your weight" << endl;
                               cin >> inputDecimal;

                               // Checks the validity of the passed weight
                               if (imperial && (inputDecimal > 0) && (inputDecimal <= 975)) {

                                   weightPounds = inputDecimal;
                                   weightKilograms = weightPounds / 2.20;
                                   inputValid = true;
                               }
                               else if ((inputDecimal > 0) && (inputDecimal <= 445)){
                                   weightKilograms = inputDecimal;
                                   weightPounds = weightKilograms * 2.20;
                                   inputValid = true;
                               }

			       // Prevents exiting the data modification menu
			       if (inputNum == 6) {
                                   inputNum = 0;
                               }
                                   
                           } while (!inputValid);
                           break;
		   }

	           // Clears the users view of the ouput terminal
		   cout << string( 100, '\n' );
	       } while (inputNum != 6);	       
		break;
        

            // Change settings /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 	    case 3 :

	       // Loops until the user exits the settings-menu
	       do {

		  // Prints the settings menu
                  cout << "Change your app settings:" << endl; 

		  if (imperial) {
	            
                      cout << "[1] Switch units (imperial)" << endl;
		  }
		  else {

                      cout << "[1] Switch units (metric)" << endl;
		  }

		  cout << "[2] Return to main menu" << endl;

		  // Takes user input
		  cout << "Please enter a menu item:" << endl;
		  cin >> inputNum;

		  // Switches units
		  if (inputNum == 1) {
		
		      imperial = !imperial;	  
                  }

		  // Clears the users view of the ouput terminal
                  cout << string( 100, '\n' );

	       } while (inputNum != 2);
	       break;
	}


        // Clears the users view of the output terminal
	cout << string( 100, '\n' );	
    } while (inputNum != 4); 
}
