
#include<iostream>
#include <fstream> 
#include <string> 

using namespace std;
#include "authentication.h"


int main()
{
        int c;   
    cout << "*********************************************************************\n";
    cout <<".........................Login Page ..................................\n";
    cout << "*********************************************************************\n";
        cout<<"                                                                                \n\n";
        cout<<"  Press 1 to LOGIN                    "<<endl;
        cout<<"  Press 2 to REGISTER                 "<<endl;
        cout<<"  Press 3 if PASSWORD RECOVERY        "<<endl;
        cout<<"  Press 4 to EXIT                   \n "<<endl;
        cout<<"  Please Enter your choice :   " ; 
        cin>>c;
        cout << endl; 


        switch(c)
        {
                case 1:
                        login();

                case 2:
                        registration();
                        main(); 
                case 3:
                        forgot();
                        main(); 
                case 4:
                        cout<<"Thankyou!\n\n";
                        break; 
                default:
                        cout<<"Please select from the options given above , Try again..\n"<<endl;
                        main();
        }

}






      


