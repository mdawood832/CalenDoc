
#include <iostream>
#include <fstream> 
#include <string> 
#include <random>
#include "patient.h"

void switchDisplays(int firstNum) {

        if (firstNum == 1) {
            displayMenuPatient(); 
        } else if (firstNum == 2) {
            cout << "ID starts with 2 (Provider)" << endl;
        } else if (firstNum == 3) {
            cout << "ID starts with 3 (Admin)" << endl;
        } 
}

void login() {

    int count = 0;
    string  password, pass; 
    string userId, id; 
    cout << "\t\t\tplease enter the username & password" << endl; 
    cout << "\t\t\tID :";
    cin >> userId; 
    cout << "\t\t\tPASSWORD :";
    cin >> password; 

    ifstream input("records.txt");
       while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1) {
        cout << "successufl login" << endl; 
        int firstDigit = std::stoi(userId) / 10000;
        switchDisplays(firstDigit); 
    
    } else {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
    }
}

void registration() {
    string role; 
    cout << "Are you a Patient, Provider, or Admin" << endl; 
    cin >> role; 

    if(role == "Patient" | role == "patient"){
        string rpassword, rpass;

        random_device rd;
        mt19937 gen(rd());
        
        // Define the distribution for five-digit numbers starting with 1
        uniform_int_distribution<> dis(10000, 19999);
        
        // Generate a random five-digit ID
        int id = dis(gen);
        
        // Output the generated ID
        cout << "Generated five-digit ID: " << id << endl;
        
    
        cout << "\n\t\t\tEnter the password :";
        cin >> rpassword;

        ofstream f1("records.txt", ios::app);
        f1 << id << ' ' << rpassword << endl;

        cout << "\n\t\t\tRegistration is Successful\n";
    } else if (role == "Provider" | role == "provider"){
        string  rpassword, rpass;
        random_device rd;
        mt19937 gen(rd());
        
        // Define the distribution for five-digit numbers starting with 2
        uniform_int_distribution<> dis(20000, 29999);
        
        // Generate a random five-digit ID
        int id = dis(gen);
        
        // Output the generated ID
        cout << "Generated five-digit ID: " << id << endl;

        cout << "\n\t\t\tEnter the password :";
        cin >> rpassword;

        ofstream f1("records.txt", ios::app);
        f1 << id << ' ' << rpassword << endl;
    } else if (role == "Admin" | role == "admin"){
        string rpassword, rpass;
        random_device rd;
        mt19937 gen(rd());
        
        uniform_int_distribution<> dis(30000, 39999);
        
        int id = dis(gen);
        
        cout << "Generated five-digit ID: " << id << endl;
        cout << "\n\t\t\tEnter the password :";
        cin >> rpassword;

        ofstream f1("records.txt", ios::app);
        f1 << id << ' ' << rpassword << endl;
    } else {
        cout << "No such role exists, try again" << endl; 
        registration(); 
    }
    


    

}

void forgot(){
    int option;

    cout << "\t\t\tYou forgot your password? No worries\n";
    cout << "Press 1 to Search your id by username" << endl;
    cout << "Press 2 to go Back to the Main menu" << endl;
    cout << "\t\t\tEnter your choice :";
    cin >> option;
    switch (option) {
        case 1:
        {
            int count=0;
            string suserId,sId,spass;
            cout<<"\n\t\t\tEnter the username which you remembered :";
            cin>>suserId;

            ifstream f2("records.txt");
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
                cout<<"\n\n\tYour account is found\n";
                cout<<"\n\tYour password is "<<spass;
            }
            else
            {
                cout<<"\n\tSorry, Account not found! \n";
            }
            
            break;
        }
        case 2:
        {
            int count=0;
            string searchpass,su2,sp2;
            cout<<"\nEnter the remembered password :";
            cin>>searchpass;

            ifstream searchp("database.txt");
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
                cout<<"\nYour password is found in the database \n";
                cout<<"\nYour Id is : "<<su2;
                cin.get();
                cin.get();
            }
            else
            {
                cout<<"Sorry, We cannot found your password in our database \n";
                cout<<"\nkindly contact your administrator for more information\n";
                cin.get();
                cin.get();
            }

            break;
        } 
    }
}
