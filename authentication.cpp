#include "authentication.h"
#include <iostream>
#include <fstream> // Include the header for file input/output operations
#include <string> // Include the header for string operations

void login() {
    int count = 0;
    std::string userId, password, id, pass; 

    std::cout << "\t\t\tplease enter the username & password" << std::endl; 
    std::cout << "\t\t\tUSERNAME :";
    std::cin >> userId; 
    std::cout << "\t\t\tPASSWORD :";
    std::cin >> password; 

    std::ifstream input("records.txt");
    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;

        }
    }
    input.close();
    if (count == 1) {
        std::cout << userId << "\n Your Login is Successful\nThanks for logging in!\n";
        
    } else {
        std::cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        
    }
}

void registration() {
    std::string ruserId, rpassword, rid, rpass;
 
    std::cout << "\t\t\tEnter the username (Patient username must start with 1, Provider username starts with 2, Admin username starts with 3)";
    std::cin >> ruserId;
    std::cout << "\n\t\t\tEnter the password :";
    std::cin >> rpassword;

    std::ofstream f1("records.txt", std::ios::app);
    f1 << ruserId << ' ' << rpassword << std::endl;

    std::cout << "\n\t\t\tRegistration is Successful\n";
}

void forgot() {
    int option;

    std::cout << "\t\t\tYou forgot your password? No worries\n";
    std::cout << "Press 1 to Search your id by username" << std::endl;
    std::cout << "Press 2 to go Back to the Main menu" << std::endl;
    std::cout << "\t\t\tEnter your choice :";
    std::cin >> option;
    switch (option) {
                case 1:
                {
                        int count=0;
                        std::string suserId,sId,spass;
                        std:: cout<<"\n\t\t\tEnter the username which you remembered :";
                        std::cin>>suserId;

                        std::ifstream f2("records.txt");
                        while(f2>>sId>>spass)
                        {
                                if(sId==suserId)
                                {
                                        count=1;
                                }
                        }
                        f2.close();
                        if(count==1)
                        {
                                std::cout<<"\n\n\tYour account is found\n";
                                std::cout<<"\n\tYour password is "<<spass;
                                
                        }
                        else
                        {
                                std::cout<<"\n\tSorry, Account not found! \n";
                                
                        }
                        
                        break;
                }
                case 2:
                {
                        int count=0;
                        std::string searchpass,su2,sp2;
                        std::cout<<"\nEnter the remembered password :";
                        std::cin>>searchpass;

                        std::ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                std::cout<<"\nYour password is found in the database \n";
                                std::cout<<"\nYour Id is : "<<su2;
                                std::cin.get();
                                std::cin.get();
                                
                        }
                        else
                        {
                                std::cout<<"Sorry, We cannot found your password in our database \n";
                                std::cout<<"\nkindly contact your administrator for more information\n";
                                std::cin.get();
                                std::cin.get();
                        }

                        break;
                } 

    }
}

