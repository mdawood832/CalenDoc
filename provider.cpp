#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
using namespace std;


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
        int coPay; 

        void getInfo()
        {
            cout << "Enter Provider's Name (all lowercase): ";
            cin.get();
            cin >> providerName; 

            cout << "Enter Provider ID: ";
            cin >> providerID;       
        }

        void disInfo(){
            //copy from patient.cpp

        }

        void calculateWeeklyCopay(){
            // totalWeeklyCoPay = numberOfAppointments * providerRate;
            //we get weekly visit count from appointments.txt            
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
        cout << "Line: " << line << endl;
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
            cout << "Phone: " << phone << endl;
            cout << "Species: " << species << endl;
        } else {
            cout << "Invalid line format" << endl;
        }

        // Add extra line for clarity
        cout << endl;
    }

    file.close();

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
        cout << "\t4. Confirm Appointment Status";
        cout << "\t5. View Provider Information";
        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;
        if(choice<1 || choice >5)
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
                goToStart(); 

            }
            break; 

        case 3:
            {    
                goToStart(); 
            }
        break;

        case 4 : 
            {

                goToStart(); 
            }
        break;

        case 5 : 
            {


                goToStart(); 
            }
        break; 

    }
}



int main () {
    displayProviderMenu(); 
}