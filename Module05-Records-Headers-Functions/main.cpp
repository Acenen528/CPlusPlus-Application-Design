#include <iostream>
#include "playerStats.h"
using namespace std;

int main() {

    cout << "Welcome to the Player Stats Manager!" << endl;

    //Number of skill points available to allocate
    int skillPoints = 10;

    //Stats in order: Vitality, Strength, Agility, Intelligence, Sense
    int stats[5] = {10, 10, 10, 10, 10}; // Initialize stats array with default values

    while (true) {
        int choice;
        cout << "Please select an option:" << endl;
        cout << "1. Display Stats" << endl;
        cout << "2. Add Skill Points" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                displayStats(stats, skillPoints);
                continue;
            }
            case 2: {
                cout << "Enter the stat to add points to (Vitality, Strength, Agility, Intelligence, Sense): ";
                string stat;
                cin >> stat;
                cout << "Enter the number of points to add (" << skillPoints << " available): ";
                int points;
                cin >> points;
                cout << addSkillPoints(stats, stat, points, &skillPoints) << endl << endl;
                continue;
            }
            case 3: {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                continue;
            }
        }
    }

    return 0;
}