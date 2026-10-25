#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "InputValidFuncs.h"

using namespace std;

class Player {
protected:
    // Player info
    int id;
    string name;
    int level;

    // Stats in order: Vitality, Strength, Agility, Intelligence, Sense
    int stats[5] = {10, 10, 10, 10, 10}; // Initialize stats array with default values

    int skillPoints; // Number of skill points available to allocate
    inline static vector<Player> players;

public:
    
    // Constructor for a new player
    Player(const string& name, int level, int id) : name(name), level(level), id(id), skillPoints(level * 3) {
        players.push_back(*this);
    }

    // Constructor for a player with existing stats
    Player(const string& name, int level, int id, int stats[], int skillPoints) : name(name), level(level), id(id), skillPoints(skillPoints) {
        for (int i = 0; i < 5; ++i) {
            this->stats[i] = stats[i];
        }
        players.push_back(*this);
    }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getLevel() const { return level; }
    string getStats() const {
        return to_string(stats[0]) + "," + to_string(stats[1]) + "," + to_string(stats[2]) + "," + to_string(stats[3]) + "," + to_string(stats[4]);
    }
    int getSkillPoints() const { return skillPoints; }


    // Comparison operator for sorting players by ID
    bool operator<(const Player& other) const {
        return this->id < other.id;
    }

    // Display basic player info
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "ID: " << id << endl;
    }

    // Display player stats
    void displayStats() {
        cout << "\n#####STATS#####" << endl;
        cout << "Vitality: " << stats[0] << endl;
        cout << "Strength: " << stats[1] << endl;
        cout << "Agility: " << stats[2] << endl;
        cout << "Intelligence: " << stats[3] << endl;
        cout << "Sense: " << stats[4] << "\n" << endl;
    }

    // Add given number of skill points to the given stat
    string addSkillPoints(string& stat, int points) {

        // Convert the stat string to lowercase
        transform(stat.begin(), stat.end(), stat.begin(), [](unsigned char c) {
            return tolower(c);
        });

        if (skillPoints < points) {
            return "Not enough skill points available.";
        }
        
        // Add skill points
        if (stat == "vitality" || stat == "vit" ) {
            stats[0] += points;
        } else if (stat == "strength" || stat == "str") {
            stats[1] += points;
        } else if (stat == "agility" || stat == "agi") {
            stats[2] += points;
        } else if (stat == "intelligence" || stat == "int") {
            stats[3] += points;
        } else if (stat == "sense" || stat == "sen") {
            stats[4] += points;
        } else {
            return "Invalid stat name.";
        }

        //Subtract allocated points
        skillPoints -= points;
        return "Skill points added successfully.";
    }

};


class Admin : public Player {
public:

    // Admin constructor
    Admin(const string& name, int level, int id) : Player(name, level, id) {}

    // Binary search. Used specifically for searching inside vector players based on id
    // Returns the index of the Player object.
    static int binarySearch(int targetId) {
        int left = 0;
        int right = players.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (players[mid].getId() == targetId) {
                return mid;
            } else if (players[mid].getId() < targetId) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    // Uses binary search to see if given player ID is available (aka not taken)
    static bool checkIDAvailability(int targetId) {
        int index = binarySearch(targetId);
        if (index != -1) {
            return false;
        } else {
            return true;
        }
    }

    // Get pointer for player object by given ID
    Player* getPlayerById(int targetId) {
        int index = binarySearch(targetId);
        if (index != -1) {
            return &players[index];
        } else {
            return nullptr;
        }
    }

    // Display all players' info
    void displayAllPlayers() {
        cout << "Number of Players: " << players.size() << endl;
        cout << "List of Players:" << endl << endl;
        for (const Player &p : players) {
            p.displayInfo();
            cout << endl;
        }
    }

    // Display player by given id
    void displayPlayerById(int targetId) {
        Player* pPtr = getPlayerById(targetId);
        if (pPtr != nullptr) {
            pPtr->displayInfo();
            pPtr->displayStats();
        } else {
            cout << "Player with ID " << targetId << " not found." << endl;
        }
    }

    // Add player given name, level, id
    void addPlayer(const string& name, int level, int id) {
        if (!checkIDAvailability(id)) {
            cout << "Player with ID " << id << " already exists." << endl;
            return;
        }
        Player(name, level, id);
        sort(players.begin(), players.end());
        exportToCSV("players.csv"); // Automatically export after adding a player
    }

    // Remove player given ID
    void removePlayer(int targetId) {
        int index = binarySearch(targetId); // Find the index directly using binary search
        if (index != -1) {
            players.erase(players.begin() + index); // Remove player with iterator at index
            cout << "Player with ID " << targetId << " has been removed." << endl;
            exportToCSV("players.csv"); // Automatically export after removing a player
        } else {
            cout << "Player with ID " << targetId << " not found." << endl;
        }
    }


    // File I/O: Export players to CSV file
    static void exportToCSV(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << "ID,Name,Level,Vitality,Strength,Agility,Intellegience,Sense,SkillPoints\n"; // CSV Header
            for (const Player& p : players) {
                if (p.getId() == 0) continue; // Skips admin user

                // Output player data to csv file
                outFile << p.getId() << "," << p.getName() << "," << p.getLevel() << "," << p.getStats() << "," << p.getSkillPoints() << "\n";
            }
            outFile.close();
            cout << "Successfully exported player data to " << filename << endl;
        } else {
            cout << "Error: Could not open file " << filename << " for writing." << endl;
        }
    }

    // File I/O: Import players from CSV file
    static void importFromCSV(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;
            getline(inFile, line); // Skip header row
            int importedCount = 0;
            
            // Create players from each line in the csv file
            while (getline(inFile, line)) {
                stringstream ss(line);
                string idStr, name, levelStr, statsStr, skillPointsStr;
                
                // Get player information
                if (getline(ss, idStr, ',') && getline(ss, name, ',') && getline(ss, levelStr, ',')) {

                    // Get id and level
                    int id = stoi(idStr);
                    int level = stoi(levelStr);

                    // Get all 5 stats
                    int stats[5];
                    for (int i = 0; i < 5; ++i) {
                        if (getline(ss, statsStr, ',')) {
                            stats[i] = stoi(statsStr);
                        } else {
                            break; // Skip to the next line if stats are incomplete
                        }
                    }

                    // Get number of skill points
                    int skillPoints;
                    if (getline(ss, skillPointsStr, ',')) {
                        skillPoints = stoi(skillPointsStr);
                    } else {
                        continue; // Skip to the next line
                    }

                    // Add only if ID doesn't already exist
                    if (checkIDAvailability(id)) {
                        Player(name, level, id, stats, skillPoints);
                        importedCount++;
                    }
                } else {
                    continue; // Skip to the next line
                }
            }
            inFile.close();
            sort(players.begin(), players.end()); // Sort players after loading all players
            cout << "Successfully imported " << importedCount << " player(s) from " << filename << endl;
        } else {
            cout << "Error: Could not open file " << filename << " for reading." << endl;
        }
    }
};



int main() {
    Admin admin("AdminUser", 10, 0);

    int decision = 0;
    
    // Ask user for decision
    while (decision != 8) { // Updated loop exit condition to 8
        cout << "\nAdmin Menu:" << endl;
        cout << "1. Add Player" << endl;
        cout << "2. Remove Player" << endl;
        cout << "3. Display All Players" << endl;
        cout << "4. Search Player by ID" << endl;
        cout << "5. Export to CSV" << endl;
        cout << "6. Import from CSV" << endl;
        cout << "7. Manage Player Attributes" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: "; 
        
        // Input validation
        while (true) {
            decision = getPositiveInteger();
            cout << endl;
            if (decision >= 1 && decision <= 8) { // Updated validation range to 1-8
                break;
            } else {
                cout << "Invalid choice. Please try again (1-8): ";
            }
        }
        
        
        switch (decision) {
            case 1: { // Add player
                string name;
                int level, id;

                // Get player info
                cout << "Enter player name: ";
                name = getValidName();

                cout << "Enter player level: ";
                level = getPositiveInteger();

                cout << "Enter player ID: ";
                id = getPositiveInteger();
                
                // Check if ID is available and add player
                if (Admin::checkIDAvailability(id)) {
                    admin.addPlayer(name, level, id);
                    cout << "Player added successfully! (Auto saved to players.csv)" << endl;
                } else {
                    cout << "Player with ID " << id << " already exists." << endl;
                }

                cout << endl;
                break;
            }
            case 2: { // Remove player
                int id;

                // Get ID and remove player
                cout << "Enter player ID to remove: ";
                id = getPositiveInteger(); // get valid ID
                admin.removePlayer(id);

                cout << endl;
                break;
            }
            case 3: // Display player
                admin.displayAllPlayers();

                cout << endl;
                break;
            case 4: { // Search player by ID
                int id;
                cout << "Enter player ID to search: ";
                id = getPositiveInteger(); // Get a valid ID
                admin.displayPlayerById(id);

                cout << endl;
                break;
            }
            case 5: { // Export players' data to a csv file
                cout << "Enter CSV filename to export to (e.g., players): ";
                string filename = getValidFilename(); // Get file name
                Admin::exportToCSV(filename);
                cout << endl;
                break;
            }
            case 6: { // Import players' data from a csv file
                cout << "Enter CSV filename to import from (e.g., players): ";
                string filename = getValidFilename(); // Get file name
                Admin::importFromCSV(filename);
                cout << endl;
                break;
            }
            case 7: { // Manage a player's attribute
                cout << "Enter player ID to manage attributes: ";
                int id = getPositiveInteger();
                admin.displayPlayerById(id);

                Player* pPtr = admin.getPlayerById(id);
                if (pPtr == nullptr) {
                    cout << "Player with ID " << id << " not found." << endl;
                    break;
                }

                cout << "Enter the stat to add points to (Vitality, Strength, Agility, Intelligence, Sense): ";
                string stat;
                cin >> stat;
                cout << "Enter the amount of points to add (Available: " << pPtr->getSkillPoints() << "): ";
                int points = getPositiveInteger();
                cout << pPtr->addSkillPoints(stat, points) << endl;
                cout << endl;
                break;
            }
            case 8: // Exit program
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cout << endl;
        }
    }
    return 0;
}