#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
#include <cstring> 

using namespace std;



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
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayProviderMenu();  
                
            }
            break;

          case 2:
            {   
                displayAllFeedback();
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayProviderMenu();  
                 

            }
            break; 

        case 3:
            {    
                weeklyCopay();
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayProviderMenu();  
            }
        break;

        case 4 : 
            {
                confirmApp(); 
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayProviderMenu();  
            }
        break;

    }
}