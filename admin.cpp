#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
using namespace std;

//charge patient copay 
//reset weekly earnings 
//admin cancel app. (copy)
//admin schedule app. (copy)
//clears day and completed appointments text files 
//search for outstanding balance

void getBalance()
{



}
void chargePatient() {

    string name;
    
    // Ask the user to input a name
    cout << "Enter a name to search for: ";
    cin.ignore();
    getline(cin, name);
    
    // Convert the user input to lowercase
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    
    // Open the file
    ifstream file("patientInfo.txt");
    
    string line;
    bool found = false;
    
    // Read each line from the file
    while (getline(file, line)) {
        istringstream iss(line);
        string searchName;
        string patientBalance;
        
        // Get the name from the line and convert it to lowercase
        if (getline(iss, searchName, ':')) {
            transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
            
            // retrieve patient info if name matches 
            if (searchName == name) {

                // searching for card number 
                for (int i = 0; i < 3; i++) {
                    if (!getline(iss, searchName, ':')) {
                        cout << "Error: Unable to read data." << endl;
                       
                    }
                }
                cout << "\nCard Number: " << searchName << endl;
                cout << name << " has been charged.\n" << endl; 
                found = true;
                break;
            }
        }
    }
    
    // Close the file
    file.close();
    
}

void resetAppointmentFiles() 
{

}

void resetEarnings()
{

}


int main()
{

    cout << "*********************************************************************\n";
    cout <<"..............CalenDoc Admin Interface ............\n";
    cout << "*********************************************************************\n";
    int k = 0;
    int choice;
    do
    {
        cout << "\tChoose Option From Menu (1-5) \n";
        cout << "--------------------------------------------------------------------\n";
        cout << "\t1. Charge Patient Copay\n";
        cout << "\t2. View Patient Balances\n";
        cout << "\t3. Schedule Apppointment\n";
        cout << "\t4. Cancel Apppointment\n";
        cout << "\t5. Reset Schedule\n";
        cout << "\t6. Reset Weekly Earnings\n";
        cout << endl;

   

        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;


    }while (k != 0);

     switch (choice)
    {
        case 1:  
            {
                chargePatient();

            }
            break;

        case 2:  
            {
                getBalance();

            } break;

    }

    return 0;
}