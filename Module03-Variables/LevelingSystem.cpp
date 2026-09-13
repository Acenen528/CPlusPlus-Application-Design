#include <iostream>
#include <string>
using namespace std;

main() {

    //System version
    float version = 1.0f;

    // Basic player data
    string name = "Allen";
    char gender = 'M';
    int level = 1;
    bool canAdvanceClass = false; // Determines if the player can advance to a new class

    // Player stats 
    double str = 10.0; // Strength increases physical damage
    double agi = 10.0; // Agility affects critical chance
    double vit = 10.0; // Vitality influences health
    double intel = 10.0; // Intelligence affects magic damage
    double sen = 10.0; // Sense affects evasion and accuracy

    cout << "_____THE SYSTEM_____" << endl;
    cout << "SYSTEM VERSION: " << version << "\n\n";

    cout << "_____PLAYER DATA_____" << endl;
    cout << "Player Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Level: " << level << endl; 
    cout << "Can Advance Class: ";

    if (canAdvanceClass) 
        cout << "Yes\n\n";
    else 
        cout << "No\n\n";


    cout << "_____PLAYER STATS_____" << endl;
    cout << "Strength: " << str << endl;
    cout << "Agility: " << agi << endl;
    cout << "Vitality: " << vit << endl;
    cout << "Intelligence: " << intel << endl;
    cout << "Sense: " << sen << endl;

    return 0;
}