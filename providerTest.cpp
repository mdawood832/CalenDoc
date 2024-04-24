#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // for transform
#include <sstream>

using namespace std;

void removeLineWithMatchingName(const string& name, ifstream& inputFile, ofstream& outputFile) {
    string line;
    bool nameFound = false;

    while (getline(inputFile, line)) {
        string currentName;
        istringstream iss(line);
        if (getline(iss, currentName, ':')) {
            transform(currentName.begin(), currentName.end(), currentName.begin(), ::tolower);
            if (currentName != name) {
                outputFile << line << endl;
            } else {
                nameFound = true;
            }
        }
    }

    if (!nameFound) {
        cout << "Name not found in the file." << endl;
    }
}

int main() {
    string name;
    cout << "Enter a name to search for: ";
    getline(cin, name);

    // Open input file
    ifstream inputFile("completedAppts.txt");
    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    // Open output file
    ofstream outputFile("records.txt");
    if (!outputFile) {
        cerr << "Error opening output file!" << endl;
        inputFile.close();
    }

    // Remove lines with matching name from input file and copy to output file
    removeLineWithMatchingName(name, inputFile, outputFile);

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}