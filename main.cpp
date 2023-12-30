//  Project 1 - DNA Profiling
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ourvector.h"
using namespace std;
// struct Person consists of name and an ourvector of STRs data
struct Person {
	string name;
	ourvector<int> numSTRs;
};
/* openFile() : this function open 'filename' (database/ DNA) file,
** and check for its validity */
bool openFile(ifstream& inFile, string& filename) {
	// open file
	inFile.open(filename);
	// check if file is valid
	if (!inFile.is_open()) {
		cout << "Error: unable to open '" << filename << "'" << endl;
		return false;
	} else {
		return true;
	}
}
/* loadSTRs() : this function extracts STRs in the database
** and load them into ourvector STRs */
void loadSTRs(ifstream& inFile, ourvector<ourvector<char>>& STRs) {
	// create stringstream s and load it with "raw" STRs line of names
	string line;
	getline(inFile, line);
	stringstream s(line.substr(5));
	// separate each STR
	ourvector<char> foo;
	while (!s.eof()) {
		string data;
		getline(s, data, ',');
		// load each STR into ourvector STRs as ourvectors
		if (data != "") {
			stringstream letters(data);
			while (!letters.eof()) {
				foo.push_back(letters.get());
			}
			STRs.push_back(foo);
			foo.clear();
		}
	}
}
/* loadPerson() : this function extracts each person data (name and
** amount of each STR) and load them into ourvector listOfPerson */
void loadPerson(ifstream& inFile, ourvector<Person>& listOfPerson) {
	string line;
	Person onePerson;
	// get each person "raw" line data
	while (!inFile.eof()) {
		getline(inFile, line);
		if (line != "") {
			stringstream s(line);
			// get name
			getline(s, onePerson.name, ',');
			// get amount of each STR
			while (!s.eof()) {
				getline(s, line, ',');
				onePerson.numSTRs.push_back(stoi(line));
			}
			listOfPerson.push_back(onePerson);
			onePerson.numSTRs.clear();
		}
	}
}
/* loadDNAstream() : this function extracts DNA data
** and load into ourvector DNAstream */
void loadDNAstream(ifstream& inFile, ourvector<char>& DNAstream) {
	char letter;
	while (!inFile.eof()) {
		letter = inFile.get();
		DNAstream.push_back(letter);
	}
}
/* printDatabase() : this function print each person data (name and STRs)
** this function is part of display() != haveDatabase()*/
void printDatabase(ourvector<Person>& listOfPerson) {
	if (listOfPerson.size() != 0) {
		cout << "Database loaded: " << endl;
		for (auto person : listOfPerson) {
			// print name
			cout << person.name;
			// print STRs
			for (auto STR : person.numSTRs) {
				cout << " " << STR;
			}
			cout << endl;
		}
	} else {
		cout << "No database loaded." << endl;
	}
}
/* printDNA() : this function print the DNA stream.
** this function is part of display() != haveDatabase()*/
void printDNA(ourvector<char>& DNAstream) {
	if (DNAstream.size() != 0) {
		cout << "DNA loaded: " << endl;
		for (int i = 0; i < DNAstream.size() - 1; i++) {
			cout << DNAstream.at(i);
		}
		cout << endl;
	} else {
		cout << "No DNA loaded." << endl;
	}
}
/* printProcess() : this function output the STRs count
** processed from DNA stream
** this function is part of display() != haveDatabase()*/
void printProcess(ourvector<ourvector<char>>& STRs, ourvector<int>& max) {
	if (max.size() != 0) {
		cout << "DNA processed, STR counts: " << endl;
		for (int i = 0; i < STRs.size(); i++) {
			for (int j = 0; j < STRs.at(i).size() - 1; j++) {
				cout << STRs.at(i).at(j);
			}
			cout << ": " << max.at(i) << endl;
		}
		cout << endl;
	} else {
		cout << "No DNA has been processed." << endl;
	}
}
/* haveDatabase() : this function check if there is
** any database input, made for process(),
** NEED to be different from search() because of passing parameters*/
bool haveDatabase(ourvector<ourvector<char>>& STRs,
	ourvector<char>& DNAstream) {
	if (STRs.size() == 0) {
		cout << "No database loaded." << endl;
		return false;
	} else if (DNAstream.size() == 0) {
		cout << "No DNA loaded." << endl;
		return false;
	}
	return true;
}
/* haveDatabase() : this function check if there is
** any database input, made for search() */
bool haveDatabase(ourvector<Person>& listOfPerson,
	ourvector<int>& max, ourvector<char>& DNAstream) {
	if (listOfPerson.size() == 0) {
		cout << "No database loaded." << endl;
		return false;
	} else if (DNAstream.size() == 0) {
		cout << "No DNA loaded." << endl;
		return false;
	} else if (max.size() == 0) {
		cout << "No DNA processed." << endl;
		return false;
	}
	return true;
}
// load_db() Milestone #1 – Load in the database – load_db
void load_db(string& filename, ourvector<Person>& listOfPerson,
	ourvector<ourvector<char>>& STRs, ourvector<int>& max) {
	// generate ifstream variable
	ifstream inFile;
	// open and check if the file is valid
	cout << "Loading database..." << endl;
	if (!openFile(inFile, filename)) return;
	// now that file is open
	// wipe all related ourvector
	listOfPerson.clear();
	STRs.clear();
	max.clear();
	// extract data to ourvector<ourvector<char>> STRs
	loadSTRs(inFile, STRs);
	// extract each Person data
	loadPerson(inFile, listOfPerson);
	inFile.close();
}
// load_dna() Milestone #3 – Load in the dna – load_dna
void load_dna(string& filename, ourvector<char>& DNAstream,
	ourvector<int>& max) {
	// generate ifstream variable
	ifstream inFile;
	// open and check if the file is valid
	cout << "Loading DNA..." << endl;
	if (!openFile(inFile, filename)) return;
	// now that DNA file is open
	// wipe DNAstream ourvector
	DNAstream.clear();
	max.clear();
	// extract DNA stream to ourvector DNAstream
	loadDNAstream(inFile, DNAstream);
	inFile.close();
}
// display() Milestone #2 – Display your data -- display
void display(ourvector<Person>& listOfPerson, ourvector<char>& DNAstream,
	ourvector<ourvector<char>>& STRs, ourvector<int>& max) {
	// printDatabase
	printDatabase(listOfPerson);
	cout << endl;
	// printDNA
	printDNA(DNAstream);
	cout << endl;
	// printProcess
	printProcess(STRs, max);
}
// process() Milestone #4 – Process the DNA – process
void process(ourvector<ourvector<char>>& STRs,
	ourvector<char>& DNAstream, ourvector<int>& max) {
	if (!haveDatabase(STRs, DNAstream)) return;
	cout << "Processing DNA..." << endl;
	// variables to keep track of consecutive sequence of repeated STR
	int index = 0;
	int count = 0;
	max.clear();
	// initialize index, count, max. sizes of whom equal size of ourvector STRs
	for (int i = 0; i < STRs.size(); i++) {
		max.push_back(0);
	}
	// check for sequence of STR, also keep counting consecutive repeated sequence
	for (int j = 0; j < STRs.size(); j++) {
		for (int i = 0; i < DNAstream.size(); i++) {
			if (count != 0 && DNAstream.at(i) != STRs.at(j).at(index)) count = 0;
			if (DNAstream.at(i) == STRs.at(j).at(index)) {
				index++;
			} else {
				i = i - index;
				index = 0;
			}
			if (index == STRs.at(j).size() - 1) {
				count++;
				if (max.at(j) < count) max.at(j) = count;
				index = 0;
			}
		}
	}
}
// search() Milestone #5 – Search the database– search
void search(ourvector<int>& max, ourvector<Person>& listOfPerson,
	ourvector<char>& DNAstream) {
	if (!haveDatabase(listOfPerson, max, DNAstream)) return;
	cout << "Searching database..." << endl;
	bool found = false;
	ourvector<int> result;
	// assume all people are match
	for (int i = 0; i < listOfPerson.size(); i++) {
		result.push_back(1);
	}
	// "unmatch" if found having different STRs data
	for (int i =0; i < listOfPerson.size(); i++) {
		for (int j = 0; j < max.size(); j++) {
			if (max.at(j) != listOfPerson.at(i).numSTRs.at(j)) {
				result.at(i) = 0;
				break;
			}
		}
	}
	// print all matches (there could be more than one, yeah?)
	for (int i = 0; i < result.size(); i++) {
		if (result.at(i) == 1) {
			cout << "Found in database!  DNA matches: ";
			cout << listOfPerson.at(i).name << endl;
			found = true;
		}
	}
	if (found == false) {
		cout << "Not found in database." << endl;
	}
}
// reset() this function wipe every date storage
void reset(ourvector<Person>& listOfPerson, ourvector<ourvector<char>>& STRs,
	ourvector<char>& DNAstream, ourvector<int>& maxSRTSequence) {
		listOfPerson.clear();
		STRs.clear();
		DNAstream.clear();
		maxSRTSequence.clear();
		cout << "reset complete" << endl;
	}
// // // // // // // // // // // // // // // // // // //
int main() {
	// list of variables
	ourvector<Person> listOfPerson;
	ourvector<ourvector<char>> STRs;
	ourvector<char> DNAstream;
	ourvector<int> maxSRTSequence;
	// Greetings
	cout << "Welcome to the DNA Profiling Application." << endl;
	// Command loop
	string command = " ";
	while (command != "#") {
		cout << "Enter command or # to exit: ";
		cin >> command;
		// load_db
		if (command == "load_db") {
			cin >> command;
			load_db(command, listOfPerson, STRs, maxSRTSequence);
		}
		// display
		if (command == "display") {
			display(listOfPerson, DNAstream, STRs, maxSRTSequence);
		}
		// load_dna
		if (command == "load_dna") {
			cin >> command;
			load_dna(command, DNAstream, maxSRTSequence);
		}
		// process
		if (command == "process") {
			process(STRs, DNAstream, maxSRTSequence);
		}
		// search
		if (command == "search") {
			search(maxSRTSequence, listOfPerson, DNAstream);
		}
		// reset, wipe everything and start program as new
		if (command == "reset") {
			reset(listOfPerson, STRs, DNAstream, maxSRTSequence);
		}
	}
	return 0;
}
