#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string name;
    cout << "Enter a name: ";
    getline(cin, name);

    ifstream inputFile("data.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;
        int colonCount = 0;

        while (getline(ss, token, ':')) {
            colonCount++;
            if (colonCount == 1 && token == name) {
                getline(ss, token, ':'); // Skip the next token
                if (!getline(ss, token, ':')) // Get the token after the second colon
                    break;
                cout << "String after the second colon for " << name << ": " << token << endl;
                break;
            }
        }
    }

    inputFile.close();

    return 0;
}
