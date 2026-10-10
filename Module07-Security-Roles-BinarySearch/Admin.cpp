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

};


class Admin : public Player {
public:
    Admin(string name, int level, int id) : Player(name, level, id) {}

    void displayAllPlayers() {
        cout << "List of Players:" << endl;
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


int main() {
    Admin admin("AdminUser", 10, 0);

    // Adding players
    admin.addPlayer("Player1", 5, 912);
    admin.addPlayer("Player2", 3, 213);
    admin.addPlayer("Player3", 7, 523);

    // Display all players
    admin.displayAllPlayers();

    // Search for a player by ID
    cout << "Searching for Player with ID 213:" << endl;
    admin.displayPlayerById(213);
    cout << endl;

    // Remove a player by ID
    cout << "Removing Player with ID 213:" << endl;
    admin.removePlayer(213);
    cout << endl;

    // Display all players after removal
    admin.displayAllPlayers();

    return 0;
}