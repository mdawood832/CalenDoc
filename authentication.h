// authentication.h - authentication header file 
// Written by Maryam Dawood 
// Written 04/16/2024
// authentication.h includes all functions related to the login page
// as well as taking either patient, provider, or admin to their 
// respective interface. The header file also includes 
// login functionality, registration, and password recovery. 



#include <iostream>
#include <fstream> 
#include <string> 
#include <random>
#include "patient.h"
#include "admin.h"
#include "provider.h"



// if users id starts with 1 then display patient interface
// if users id starts with 2 then display provider interface
// if users id starts with 3 then display admin interface
void switchDisplays(int firstNum) {

        if (firstNum == 1) {
            displayMenuPatient(); 
        } else if (firstNum == 2) {
            displayProviderMenu(); 
        } else if (firstNum == 3) {
            displayAdminMenu(); 
        } 
}


//asking patient to enter their ID and Password 
//checking that the login info matches what's saved in records.txt
//if the login info matches what's saved then we can pass the first digit 
//of the id to switchDisplays() to display the respective interface. 
//ELSE: the info entered does not match and we display error message 
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

//allowing the user to register an account as a provider, admin, or patient
//it will ask what role the user falls in. If the user selects patient then the system will generate a 
//random five digit ID starting with 1. Provider ID starts with 2. Admin ID starts with 3. If 
//the user types a role that does not exist we display an error message saying that role does not exist and call the 
//registration function again. 
//Once the user has their ID they are prompted to enter the password. Both ID and password are then saved 
//to "records.txt" with a " " in between. 


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

//If the user forgets their password we can look up their password using their username. 
//Tthe program will ask the user to enter their username and then check if the username matches anything we have in records.txt. 
//If it is found we set count to 1 followed by another if statement that checks if count is set to 1 or 0. 
//If count is set to 1 we display the password. If count is set to 0 that means the username does not exist 
//in records.txt and it will display a message saying that the account was not found. 

void forgot(){
    int option;

    cout << "\t\t\tYou forgot your password? No worries\n";
    cout << "Search your id by username" << endl;



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
                cout<<"\n\tYour password is "<<spass << endl; 
            }
            else
            {
                cout<<"\n\tSorry, Account not found! \n";
            }
            
    

    
}
