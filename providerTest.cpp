#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name;
    cout << "Enter name to search for: ";
    getline(cin, name); // Get the name from the user

    ifstream inputFile("completedAppts.txt"); // Open the file
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    bool found = false;
    while (getline(inputFile, line)) { // Read each line of the file
        size_t pos = line.find(name); // Search for the name in the line
        if (pos != string::npos) { // If name is found in the line
            size_t colonPos = line.find(':', pos + name.length()); // Find the position of the second colon
            if (colonPos != string::npos) {
                string data = line.substr(colonPos + 1); // Get the substring after the second colon
                cout << data << endl;
                found = true;
                break; // No need to search further
            }
        }
    }

    if (!found) {
        cout << "Name not found or data not available." << endl;
    }

    inputFile.close(); // Close the file
    return 0;
}
