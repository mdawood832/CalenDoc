#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
using namespace std;


//copay calculation for patient

//  WORKING ON: 
//HAVE PATIENT ENTER THEIR NAME AND IT WILL 
//PULL UP DETAILS 
//patient copay calculation 


class PatientInformationCollection
{
    public :
        string patientName;
        int patientID;
        string dateOfBirth;
        string patientPayment;
        int currentBalance = 0;  
        string insuranceType; 


        void getInfo()
        {
            cout << "Enter Patient's Name (all lowercase): ";
            cin.get();
            cin >> patientName; 

            cout << "Enter Patient ID: ";
            cin >> patientID;

            cout << "Date of Birth( DD/MM/YYYY): ";
            cin >> dateOfBirth;

            cout << "Enter your Credit Card Number: ";
            cin >> patientPayment;

            cout <<"Enter your Insurance Type (alien, zombie, unicorn, other): ";
            cin >> insuranceType;
            
            
        }


        //display info
        void disInfo()
        {
            cout.setf(ios::left);
            //this works 
            cout <<setw(15)<< patientName <<setw(20)<< patientID <<setw(30)<<dateOfBirth <<setw(20)<<patientPayment <<setw(30)<< insuranceType<<setw(30)<<currentBalance<<endl;
        }


        void CalculatePatientCopay(){
            // patientCoPayAmount = appointmentCost * (1 - insuranceCoverage);

            /* insurance Coverage rates: 
                alien = 10% 
                zombie = 30%
                unicorn = 100*
                other = 0%
            appointment cost = 100; 
            in the end add patient copay amount to current balance; */
        }

};


class Feedback
{
    public :
        char patientName[20];
        int  patientID;
        char date[10];
        string rating; 
        

        void getFeedback()
        {
            cout << "Enter Name: ";
            cin >> patientName; 

            cout << "Enter Patient ID: ";
            cin >> patientID;

            cout << "Enter Today's Date ( DD/MM/YYYY ): ";
            cin >> date;

            cout << "Enter Provider Rating (1-5): " ;
            cin >> rating;
        }

        void disInfo(){
            cout <<setw(15)<< patientName <<setw(20)<< patientID <<setw(30)<< date <<setw(20)<< rating <<endl;
        }
};



int bookAppointment(){
                cout<<"\n ----- Book Your Appointment ---- \n";	
                cout<<"\n ----- Availbale slots ---- \n";	 

                //check if record already exist..
                ifstream read;
                read.open("appointments.txt");
                
                int hoursbook = 8;
                
                int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
                int recordFound =0; 
                
                if(read)
                {     
                    string line;
                    char key = 'A';
                    int i = 9;
	       
                    while(getline(read, line)) {
                        char temp = line[0];
                        int index = (temp - 65);
                        arr[index]=1;  
                        recordFound = 1;
                    }
                    if(recordFound == 1)
                    {
                        cout<<"\n Appointment Summary by hours:";
                        char key = 'A';
                        int hours = 9;
                        for(int i = 0; i<=12; i++)
                        {
                            if(i == 0){
                                if(arr[i] == 0) 
                                    cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
                                else
                                    cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
                            }
                            
                            else
                            {								           	
                                if(arr[i] == 0) 
                                    cout<<"\n "<<key<<"->"<<hours<<" - Available";
                                else
                                    cout<<"\n "<<key<<"->"<<hours<<" - Booked";
                            }

                            hours++; key++;
                        }
                            
                    }
                        
                    read.close();
                }

                if(recordFound == 0){
                    cout<<"\n Appointment Available for following hours :";
                    char key = 'A';

                for(int i = 9; i<=21; i++)
                {
                    if(i==9)
                        cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
                    else
                        cout<<"\n "<<key<<" -> "<<i<<" - Available";
                        key++;
                }
                
                }
   
            char choice;
            cout<<"\n\n Input your choice : ";
            cin>>choice;
        
            if( !(choice >= 'A' && choice <='Z'))
            {
            cout<<"\n Error : Invalid Selection";
            cout<<"\n Please selction correct value from menu A- Z";
            cout<<"\n Press any key to continue";
            getchar();getchar();
            system("cls");
            bookAppointment();
             }
   
        int index = (choice-65 );
        int isBooked = 1;
        if(arr[index] == 0) 
            isBooked = 0;
      
        if(isBooked ==1)
        {
            cout<<"\n Error : Appointment is already booked for this Hour";
            cout<<"\n Please select different time !!";
            cout<<"\n Press any key to continue!!";
            getchar();getchar();
            system("cls");
            bookAppointment();
        }
        
        string name;
        cout<<"\n Enter your first name:";
        cin>>name;  
        
        ofstream out;
        out.open("appointments.txt", ios::app);

        if(out){
            out<<choice<<":"<<name.c_str()<<"\n";
            out.close();
            cout<<"\n Appointment booked for Hours : "<< (choice-65) + 9 <<" successfully !!";
        }
        else{
            cout<<"\n Error while saving booking";
        }

        return 0;
}

void cancelAppointment() {
           string name;
            cout << "Enter your name to cancel appointment: ";
            cin >> name; 

            ifstream inFile("appointments.txt");
            ofstream outFile("temp.txt");
            if (!inFile) {
                cerr << "Error: Unable to open file." << endl;
                return;
            }

            bool found = false;
            string line;
            while (getline(inFile, line)) {
                size_t pos = line.find(":");
                if (pos != string::npos) {
                    string appointmentName = line.substr(pos + 1);
                    if (appointmentName == name) {
                        found = true;
                        continue;
                    }
                }
                outFile << line << endl;
            }

            inFile.close();
            outFile.close();

            if (found) {
                remove("appointments.txt");
                rename("temp.txt", "appointments.txt");
                cout << "Appointment cancelled successfully." << endl;
            } else {
                remove("temp.txt");
                cout << "Appointment not found for the given name." << endl;
            }
}

void modifyAppointment() {
    string name;
    cout << "Enter your name to modify appointment: ";
    cin >> name; 

    ifstream inFile("appointments.txt");
    ofstream outFile("temp.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    bool found = false;
    string line;
    while (getline(inFile, line)) {
        size_t pos = line.find(":");
        if (pos != string::npos) {
            string appointmentName = line.substr(pos + 1);
            if (appointmentName == name) {
                found = true;
                string newAppointment;
                cout << "Enter new appointment (format: A:NewName): ";
                cin >> newAppointment; 
                outFile << newAppointment << endl;
                break; 
            }
        }
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    if (found) {
        remove("appointments.txt");
        rename("temp.txt", "appointments.txt");
        cout << "Appointment modified successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Appointment not found for the given name." << endl;
    }
}


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
        cout << "\t4. Patient Details\n"; //does not work
        cout << "\t5. Submit Feedback\n";
        cout << "\t6. Insurance Validation\n";
        cout << "\t7. Modify Patient Info\n";

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
            {

                PatientInformationCollection b;
                fstream f1;
                char ch;
                int book_id = 1;
                
                cout << "\t\tWelcome to Patient Information Collection\n";
                cout << "\t\t---------------------------\n";

                f1.open("booking.txt", ios::out | ios::app);
                if (!f1.is_open()) {
                    cerr << "Error: Unable to open file for writing!" << endl;
                    return 1; // Exit the program with an error code
                }

                bool tag = true; 
                do {
                    b.getInfo();
                        f1 << b.patientName << " ";
                        f1 << b.patientID << " ";
                        f1 << b.dateOfBirth << " ";
                        f1 << b.patientPayment << " ";
                        f1 << b.insuranceType << " ";
                        f1 << b.currentBalance << endl;

                    //printing details to screen 
                    cout << "\n\t\tPatient Details are following\n";
                    cout << "\t\t-----------------------------\n";
                    cout.setf(ios::left);
                    cout << setw(15) << "patientName" << setw(20) << "patientID" << setw(30) << "dateOfBirth" << setw(20) << "patientPayment" << setw(12) << "insuranceType" << setw(12) << "Balance" << endl;
                    b.disInfo();

                    cout << "\n\t..........Information Saved...............\n";
                    tag = false; 
                } while (tag);

                    char c1;
                    cout << "\tPress 'q' to terminate or any other key to return to HomeScreen :- ";
                    cin >> c1;
                    if (c1 == 'q' || c1 == 'Q')
                        exit(EXIT_FAILURE);
                    else
                        goto start;
                    
            }
            break;

          case 2:
            {   
                bookAppointment(); 

                    char c1;
                    cout << "\tPress 'q' to terminate or any other key to return to HomeScreen :- ";
                    cin >> c1;
                    if (c1 == 'q' || c1 == 'Q')
                        exit(EXIT_FAILURE);
                    else
                        goto start;

            }
            break; 

        case 3:
            {    
                cancelAppointment(); 
                    char c1;
                    cout << "\tPress 'q' to terminate or any other key to return to HomeScreen :- ";
                    cin >> c1;
                    if (c1 == 'q' || c1 == 'Q')
                        exit(EXIT_FAILURE);
                    else
                        goto start;
            }
        
        break;

        case 4:
            {
                cout << "\t\tWelcome to Patient Details \n";

            }
            break;
        case 5 : 
        {

            //read all feedback info. read every single line
            Feedback b;
                fstream f1;
                char ch;
                int book_id = 1;
                f1.open("feedback.txt",ios::out | ios::app);
                cout << "\t\tWelcome to Feedback Collection\n";
                cout << "\t\t---------------------------\n";

                    b.getFeedback();
        
                    // Write feedback information as a structured record in the file
                    f1 << "Name: " << b.patientName << endl;
                    f1 << "ID: " << b.patientID << endl;
                    f1 << "Date: " << b.date << endl;
                    f1 << "Rating: " << b.rating << endl;
                    f1 << "---------------------------" << endl;


                    cout << "\n\t\tFeedback Details are the following\n";
                    cout << "\t\t-----------------------------\n";
                    cout.setf(ios::left);
                    cout <<setw(15)<< "patientName" <<setw(20)<< "patientID" <<setw(30)<< "date" <<setw(20)<< "rating" <<endl;
                    b.disInfo();
                    
                cout << "\n\t..........Information Saved...............\n";

                // Clear input buffer before prompting for further input
                cin.clear(); // Clear any errors
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input buffer

                char c1;
                cout << "\tPress 'q' to terminate or any other key to return to HomeScreen :- ";
                cin >>c1;
                if(c1 == 'q' || c1 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
                f1.close();
        }
        break;

        case 6 : 
        {
                cout << "\t\tWelcome to Insurance Validation \n";
                cout << "\t\t---------------------------\n";
                PatientInformationCollection p;
                fstream f6;
                //REMOVE BINARY
                f6.open("booking.txt",ios::in|ios::out|ios::binary);
                f6.seekg(0,ios::beg);
                f6.read((char *)&p,sizeof(p));
                cout.setf(ios::left);
                string acceptedInsurances[3] = {"alien", "zombie","unicorn"}; 

                string target_name; 
                cout << " What is your name? " << endl; 
                cin >> target_name; 
               
                while(f6)
                {
                    if (p.patientName == target_name)
                    {
                        
                    
                    //chnage insurance type to all lowercase 
                    transform(p.insuranceType.begin(), p.insuranceType.end(), p.insuranceType.begin(), ::tolower);
                    bool accepted = false;
                    for (int i = 0; i < 3; i++) {
                        if (p.insuranceType == acceptedInsurances[i]){
                            accepted = true;
                            break;
                        }
                    }

                    if (accepted) {
                        cout << "You Insurance is accepted." <<endl;
                    } else {
                        cout << "You Insurance is not accepted." << endl;
                    }
                    }
                        f6.read((char *)&p,sizeof(p));
                    
                }

                f6.close();

                char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
        }
        break; 

        case 7 : 
        {
            modifyAppointment(); 


            char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
                    
        }
    }
}