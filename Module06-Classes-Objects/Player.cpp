#include <iostream>
#include <string>
using namespace std;

class Player {
private: 
    string name;
    int level; // Player's level
    int skillPoints; // Number of skill points available to allocate

    // Stats in order: Vitality, Strength, Agility, Intelligence, Sense
    int stats[5] = {10, 10, 10, 10, 10}; // Initialize stats array

public:
    // Constructor to initialize the player's name and level
    Player(string name, int level) {
        this->name = name;
        this->level = level;
        this->skillPoints = level * 3; // Skill points based on level
    }

    // Function to allocate skill points to a specific stat
    string addSkillPoints(string stat, int points) {
        if (skillPoints < points) {
            return "Not enough skill points available.";
        }

        if (stat == "Vit" || stat == "vit") {
            stats[0] += points;
        } else if (stat == "Str" || stat == "str") {
            stats[1] += points;
        } else if (stat == "Agil" || stat == "agil") {
            stats[2] += points;
        } else if (stat == "Int" || stat == "int") {
            stats[3] += points;
        } else if (stat == "Sen" || stat == "sen") {
            stats[4] += points;
        } else {
            return "Invalid stat name.";
        }

        skillPoints -= points;
        return "Skill points allocated successfully.";
    }

    // Getter function to access private member variables
    string getName() {
        return name;
    }

    string getStats() {
        return "Vitality: " + to_string(stats[0]) + "\nStrength: " + to_string(stats[1]) + "\nAgility: " + to_string(stats[2]) + 
                "\nIntelligence: " + to_string(stats[3]) + "\nSense: " + to_string(stats[4]);
    }

    int getSkillPoints() {
        return skillPoints;
    }

    int getLevel() {
        return level;
    }

    // Function that displays all player information in a formatted manner
    void displayPlayerInfo() {
        cout << "Player Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Skill Points Available: " << skillPoints << endl;
        cout << getStats() << endl;
    }

    // Setter functions to update player info
    void setName(string name) {
        this->name = name;
    }
    
    void setLevel(int level) {
        this->level = level;
        // Resets skill points based on new level
        skillPoints = level * 3; // Update skill points based on new level

        // Reset stats to default values when level is changed
        stats[0] = 10;
        stats[1] = 10;
        stats[2] = 10;
        stats[3] = 10;
        stats[4] = 10;
    }

};

int main() {
    // Create a Player object
    Player player("Sung Jinwoo", 5);

    // Display initial player info
    player.displayPlayerInfo();
    cout << endl;

    // Allocate skill points to a stat
    cout << player.addSkillPoints("Str", 5) << endl;

    // Display updated player info
    player.displayPlayerInfo();

    return 0;
}