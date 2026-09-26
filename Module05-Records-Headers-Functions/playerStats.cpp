#include <iostream>
#include "playerStats.h"

using namespace std;

string addSkillPoints(int stats[], string stat, int points, int *skillPoints) {
    if (*skillPoints < points) {
        return "Not enough skill points available.";
    }
    
    if (stat == "Vitality" || stat == "vitality") {
        stats[0] += points;
    } else if (stat == "Strength" || stat == "strength") {
        stats[1] += points;
    } else if (stat == "Agility" || stat == "agility") {
        stats[2] += points;
    } else if (stat == "Intelligence" || stat == "intelligence") {
        stats[3] += points;
    } else if (stat == "Sense" || stat == "sense") {
        stats[4] += points;
    } else {
        return "Invalid stat name.";
    }

    *skillPoints -= points;
    return "Skill points added successfully.";
}

void displayStats(int stats[], int skillPoints) {

    cout << "\n#####STATS#####" << endl;
    cout << "Vitality: " << stats[0] << endl;
    cout << "Strength: " << stats[1] << endl;
    cout << "Agility: " << stats[2] << endl;
    cout << "Intelligence: " << stats[3] << endl;
    cout << "Sense: " << stats[4] << "\n" << endl;
}
