#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// Admin credentials
const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "1234";

map<string, int> votes;
map<string, bool> votedUsers;

// Save results to CSV (Excel)
void saveToExcel() {
    ofstream file("votes.csv");
    file << "Candidate,Votes\n";
    for (auto &v : votes) {
        file << v.first << "," << v.second << "\n";
    }
    file.close();
}

// User voting
void userVote() {
    string userId;
    cout << "\nEnter User ID: ";
    cin >> userId;

    if (votedUsers[userId]) {
        cout << "You have already voted!\n";
        return;
    }

    cout << "\nCandidates:\n";
    int i = 1;
    for (auto &v : votes) {
        cout << i++ << ". " << v.first << endl;
    }

    int choice;
    cout << "Enter your choice number: ";
    cin >> choice;

    i = 1;
    for (auto &v : votes) {
        if (i == choice) {
            votes[v.first]++;
            votedUsers[userId] = true;
            saveToExcel();
            cout << "Vote cast successfully!\n";
            return;
        }
        i++;
    }

    cout << "Invalid choice!\n";
}

// Admin panel
void adminPanel() {
    string username, password;
    cout << "\nAdmin Username: ";
    cin >> username;
    cout << "Admin Password: ";
    cin >> password;

    if (username != ADMIN_USERNAME || password != ADMIN_PASSWORD) {
        cout << "Invalid admin credentials!\n";
        return;
    }

    cout << "\n--- Voting Results ---\n";
    for (auto &v : votes) {
        cout << v.first << ": " << v.second << " votes\n";
    }

    saveToExcel();
    cout << "\nResults saved to votes.csv\n";
}

// Main menu
int main() {
    // Initial candidates
    votes["Alice"] = 0;
    votes["Bob"] = 0;
    votes["Charlie"] = 0;

    int choice;
    do {
        cout << "\n--- Voting System ---\n";
        cout << "1. User Vote\n";
        cout << "2. Admin Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                userVote();
                break;
            case 2:
                adminPanel();
                break;
            case 3:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}