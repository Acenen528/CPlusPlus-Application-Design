#include <iostream>
using namespace std;

void awakening() {
    cout << "[SYSTEM LINK ESTABLISHED]" << endl;
    cout << "[RECOVERY COMPLETE: YOU HAVE AWAKENED]" << endl;
}

int main() {
    cout << "[CRITICAL EMERGENCY] HEALTH: (1/100)" << endl;
    cout << "YOU HAVE BEEN CHOSEN TO BECOME A 'PLAYER'" << endl;
    cout << "3 SECONDS LEFT" << endl;
    cout << "DO YOU ACCEPT?" << endl;

    char choice;
    int chances = 3;
    while (chances > 0) {
        cout << "1. Accept" << endl;
        cout << "2. Decline" << endl;
        cin >> choice;
        cout << endl;

        switch (choice) {
            case '1':
                awakening();
                return 0;
            case '2':
                cout << "You've accepted your fate... (GAME OVER)" << endl;
                return 0;
            default:
                chances--;
                cout << chances << " SECONDS LEFT" << endl;
        }
    }

    cout << "Time ran out. Your heart stopped pounding... (GAME OVER)" << endl;

}