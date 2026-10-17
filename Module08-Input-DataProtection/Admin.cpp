#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Player {
protected:
    int id;
    string name;
    int level;
    inline static vector<Player> players;

public:
    Player(string name, int level, int id) : name(name), level(level), id(id) {
        players.push_back(*this);
    }

    bool operator<(const Player other) const {
        return this->id < other.id;
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "ID: " << id << endl;
    }

    static int binarySearch(int targetId) {
        int left = 0;
        int right = players.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (players[mid].id == targetId) {
                return mid;
            } else if (players[mid].id < targetId) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    bool checkIDAvailability(int targetId) {
        int index = binarySearch(targetId);
        if (index != -1) {
            return false;
        } else {
            return true;
        }
    }


};


class Admin : public Player {
public:
    Admin(string name, int level, int id) : Player(name, level, id) {}

    void displayAllPlayers() {
        cout << "Number of Players: " << players.size() << endl;
        cout << "List of Players:" << endl << endl;
        for (Player p : players) {
            p.displayInfo();
            cout << endl;
        }
    }

    void displayPlayerById(int targetId) {
        int index = binarySearch(targetId);
        if (index != -1) {
            players[index].displayInfo();
        } else {
            cout << "Player with ID " << targetId << " not found." << endl;
        }
    }

    void addPlayer(string name, int level, int id) {
        Player(name, level, id);
        sort(players.begin(), players.end());
    }

    void removePlayer(int targetId) {
        int index = binarySearch(targetId);
        if (index != -1) {
            players.erase(players.begin() + index);
            cout << "Player with ID " << targetId << " has been removed." << endl;
        } else {
            cout << "Player with ID " << targetId << " not found." << endl;
        }
    }
};


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

int main() {

    Admin admin("AdminUser", 10, 0);

    int decision = 0;
    while (decision != 5) {
        cout << "Admin Menu:" << endl;
        cout << "1. Add Player" << endl;
        cout << "2. Remove Player" << endl;
        cout << "3. Display All Players" << endl;
        cout << "4. Search Player by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: "; 
        while (true) {
            decision = getPositiveInteger();
            if (decision >= 1 && decision <= 5) {
                break;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << endl;
        }

        switch (decision) {
            case 1: {
                string name;
                int level, id;
                cout << "Enter player name: ";
                name = getValidName();

                cout << "Enter player level: ";
                level = getPositiveInteger();

                cout << "Enter player ID: ";
                id = getPositiveInteger();

                if (admin.checkIDAvailability(id)) {
                    admin.addPlayer(name, level, id);
                } else {
                    cout << "Player with ID " << id << " already exists." << endl;
                }

                cout << endl;
                break;
            }
            case 2: {
                int id;
                cout << "Enter player ID to remove: ";
                id = getPositiveInteger();
                admin.removePlayer(id);

                cout << endl;
                break;
            }
            case 3:
                admin.displayAllPlayers();

                cout << endl;
                break;
            case 4: {
                int id;
                cout << "Enter player ID to search: ";
                id = getPositiveInteger();
                admin.displayPlayerById(id);

                cout << endl;
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cout << endl;
        }
    }
}