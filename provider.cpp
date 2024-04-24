// THINGS TO DO:
// Check weekly copay 
// Check feedback 
// View all patients 
// try but **medication


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
using namespace std;


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

        void calculateWeeklyCopay(){
            // totalWeeklyCoPay = numberOfAppointments * providerRate;
            //we get weekly visit count from appointments.txt            
        }


};

void confirmAppontment() 
{
    // variables to store patient name, status, and balance 
   

    // open file in append mode
    ofstream outfile("completedAppts.txt", std::ios_base::app);

     // Get first and last name from the user
    string name, insuranceType, status;
    double balance = 0.00; 

    cout << endl;
    cout << "Enter patient name: ";
    cin >> name; 



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
            
            // retrieve insurance
            if (searchName == name) {

                // searching for card number 
                for (int i = 0; i < 4; i++) {
                    if (!getline(iss, searchName, ':')) {
                        cout << "Error: Unable to read data." << endl;
                       
                    }
                }

                // display output
                insuranceType = searchName;

            }
        }
    }

    // find copay depending on insurance type 
    if (insuranceType == "unicorn") {
            balance += 25.00;}

    else if (insuranceType == "alien") {
            balance += 50.00; }
    else {
        balance += 100.00;   }


    // ask about patient's status 
    cout << "Was the patient's appointment completed, late, or canceled?\n";
    cout << "Enter the patient's appointment status: ";
    cin >> status; 

    // add co-pay or late fee as needed 
    if (status == "late") {
        balance += 50.00;
    }
    else if (status == "canceled") {
        balance += 100.00;
    }


    // Append the first and last name to the file
    outfile << name << ":" << status << ":" << balance << ".00" << endl;
    
    // Close the file
    file.close();
    outfile.close();

    cout << "\nRecorded. Thanks, Doc!" << endl; 
    cout << endl; 


}


int main () {
    cout << "*********************************************************************\n";
    cout <<"..............CalenDoc Provider Interface ............\n";
    cout << "*********************************************************************\n";
    int k = 0;
    int choice;

        cout << "\tChoose Option From Menu (1-5) \n";
        cout << "--------------------------------------------------------------------\n";
        cout << "\t1. View all Patients \n";
        cout << "\t2. View all Feedback\n";
        cout << "\t3. Check Weekly Copay\n";
        cout << "\t4. Confirm Appointment Status\n";
        cout << endl;
        cout << "Please Enter your Preferred Choice :- ";

        cin >> choice;



    switch(choice) {

        case(4):
        {
            confirmAppontment();
        }
        break; 
    }
}