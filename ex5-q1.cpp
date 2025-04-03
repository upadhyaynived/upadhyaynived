#include <iostream>
using namespace std;

class Player {
private:
    string name;
    string teamName;
    float battingAverage;

public:
    
    Player() {
        name = "";
        teamName = "";
        battingAverage = 0.0;
    }

    
    void getData() {
        cout << "Enter Player Name: ";
        cin >> name;
        cout << "Enter Team Name: ";
        cin >> teamName;
        cout << "Enter Batting Average: ";
        cin >> battingAverage;
    }

    
    void displayData() {
        cout << "Name: " << name << ", Team: " << teamName << ", Batting Average: " << battingAverage << endl;
    }

    
    float getBattingAverage() {
        return battingAverage;
    }

    
    string getTeamName() {
        return teamName;
    }

    
    string getName() {
        return name;
    }
};


void sortByAverage(Player players[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (players[i].getBattingAverage() < players[j].getBattingAverage()) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}


void sortByTeam(Player players[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (players[i].getTeamName() > players[j].getTeamName() || 
               (players[i].getTeamName() == players[j].getTeamName() && players[i].getName() > players[j].getName())) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

int main() {
    Player players[10];

    
    for (int i = 0; i < 10; i++) {
        cout << "\nEnter details for Player " << i + 1 << ":\n";
        players[i].getData();
    }

    
    sortByAverage(players, 10);
    cout << "\nPlayers sorted by batting average:\n";
    for (int i = 0; i < 10; i++) {
        players[i].displayData();
    }

    
    sortByTeam(players, 10);
    cout << "\nPlayers sorted team-wise:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Team: " << players[i].getTeamName() << ", Player: " << players[i].getName() << ", Average: " << players[i].getBattingAverage() << endl;
    }

    return 0;
}
