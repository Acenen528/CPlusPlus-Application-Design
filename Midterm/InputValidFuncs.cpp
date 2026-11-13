#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "InputValidFuncs.h"

using namespace std;

int getPositiveInteger() {
    int num;
    while (true) {
        cin >> num;

        if (cin.fail() || num <= 0) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a positive integer." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any extra input
            return num;
        }
    }
}

string getValidName() {
    string name;
    while (true) {
        getline(cin, name);

        if (name.empty()) {
            cout << "Name cannot be empty. Please enter a valid name." << endl;
        } else if (name.length() > 50) {
            cout << "Name is too long. Please enter a name with 50 characters or fewer." << endl;
        } else if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos) {
            cout << "Name contains invalid characters. Please enter a valid name." << endl;
        } else if (name.find("  ") != string::npos) {
            cout << "Name cannot contain consecutive spaces. Please enter a valid name." << endl;
        } else if (name.front() == ' ' || name.back() == ' ') {
            cout << "Name cannot start or end with a space. Please enter a valid name." << endl;
        } else if (count(name.begin(), name.end(), ' ') > 2) {
            cout << "Name cannot contain more than two spaces." << endl;
        } else {
            return name;
        }
    }
}

string getValidFilename() {
    string filename;
    while (true) {
        getline(cin, filename);

        if (filename.empty()) {
            cout << "Filename cannot be empty. Please try again: ";
        } else if (filename.find_first_of("\\/:*?\"<>|") != string::npos) {
            cout << "Filename contains invalid characters (e.g., \\, /, :, *). Try again: ";
        } else {
            if (!filename.ends_with(".csv")) { 
                filename += ".csv";  
                return filename;
            }
        }
    }
}