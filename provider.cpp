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
    //idea, theres only one provider so we don't need to add all his info, plus we will not be using it 
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
            //get the size of appointment vector and that will be numberOfAppointments
            
        }


};


     //CODE WHERE YOU CAN SEE ALL THE PATIENT NAMES FOR PROVIDER VIEW ***********************
                // PatientInformationCollection p;
                // int count = 0;
                // fstream f6;
                // f6.open("bookin.txt",ios::in|ios::out|ios::binary);
                // f6.seekg(0,ios::beg);
                // f6.read ((char *)&p,sizeof(p));
                // cout.setf(ios::left);
                // cout <<endl;
                //cout <<setw(15)<< "patientName" <<setw(20)<< "patientID" <<setw(30)<< "dateOfBirth" <<setw(20)<< "patientPayment" <<setw(12)<< "insuranceType" <<setw(30)<< "Balance" <<endl;
                // while(f6.eof() != 1)
                // {
                //     p.disInfo();
                //     f6.read ((char *)&p,sizeof(p));
                //     count++;
                // }
                // f6.close();

                // cout << "\n\tTotal Number of passengers is "<<count<<endl;
                // char c6;
                // cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                // cin >> c6;

                // if(c6 == 'q'|| c6 == 'Q')
                //     exit(EXIT_FAILURE);
                // else
                //     goto start;

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
        cout << "\t2. Check Feedback\n";
        cout << "\t3. Check Weekly Copay\n";
        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;
        if(choice<1 || choice >3)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            k++;
        }
    }while (k != 0);
}