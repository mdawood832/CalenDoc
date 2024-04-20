#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
using namespace std;


//CHANGES - cancellation fee for cancelling an appointment instead of late fee
//copay calculation for patient 

class PatientInformationCollection
{
    public :
        char patientName[20];
        int patientID;
        char dateOfBirth[10];
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


//appointment class
//NOTE: does not have option where you dont book overlapping appointments 
class Appointment
{
    public :
    char patientName[20];
    char date[10];
    char time[5];
    char type[20];
    int cancellationFee = 50; 
    // string availabilty; 
    // string appointmentStatus; 
    // string currentAppointments; 

    
        void appointmentInfo()
        {
            cout << "Enter Patient's Name (all lowercase): ";
            cin >> patientName; 

            cout << "Date of Appointment Monday-Friday ( DD/MM/YYYY ): ";
            cin >> date;

            cout << "Time of Appointment 9am-5pm (00:00): ";
            cin >> time;

            cout << "Type of Appointment: "; 
            cin >> type;
        }

        // void chargeCancellationFee( )
        // {
        //     currentBalance = currentBalance + cancellationFee; 
        // }
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

//PASS BY REFERNCE IF MOVED TO ANOTHER FILE 
bool hasConflict(const Appointment& newAppointment, const vector<Appointment>& appointments) {
    for (int i = 0; i < appointments.size(); ++i) {
        const Appointment& existingAppointment = appointments[i];
        if (strcmp(existingAppointment.date, newAppointment.date) == 0 &&
            strcmp(existingAppointment.time, newAppointment.time) == 0) {
            return true; // Conflict found
        }
    }
    return false; // No conflict found
}

// bool hasConflict(const Appointment newAppointment, const vector<Appointment> appointments) {
//     for (int i = 0; i < appointments.size(); ++i) {
//         const Appointment existingAppointment = appointments[i];
//         if (strcmp(existingAppointment.date, newAppointment.date) == 0 &&
//             strcmp(existingAppointment.time, newAppointment.time) == 0) {
//             return true; 
//         }
//     }
//     return false; 
// }

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
        cout << "\t4. Patient Details\n";
        cout << "\t5. Submit Feedback\n";
        cout << "\t6. Insurance Validation\n";
        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;
        if(choice<1 || choice >6)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            k++;
        }
    }while (k != 0);

    switch (choice)
    {
        case 1: //problem with this is that it only makes one isntance of the information and then deletes the last patient 
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
                        f1 << "Name: " << b.patientName << endl;
                        f1 << "ID: " << b.patientID << endl;
                        f1 << "Date of Birth: " << b.dateOfBirth << endl;
                        f1 << "Payment: " << b.patientPayment << endl;
                        f1 << "Insurance Type: " << b.insuranceType << endl;
                        f1 << "Balance: " << b.currentBalance << endl;
                        f1 << "---------------------------" << endl;

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
                    

                
               
            

                // PatientInformationCollection b;
                // fstream f1;
                // char ch;
                // int book_id = 1;
                // f1.open("booking.txt",ios::in|ios::out|ios::app|ios::binary);
                // cout << "\t\tWelcome to Patient Information Collection\n";
                // cout << "\t\t---------------------------\n";

                //     b.getInfo();
                //     f1.write((char *)&b , sizeof(b));

                //     cout << "\n\t\tPatient Details are following\n";
                //     cout << "\t\t-----------------------------\n";
                //     cout.setf(ios::left);
                //     cout <<setw(15)<< "patientName" <<setw(20)<< "patientID" <<setw(30)<< "dateOfBirth" <<setw(20)<< "patientPayment" <<setw(12)<< "insuranceType"<<setw(12)<<"Balance"<<endl;
                //     b.disInfo();
                    
                // cout << "\n\t..........Information Saved...............\n";

                // char c1;
                // cout << "\tPress 'q' to terminate or any other key to return to HomeScreen :- ";
                // cin >>c1;
                // if(c1 == 'q' || c1 == 'Q')
                //     exit(EXIT_FAILURE);
                // else
                //     goto start;
                // f1.close();
            }
            break;

          case 2:
            {
                //vector of appointment called appointments
                vector<Appointment> appointments;
                fstream f2;
                // storing appointments in appointment txt
                f2.open("appointment.txt",ios::in|ios::out|ios::app);
                
                char c2 = 'Y';
                while (c2 == 'Y' || c2 == 'y') {
                    Appointment newAppointment;
                    newAppointment.appointmentInfo();

                    // Check for conflicts
                    if (hasConflict(newAppointment, appointments)) {
                        cout << "Sorry, the selected time slot is not available. Please choose another time.\n";
                    } else {
                        // No conflict, add the appointment
                        f2.write((char*)&newAppointment, sizeof(newAppointment));
                        appointments.push_back(newAppointment);
                        cout << "Appointment scheduled successfully!\n";
                    }

                    // Clear input buffer before prompting for further input
                    cin.clear(); // Clear any errors
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input buffer

                    cout << "Enter 'Y' to schedule another appointment or any other key to quit: ";
                    //or go back to homepage 
                    cin >> c2;
                    
                }
                

            }
            break; 

        case 3:
        //include cancellation fee 
            {
                Appointment c; 
                fstream f4,fr;
                //change binary
                f4.open("appointment.txt",ios::in|ios::out|ios::binary); 
                fr.open("b.txt",ios::in|ios::out|ios::binary|ios::app);

                char name[20];
                cout << "Under which name do you want to delete the appointment :- ";
                cin >> name;

                f4.seekg(0,ios::beg);
                f4.read((char*)&c,sizeof(c));
                while (f4.eof() != 1)
                {
                    if(strcmp(name,c.patientName) != 0)
                        fr.write((char *)&c,sizeof(c));
                    f4.read((char*)&c,sizeof(c));
                }

                cout << "\n\t******Ticket Cancellation Successful******\n";
                // charging fee for cancel
                // c.chargeCancellationFee(); 
                remove ("appointment.txt");
                rename ("b.txt","appointment.txt");

                f4.close();
                fr.close();
                char c5;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c5;

                if(c5 == 'q'|| c5 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
            }
            break;


        //adjusted it so it only shows the name of one patient, we have to actually write the name 
        //of the patient so it only prints their information and not everyone elses 
        case 4:
            {

                PatientInformationCollection p;
                int count = 0;
                fstream f6;
                f6.open("booking.txt",ios::in|ios::out|ios::binary);
                f6.seekg(0,ios::beg);
                f6.read((char *)&p,sizeof(p));
                cout.setf(ios::left);
                cout <<endl;
                cout <<setw(15)<< "patientName" <<setw(20)<< "patientID" <<setw(30)<< "dateOfBirth" <<setw(20)<< "patientPayment" <<setw(12)<< "insuranceType" <<setw(30)<< "Balance"<<endl;


                //CHANGE NAME TO TARGET SPECIFIC PATIENT 
                string target_name = "maryam"; // Change this to the name you want to search for

                while(f6)
                {
                    // Assuming p.getName() returns the name of the booking
                    if (p.patientName == target_name)
                    {
                        p.disInfo(); // Display the booking information
                        count++;
                    }
                    f6.read((char *)&p,sizeof(p));
                }

                f6.close();

                // cout << "\n\tTotal Number of passengers with name "<< target_name <<" is "<<count<<endl;
                char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;

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
        case 6 : {
                PatientInformationCollection p;
                fstream f6;
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
    }
}

