#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
using namespace std;


//save info to providerInfo.txt

int main(); 

void goToStart(){
                char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    main(); 
}

class ProviderInformationCollection
{
    public :
        char providerName[20];
        int providerID;

        void getInfo()
        {
            cout << "Enter Provider's Name (all lowercase): ";
            cin.get();
            cin >> providerName; 

            cout << "Enter Provider ID: ";
            cin >> providerID;       
        }

        void disInfo(){
            
            cout.setf(ios::left);
            cout <<setw(15)<< providerName <<setw(20)<< providerID <<endl;

        }


};


void displayAllPatients(){
    // Open the text file
    ifstream file("patientInfo.txt");
    string line;

    // Read each line
    while (getline(file, line)) {
        // Create a string stream to split the line
        stringstream ss(line);
        string item;
        vector<string> values;

        // Split the line by ":" delimiter
        while (getline(ss, item, ':')) {
            values.push_back(item);
        }

        // Display the values
        if (values.size() >= 5) {
            // Extract individual values
            string name = values[0];
            string id_number = values[1];
            string dob = values[2];
            string phone = values[3];
            string species = values[4];

            // Display the values
            cout << "Name: " << name << endl;
            cout << "ID Number: " << id_number << endl;
            cout << "Date of Birth: " << dob << endl;
            cout << "Credit Card Number: " << phone << endl;
            cout << "Insurance: " << species << endl;
        } else {
            cout << "Invalid line format" << endl;
        }

        // Add extra line for clarity
        cout << endl;
    }

    file.close();

}

void displayAllFeedback(){
    ifstream file("feedback.txt");
    string line;

    // Read each line
    while (getline(file, line)) {
        // Check if the line starts with "Name: "
        if (line.find("Name: ") == 0) {
            // Extract name
            string name = line.substr(6);

            // Read ID, Date, and Rating from the next three lines
            string id, date, rating;
            getline(file, line); // Read ID line
            id = line.substr(4);

            getline(file, line); // Read Date line
            date = line.substr(6);

            getline(file, line); // Read Rating line
            rating = line.substr(8);

            // Display the feedback
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Date: " << date << endl;
            cout << "Rating: " << rating << endl;
            cout << "---------------------------" << endl;
        }
    }

    // Close the file
    file.close();

}

void weeklyCopay(){
    ifstream file("weeklyCopay.txt");
    string line;
    int sum = 0;

    // Read each line
    while (getline(file, line)) {
        // Convert the line to an integer and add it to the sum
        sum += stoi(line);
    }

    // Close the file
    file.close();

    // Display the sum
    cout << "Th weekly copay is : $ " << sum << endl;
}

void confirmApp(){
    

}








void displayProviderMenu(){
start: 
    cout << "*********************************************************************\n";
    cout <<"..............CalenDoc Provider Interface ............\n";
    cout << "*********************************************************************\n";
    int k = 0;
    int choice;
    do
    {
        cout << "\tChoose Option From Menu (1-5) \n";
        cout << "--------------------------------------------------------------------\n";
        cout << "\t1. View all Patients \n";
        cout << "\t2. View all Feedback\n";
        cout << "\t3. Check Weekly Copay\n";
        cout << "\t4. Confirm Appointment Status\n";
        cout << "Please Enter your Preferred Choice : ";
        cin >> choice;
        if(choice<1 || choice >4)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            k++;
        }
    }while (k != 0);
    switch (choice)
    {
        case 1:  
            {
                displayAllPatients();
                goToStart(); 
            }
            break;

          case 2:
            {   
                displayAllFeedback();
                goToStart(); 

            }
            break; 

        case 3:
            {    
                weeklyCopay();
                goToStart(); 
            }
        break;

        case 4 : 
            {
                confirmApp(); 
                goToStart(); 
            }
        break;

    }
}



int main () {
    displayProviderMenu(); 
}