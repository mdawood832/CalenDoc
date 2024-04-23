// THINGS TO DO:
// Confirm appointment (complete, late, or canceled)
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


int main () {
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
        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;
        if(choice<1 || choice >3)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            k++;
        }
    }while (k != 0);
}