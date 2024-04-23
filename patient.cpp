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
            cout << "Enter Patient's Name: "; 
            cin.get();
            cin >> patientName; // HAYDEN: convert to all lower or upper

            cout << "Enter Patient ID: ";
            cin >> patientID;

            cout << "Date of Birth( DDMMYYYY): ";
            cin >> dateOfBirth; // HAYDEN: make sure it's 8 characters

            cout << "Enter your Credit Card Number: ";
            cin >> patientPayment; //HAYDEN: 15 digit credit card number 

            cout <<"Enter your Insurance Type (alien, zombie, unicorn): ";
            cin >> insuranceType; // HAYDEN: make sure it's these 3 options

            ofstream out; 
            out.open("patientInfo.txt", ios::app); 

            out << patientName.c_str()<< ":" << patientID << ":" << dateOfBirth << ":" << patientPayment << ":" <<
            insuranceType << "\n";

            out.close();
        
    }

        void disInfo()
        {
            cout.setf(ios::left);
            cout <<setw(15)<< patientName <<setw(20)<< patientID <<setw(30)<<dateOfBirth <<setw(20)<<patientPayment <<setw(30)<< insuranceType<<setw(30)<<currentBalance<<endl;
        }


        // search patient for details for Option #4
        void findPatientInfo()
        {

            return; 
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

void patientInformationCollection () {
               PatientInformationCollection b;
                fstream f1;
                char ch;
                int book_id = 1;
                
                cout << "\t\tWelcome to Patient Information Collection\n";
                cout << "\t\t---------------------------\n";

                f1.open("patientInfo.txt", ios::out | ios::app);
                if (!f1.is_open()) {
                    cerr << "Error: Unable to open file for writing!" << endl;
                }

                bool tag = true; 
                do {
                    b.getInfo();
  

                    //printing details to screen 
                    cout << "\n\t\tPatient Details are following\n";
                    cout << "\t\t-----------------------------\n";
                    cout.setf(ios::left);
                    cout << setw(15) << "patientName" << setw(20) << "patientID" << setw(30) << "dateOfBirth" << setw(20) << "patientPayment" << setw(12) << "insuranceType" << setw(12) << "Balance" << endl;
                    b.disInfo();

                    cout << "\n\t..........Information Saved...............\n";
                    tag = false; 
                } while (tag);
}

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

std::string dayofWeek(char day) {
    
    if (day == 'A')
        return "Monday";
        
    else if (day == 'B')
        return "Tuesday";
        
    else if (day == 'C')
        return "Wednesday";
        
    else if (day == 'D')
        return "Thursday";
        
    else
     return "Friday";
}

void viewAppointments() {

    cout << "Select an Appointment Day\n";
    cout << "-------------------------\n";
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    int userChoice;

    cout << endl;
    cout << "Select a Day: ";
    cin >> userChoice;

    cout << "\n ----- Book Your Appointment ---- \n";	
    cout << "\n ----- Availbale slots ---- \n";	 
    
    // opens file object
    ifstream read;
    
    
        if (userChoice == 1)
        {
               cout << "\n ----- Monday ----------- \n";	 
            read.open("Monday.txt");
        }

        else if (userChoice == 2)
        {
            read.open("Tuesday.txt");
        }

        else if (userChoice == 3)
        {
            read.open("Wednesday.txt");
        }

        else if (userChoice == 4)
        {
            read.open("Thursday.txt");
        }

        else 
        {
            read.open("Friday.txt");
        }
   
        int numOfHours = 8;
        int recordFound = 0;
        int arr[numOfHours];

    // initialize array
    for (int j = 0; j < numOfHours; j++)
    {
        arr[j] = 0;
    }
        string line;
        
    
    
    if (read)
    {
        // loop to mark appointment was recordFound
        while (getline(read, line))
        {
            char temp = line[0];
            int index = (temp - 65);
            arr[index] = 1;
            recordFound = 1; 
        }
        
    }
    
    read.close();
    
    char key = 'A';
    int hour = 8;
    
    // display availability 
    for (int i = 0; i < numOfHours; i++)
    {
        if (arr[i] == 1)
        {
            cout << "\n" << key << "->" << hour << ":00" << " - Booked";
           

        }
        else
            {
                cout << "\n" << key << "->" << hour << ":00" << " - Available";
            }
            
        key++;
        hour++;

    }

    char bookAnother;
    cout << endl;
    cout << "\n\nWould you like to see other appointments?\n" << endl;
    cout << "Enter y or n: ";
    cin >> bookAnother;

    while (bookAnother == 'y' || bookAnother == 'Y')
{
    cout << "Select an Appointment Day\n";
    cout << "-------------------------\n";
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    cout << endl;
    cout << "Select a Day: ";
    cin >> userChoice;

    viewAppointments();

    cout << endl;
    cout << "\n\nWould you like to see other appointments?\n" << endl;
    cout << "Enter y or n: ";
    cin >> bookAnother;
}

   
return; 

};

void bookAppointments(){

start :
    cout << "Select an Appointment Day\n";
    cout << "-------------------------\n";
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    int userChoice;

    cout << endl;
    cout << "Select a Day: ";
    cin >> userChoice;

    cout << "\n ----- Book Your Appointment ---- \n";	
    cout << "\n ----- Availbale slots ---- \n";	 
    
    // opens file object
    ifstream read;
    
        if (userChoice == 1)
        {
               cout << "\n ----- Monday ----------- \n";	 
            read.open("Monday.txt");
        }

        else if (userChoice == 2)
        {
            read.open("Tuesday.txt");
        }

        else if (userChoice == 3)
        {
            read.open("Wednesday.txt");
        }

        else if (userChoice == 4)
        {
            read.open("Thursday.txt");
        }

        else 
        {
            read.open("Friday.txt");
        }
   
        int numOfHours = 8;
        int recordFound = 0;
        int arr[numOfHours];

    // initialize array
    for (int j = 0; j < numOfHours; j++)
    {
        arr[j] = 0;
    }

    string line;
        
    

    if (read)
    {
        // loop to mark appointment was recordFound
        while (getline(read, line))
        {
            char temp = line[0];
            int index = (temp - 65);
            arr[index] = 1;
            recordFound = 1; 
        }
        
    }
    
    read.close();
    
    char key = 'A';
    int hour = 8;
    
    // display availability 
    for (int i = 0; i < numOfHours; i++)
    {
        if (arr[i] == 1)
        {
            cout << "\n" << key << "->" << hour << ":00" << " - Booked";
           

        }
        else
            {
                cout << "\n" << key << "->" << hour << ":00" << " - Available";
            }
            
        key++;
        hour++;

    }

    char seeAnother;
    cout << endl;
    cout << "\n\nWould you like to see other appointments?\n" << endl;
    cout << "Enter y or n: ";
    cin >> seeAnother;

    while (seeAnother == 'y' || seeAnother == 'Y')
{
    cout << "Select an Appointment Day\n";
    cout << "-------------------------\n";
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    cout << endl;
    cout << "Select a Day: ";
    cin >> userChoice;

    bookAppointments();

    cout << endl;
    cout << "\n\nWould you like to see another appointment day?\n" << endl;
    cout << "Enter y or n: ";
    cin >> seeAnother;
}
    char choice;
    cout<<"Input your desired appointment time: ";
    cin>>choice;

         // method to book the appointment 
        int index = (choice-65 );
        int isBooked = 1;

        // identies if the time slot is booked
        if(arr[index] == 0) 
            isBooked = 0;

        else
            { 
            cout << "\n Error : Appointment is already booked for this Hour";
            cout << "\n Please select different time !!";
            goto start;
            }

        string name;
        cout << "Enter your first name:";
        cin >> name;  

        ofstream out;

        if (userChoice == 1)
        {
            out.open("Monday.txt", ios::app);
        }

        else if (userChoice == 2)
        {
            out.open("Tuesday.txt", ios::app);
        }

        else if (userChoice == 3)
        {
            out.open("Wednesday.txt", ios::app);
        }

        else if (userChoice == 4)
        {
            out.open("Thursday.txt", ios::app);
        }

        else 
        {
            out.open("Friday.txt", ios::app);
        }

        if(out){
            out<<choice<<":"<<name.c_str()<<"\n";
            out.close();
            cout<<"\n Appointment booked for Hours : "<< (choice-65) + 9 <<" successfully !!";
        }
        else{
            cout<<"\n Error while saving booking";
        }

        out.close();


}

void cancelAppointment() {

           string name;
           string day;
           int dayPlaceHolder;    

            // prompts user for name and appointment day 
            cout << "Enter your name to cancel appointment: ";
            cin >> name; 
            cout << "Enter your appointment day: ";
            cin >> day;

            ifstream inFile;
            ofstream outFile("temp.txt");

            // opens respective day file and a temp file
            if (day == "Monday" || day == "monday")
            {
                inFile.open("Monday.txt");
                dayPlaceHolder = 1;
               
            }
            else if (day == "Tuesday" || day == "tuesday")
            {
                inFile.open("Tuesday.txt");
                dayPlaceHolder = 2;
            }
            else if (day == "Wednesday" || day == "wednesday")
            {
                inFile.open("Wednesday.txt");
                dayPlaceHolder = 3;
            }
            else if (day == "Thursday" || day == "thursday")
            {
                inFile.open("Thursday.txt");
                dayPlaceHolder = 4;
            }
            else
            {
                inFile.open("Friday.txt");
                dayPlaceHolder = 5;
            }




            // input validation 
            if (!inFile) {
                cerr << "Error: Unable to open file." << endl;
                return;
            }

            // searches for name
            bool found = false;
            string line;

            // loop reads original day file 
            while (getline(inFile, line)) {
                size_t pos = line.find(":");

                // identifies if name appears in original day file 
                if (pos != string::npos) {
                    string appointmentName = line.substr(pos + 1);
                    if (appointmentName == name) {
                        found = true;
                        continue;
                    }
                }

                // writes all other appointments into temp.txt file 
                outFile << line << endl;
            }

            // closes all files 
            inFile.close();
            outFile.close();

            // method to update appointment files 
            switch(dayPlaceHolder)
            {
                case (1):
                {
                    // clears original file 
                    // reassign name of temp.txt with original day file name
                    // reassign name of original day file to "text.txt"
                    if (found) 
                    {
                        remove("Monday.txt");
                        rename("temp.txt", "Monday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    }
                    else
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break;
                
                case (2): 
                {
                    if (found) 
                    {
                        remove("Tuesday.txt");
                        rename("temp.txt", "Tuesday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break; 

                case 3: 
                {
                    if (found) 
                    {
                        remove("Wednesday.txt");
                        rename("temp.txt", "Wednesday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break; 

                case 4: 
                {
                    if (found) 
                    {
                        remove("Thursday.txt");
                        rename("temp.txt", "Thursday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break; 

                case 5: 
                {
                    if (found) 
                    {
                        remove("Thursday.txt");
                        rename("temp.txt", "Thursday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break; 



            }


    
}

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

void getFeedback(){
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

void validateInsurance(){
        cout << "\t\tWelcome to Insurance Validation \n";
        cout << "\t\t---------------------------\n";

        string insuranceType; 
        cout << "Enter your insurance type (lowercase): " << endl; 
        cin >> insuranceType;
        string acceptedInsurances[3] = {"alien", "zombie","unicorn"};
                    int count = 0; 
                    for (int i = 0; i < 3; i++) {
                        if (insuranceType == acceptedInsurances[i]){
                            count = 1; 
                        }          
                    }

                    if(count ==1){
                        cout << "Your insurance is accepted." << endl; 
                    } else {
                        cout << "Your insurance is NOT accepted." << endl; 
                    }
}

int main(); 

void goToStart(){
                char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    main(); 
}

int main()
{
start: 
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
        cout << "\t4. Submit Feedback\n";
        cout << "\t5. Insurance Validation\n";
        cout << endl;

        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;
        if(choice<1 || choice >5)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            k++;
        }
    }while (k != 0);


    switch (choice)
    {
        case 1:  
            {
                patientInformationCollection(); 
                goToStart(); 
            }
            break;

          case 2:
            {   
                bookAppointments(); 
                goToStart(); 

            }
            break; 

        case 3:
            {    
                cancelAppointment(); 
                goToStart(); 
            }
        break;

        case 4 : 
            {

                getFeedback(); 
                goToStart(); 
            }
        break;

        case 5 : 
            {

                    validateInsurance(); 
                    goToStart(); 
            }
        break; 

    }
}

 