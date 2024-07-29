#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int row = 0;

struct {             // Structure declaration
    string username;
    string password;
    string name;
    int age;
    string address;
    string contact_number;
    string category; // empty if negative
    string date;
} User;       // Structure variable

vector<string> parse(const string& str, const char& ch) {
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        }
        else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}

bool login() {
    //ask user to key in username and password to login to theri account
    fstream file;
    string username;
    string password;
    string record; // get record from user.txt file to identify username and password
    bool auth=false;
    vector<string> result;

    cout << "\n\t\t\t\t************************************************************";
    cout << "\n\t\t\t\t*             COVID-19 MANAGEMENT SYSTEM LOGIN             *";
    cout << "\n\t\t\t\t************************************************************";

    cout << "\n\n\t\t -->> ENTER USERNAME: ";
    cin >> username;
    cout << "\n\n\t\t -->> ENTER PASSWORD: ";
    cin >> password;
    
    file.open("user.txt", ios::in);
    if (!file) {
        cout << "Error opening file\n";
    }
    else {
        while (file) {
            getline(file,record);
            row++;
            result = parse(record, ';');
            User.username = result[0];
            User.password = result[1];
            User.name = result[2];
            User.age = stoi(result[3]);
            User.contact_number = result[4];
            User.address = result[5];
            User.category = result[6];
            User.date = result[7];
            if (username == User.username && password == User.password)
            {
                auth = true;
                break;
            }
            /*else {
                cout << "\n\n\n\t\t\t\tINVALID USERNAME OR PASSWORD!!! PLEASE RETRY AGAIN.\n\n";
                exit(0);
            }*/
        }
    }
    file.close();
   
    return auth;
}



void register_user() 
{
    fstream file; 

    system("cls");

    cout << "\n\t\t\t\t************************************";
    cout << "\n\t\t\t\t*             REGISTER             *";
    cout << "\n\t\t\t\t************************************";
    //username//passowrd
    cout << "\n\n\t\t -->> ENTER NAME: ";
    getline(cin,User.name);
    cout << "\n\n\t\t -->> ENTER AGE: ";
    while (!(cin >> User.age))
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nInvalid Age... \t Enter Again: ";
    }
    cin.clear();
    cin.ignore(256, '\n');
    cout << "\n\n\t\t -->> ENTER CONTACT NUMBER: ";
    getline(cin, User.contact_number); 
    cout << "\n\n\t\t -->> ENTER ADDRESS: ";
    getline(cin, User.address);
    cout << "\n\n\t\t -->> ENTER DATE(dd/mm/yy): ";
    getline(cin, User.date);

    file.open("user.txt",ios::app); //open file to save registered information of user
    file << User.username << ";" << User.password << ";" <<User.name <<";" << User.age << ";" << User.contact_number << ";" << User.address <<";C" << ";" << User.date << endl; //username//password
    file.close();

}

void show_status() {
    system("cls");
    cout << "Category A - TESTED POSITIVE COVID-19\n" << "Category B - SUSPECTED CLOSE CONTACT WITH COVID-19 PATIENT\n" << "Category C - TESTED NEGATIVE COVID-19 OR NORMAL CONTACT " << endl;
    cout << "\n\n\t\t -->> NAME: " << User.name << endl;
    cout << "\n\n\t\t -->> AGE: " << User.age << endl;
    cout << "\n\n\t\t -->> CONTACT NUMBER: " << User.contact_number << endl;
    cout << "\n\n\t\t -->> ADDRESS: " << User.address << endl;
    cout << "\n\n\t\t -->> COVID CATEGORY: " << User.category << endl;
    cout << "\n\n\t\t -->> DATE OF LAST RECORD: " << User.date << endl;

    /* Category A = positive covid - 19
       Category B = suspected close contact with COVID-19 patient
       Category C = negative covid-19          */
    if (User.category == "A") {
        cout << "\n\n\n\t\t\t**************************************************";
        cout << "\n\t\t\t*             TESTED POSITIVE COVID-19           *";
        cout << "\n\t\t\t**************************************************\n\n\n";
        cout << "\n(Staff/Student who have been confirmed case of postive COVID-19)\n\n";
        cout << "Suggested action(s) to be taken.\n\n";
        cout << "1. Vaccination status on My Sejahtera must be verify.\n"; 
        cout << "2. Hospital Quarantine or Home Surveillance Order (HSO) subjected to MOH instructions.\n";
        cout << "3. Report to immediate supervisor/respective lecturer.\n";
        cout << "4. Report to Bilik Gerakan for close monitoring and sanitisation process.\n";
        cout << "5. Hospitalisation Leave will be granted upon receiving supporting documentation.\n\n\n";
        cout << "\t\t\tQUARANTINE OF POSITIVE COVID-19 PATIENTS\n\n";
        cout << "-The quarantine period was the same for asymptomatic or symptomatic.\n";
        cout << "i.  COVID-19 positive cases must be quarantine 7 days.\nii. However, they can be released earlier if they tested negative on 4 days.\niii.The RTK-AG Covid-19 test on Day 4 of quarantine needs to be supervised by medical practitioner.\n"; 
    }
    else if (User.category == "B") {
        cout << "\n\n\n\t\t\t**********************************************************************";
        cout << "\n\t\t\t*            SUSPECTED CLOSE CONTACT WITH COVID-19 PATIENT           *";
        cout << "\n\t\t\t**********************************************************************\n\n\n";
        cout << "(Staff/Student who have been (SUSPECTED) close contact with individuals from category A)\n\n";
        cout << "Suggested action(s) to be taken.\n\n";
        cout << "-For Asymptomatic cases:For Symptomatic cases:\n";
        cout << "1. No quarantine is needed OR 3 days quarantine (if staying with tested positive COVID - 19 family members and roommates).\n";
        cout << "2. No test is required (either required by KKM / UTAR BG) OR RTK(Ag) self-test on day 1 and day 3 (if staying with tested positive COVID - 19 family members and roommates).\n";
        cout << "3. Release from quarantine if RTK(AG) Self-test result on day 3 is negative.\n\n";
        cout << "-For Symptomatic cases:\n";
        cout << "1. 3 days of quarantine is needed.\n";
        cout << "2. RTK(Ag) self-test is needed to be done on day 1 and day 3.\n";
        cout << "3. Release from quarantine if RTK(AG) Self-test result on day 3 is negative and symptoms have improved.\n\n";
        cout << "(CATEGORY CHANGES BASED ON COVID - 19 TEST)\n";
        cout << "i.  If Category B is tested COVID-19 + ve, B will become A.\n";
        cout << "ii. If Category B is tested COVID-19 – ve, student is allowed to work/study as usual and access campus after completion of the three-day quarantine period, the RTK(AG) self - test results on the 3rd day were negative and no symptoms or improved.";

    }
    else if (User.category == "C") {
        cout << "\n\n\n\t\t\t********************************************************************";
        cout << "\n\t\t\tt*            TESTED NEGATIVE COVID-19 OR NORMAL CONTACT           *";
        cout << "\n\t\t\t********************************************************************\n\n\n";
        cout << "(Staff/Student who were likely exposed to another person infected with COVID - 19)\n\n";
        cout << "Suggested action(s) to be taken.\n\n";
        cout << "1. Students or staffs are not require to self-isolate and can work/study as usual.\n";
        cout << "2. Students or staffs are require to be put under monitoring list.\n\n";
        cout << "3. If casual contact symptomatic, students or staffs are allowed to access on campus if Covid-19 test result is negative.  \n";
        cout << "4. If casual contact no symptomatic, students or staffs are allowed to work/study as usual and access campus in accordance with UTAR’s SOPs / procedures.\n";

    }
    system("pause"); // pause if no cin from user to update status
}

void update_status() {

    int choice1; //choice 1 is the choice of category A/B/C
    string category;
    string record;
    string date;
    int A, B, C;
    int i = 0;
    system("cls");
    //cin category
    
    fstream file,temp; 
    file.open("user.txt", ios::in);
    temp.open("temp.txt", ios::app);
    cout << "\n\t\t\t\t\t           Hi " << User.name << "!           ";
    cout << "\n\t\t\t\t****************************************************";
    cout << "\n\t\t\t\t*             UPDATE COVID-19 CATEGORY             *";
    cout << "\n\t\t\t\t****************************************************";

    cout << "\n\nCategory A - positive COVID-19\nCategory B - suspected close contact with COVID-19 patient\nCategory C - negative COIVD-19";
    cout << "\n\n\nPLEASE CHOOSE YOUR CATEGORY TO UPDATE";
    cout << "\n\n\t\t 1. A";
    cout << "\n\t\t 2. B";
    cout << "\n\t\t 3. C";
    cout << "\n\t\t 4. EXIT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> choice1;
    cin.clear();
    cin.ignore(256, '\n');

    
    switch (choice1)
    {
    case 1:
        if (!file) {
            cout << "Error opening file\n";
        }
        else {
            while (getline(file, record)) {


                i++;
                if (i == row) {
                    User.category = category = "A";
                    User.date = date;
                    cout << "PLEASE ENTER CURRENT DATE(DD/MM/YY): ";
                    cin >> date;
                    temp << User.username << ";" << User.password << ";" << User.name << ";" << User.age << ";" << User.contact_number << ";" << User.address << ";" << category << ";" << date << endl;
                    
                }
                else {
                    temp << record << endl;
                }
            }
        }
        break;
    case 2:
        if (!file) {
            cout << "Error opening file\n";
        }
        else {
            while (getline(file, record)) {


                i++;
                if (i == row) {
                    User.category = category = "B";
                    User.date = date;
                    cout << "PLEASE ENTER CURRENT DATE(DD/MM/YY): ";
                    cin >> date;
                    temp << User.username << ";" << User.password << ";" << User.name << ";" << User.age << ";" << User.contact_number << ";" << User.address << ";" << category << ";" << date << endl;
                    
                }
                else {
                    temp << record << endl;
                }
            }
        }
        break;
    case 3:
        if (!file) {
            cout << "Error opening file\n";
        }
        else {
            while (getline(file, record)) {


                i++;
                if (i == row) {
                    User.category = category = "C";
                    User.date = date;
                    cout << "PLEASE ENTER CURRENT DATE(DD/MM/YY): ";
                    cin >> date;
                    temp << User.username << ";" << User.password << ";" << User.name << ";" << User.age << ";" << User.contact_number << ";" << User.address << ";" << category << ";" << date << endl;
                    
                }
                else {
                    temp << record << endl;
                }
            }
        }
        

            break;
    case 4:
        exit(0);
        break;

    default:
        system("cls");
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";

        }

    
    file.close();
    temp.close();
    remove("user.txt"); //remove the file with old record user.txt file and replace it with the temp.txt file that contains new record.
    rename("temp.txt", "user.txt");
    return;//rename the new temp.txt file to user.txt file 
}



void menu() {
    system("cls");

A:
    int choice;

    cout << "\n\t\t\t\t           Hi "<< User.name <<"!           ";

    cout << "\n\t\t\t\t*******************************************";
    cout << "\n\t\t\t\t*             COVID-19 STATUS             *";
    cout << "\n\t\t\t\t*******************************************";

    // MAIN MENU
    cout << "\n\n\t\t -->> MAIN MENU <<--";
    cout << "\n\n\t\t 1. SHOW STATUS";
    cout << "\n\t\t 2. UPDATE STATUS";
    cout << "\n\t\t 3. EXIT";
    cout << "\n\n\t\t -->> ADMIN OPTION <<--";
    cout << "\n\n\t\t 4. REGISTER";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> choice;
    cin.clear();
    cin.ignore(256, '\n');

    
        switch (choice)
        {
        case 1:
            show_status();
            system("cls");
            goto A;
            break;
        case 2:
            update_status();
            system("cls");
            goto A;
            break;
        case 3:
            exit(0);
            break;
        case 4:
            register_user();
            system("cls");
            goto A;
            break;
        default:
            system("cls");
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
            goto A;
        }
    }



int main()
{
    bool auth = true; // default false

    B:
        auth = login();
        system("cls");
        if (!auth) {
         
            cout << "INCORRECT USERNAME OR PASSWORD!!! ";
           goto B;
        }

    menu();
    
    
}
