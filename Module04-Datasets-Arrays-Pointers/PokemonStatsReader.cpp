#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    fstream pokemonFile("pokemon_complete_stats.csv");

    string names[9];
    string primaryType[9];
    string secondaryType[9];

    string header;
    getline(pokemonFile, header); // Skips header

    // Loop through first 9 pokemon data and store in arrays
    for (int i = 0; i < 9; i++) {
        string id, name, height, weight, exp, type1, type2, rest;

        // Read each line of the CSV file and store the values in the respective arrays
        // Useless values will be read to temporary variables and discarded
        getline(pokemonFile, id, ',');
        getline(pokemonFile, names[i], ',');
        getline(pokemonFile, height, ',');
        getline(pokemonFile, weight, ',');
        getline(pokemonFile, exp, ',');
        getline(pokemonFile, primaryType[i], ',');
        getline(pokemonFile, secondaryType[i], ',');
        if (secondaryType[i] == "") {
            secondaryType[i] = "None"; // Replace "None" with "N/A"
        }
        getline(pokemonFile, rest); // Read and discard the rest of the line

    }

    cout << "1. Bulbasaur\n";
    cout << "2. Ivysaur\n";
    cout << "3. Venusaur\n";
    cout << "4. Charmander\n";
    cout << "5. Charmeleon\n";
    cout << "6. Charizard\n";
    cout << "7. Squirtle\n";
    cout << "8. Wartortle\n";
    cout << "9. Blastoise\n\n";

    int record;
    int field;

    cout << "Enter the record number of the pokemon you'd like to view(1-9): ";
    cin >> record;

    while(record < 1 || record > 9) {
        cout << "Invalid record number. Please enter a number between 1 and 9.\n";
        cout << "Enter the record number of the pokemon you'd like to view (1-9): ";
        cin >> record;
    }

    string* ptrNames = names;
    string* ptrPrimaryType = primaryType;
    string* ptrSecondaryType = secondaryType;

    cout << "\nPokemon Name: " << ptrNames[record - 1] << endl;
    cout << "Primary Type: " << ptrPrimaryType[record - 1] << endl;
    cout << "Secondary Type: " << ptrSecondaryType[record - 1] << endl;

}