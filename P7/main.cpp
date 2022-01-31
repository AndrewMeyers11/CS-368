//Name:         Andrew Meyers
//WiscID:       ajmeyers4
//Class:        CS 368
//Assignment:   7

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

/**
 * The main function handles all of the code for this program.
 *  This program reads from 2 data files to get a message
 *  and swap info.  Swap info is used to decrypt a message from the 
 *  message.  Regex is used for this purpose.
 */
int main() {

	// Reads in the word swaps file(swaps.txt)
	ifstream wordSwapsInputFile;
	wordSwapsInputFile.open("swaps.txt");

	// Exits program with an error message if the wordSwaps file couldnt be opened
	if (!wordSwapsInputFile.is_open()) {

		cout << "The wordSwaps file could not be opened!!!";
		return 1;
	}

	int numSwapPairs;
	wordSwapsInputFile >> numSwapPairs;
	wordSwapsInputFile.get();
	vector<string> swapPairs;
	string searchWord;
	string replaceWord;

	// Loops through all swap pairs in swap file
	//  and adds them to the vector of swap pairs
	for (int i = 0; i < numSwapPairs; i++) {

		getline(wordSwapsInputFile, searchWord, ' ');
		getline(wordSwapsInputFile, replaceWord);

		swapPairs.push_back(searchWord);
		swapPairs.push_back(replaceWord);
	}

	// Reads in the message file(message.txt)
	ifstream messageInputFile;
	messageInputFile.open("message.txt");

	// Exits program with an error message if the message file couldnt be opened
	if (!messageInputFile.is_open()) {

		cout << "The message file could not be opened!!!";
		return 1;
	}

	vector<string> messageVector;
	string messageLine;

	// Loops through each line of the message file
	//  and replaces each search word with its corresponding replace word
	// (1st layer decription)
	while (getline(messageInputFile, messageLine)) {

		// Loops through all message pairs
		for (int i = 0; i < (int)swapPairs.size(); i += 2) {

			regex re(swapPairs.at(i));

			// Makes the swap
			messageLine = regex_replace(messageLine, re, swapPairs.at(i + 1));
		}

		// Adds updated messgage line to the messageVector
		messageVector.push_back(messageLine);
	}

	// Outputs lines of text to be used for layer two
	for (int i = 0; i < (int)messageVector.size(); i++) {
		
		cout << messageVector.at(i) << endl;
	}
	cout << "***" << endl;

	// 2nd layer decription
	//  Loops through all lines of the message and omits them
	//   if their respective head and tag dont match.
	//   Corresponding heads and tags are removed if they match.
	for (int i = 0; i < (int)messageVector.size(); i++) {

		//regex reg("(<(.*?)>)(.*)(<(.*?)>)");
		regex reg("<(.*?)>(.*)<(.*?)>");
		smatch matches;

		regex_search(messageVector.at(i), matches, reg);

		// removes the tags if they match
		if (matches[1].compare(matches[3]) == 0) {

			messageVector.at(i) = matches[2];
		}
		// Deletes line if the tags dont match
		else {

			messageVector.erase(messageVector.begin() + i);
			i--;
		}
	}

	// Outputs the inner text
	for (int i = 0; i < (int)messageVector.size(); i++) {

		cout << messageVector.at(i) << endl;
	}
	cout << "***" << endl;

	string finalOutput;

	// Loops through the remaining inner text lines to get the
	//  final output based off the length of each line
	for (int i = 0; i < (int)messageVector.size(); i++) {

		int lineLength = messageVector.at(i).length();

		// Adds a space if the line is 27 characters long
		if (lineLength == 27) {

			finalOutput += " ";
		}
		// Adds 96 to the lineLength to link this projects specification to ASCII values
		else {

			char intToChar = lineLength + 96;
			string addOnString(1, intToChar);
			finalOutput += addOnString;
		}
	}

	// Outputs the final message
	cout << finalOutput;

	return 0;
}