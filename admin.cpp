#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
using namespace std;


int main()
{
start :
    cout << "*********************************************************************\n";
    cout <<"..............CalenDoc Patient Interface ............\n";
    cout << "*********************************************************************\n";
    int k = 0;
    int choice;
    do
    {
        cout << "\tChoose Option From Menu (1-5) \n";
        cout << "--------------------------------------------------------------------\n";
        cout << "\t1. Patient Information Collection\n";
        cout << "\t2. Schedule an Appointment\n";
        cout << "\t3. Cancel an Appointment\n";
   

        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;
        if(choice<1 || choice >7)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            k++;
        }
    }while (k != 0);

     switch (choice)
    {
        case 1:  
            {}


    }

}