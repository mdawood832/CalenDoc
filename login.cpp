
#include<iostream>
#include <fstream> 
#include <string> 

using namespace std;
#include "authentication.h"


//input validation for ID number make sure its only five digits 
//

int main()
{
        int c;   
        cout<<"\t\t\t__________________________________________________________________________\n\n\n";
        cout<<"\t\t\t                     Welcome to the Login page                               \n\n";
        cout<<"\t\t\t______________________        MENU        ________________________________\n\n";
        cout<<"                                                                                \n\n";
        cout<<"\t|  Press 1 to LOGIN                    |"<<endl;
        cout<<"\t|  Press 2 to REGISTER                 |"<<endl;
        cout<<"\t|  Press 3 if you forgot your PASSWORD |"<<endl;
        cout<<"\t|  Press 4 to Exit                     |"<<endl;
        cout<<"\n\t\t\tPlease Enter your choice :";
        cin>>c;
        cout<<endl;

        switch(c)
        {
                case 1:
                        login();
                        main();
                case 2:
                        registration();
                        main(); 
                case 3:
                        forgot();
                        main(); 
                case 4:
                        cout<<"\t\t\tThankyou!\n\n";
                        break; 
                default:
                        cout<<"\t\t\tPlease select from the options given above , Try again..\n"<<endl;
                        main();
        }

}






      


