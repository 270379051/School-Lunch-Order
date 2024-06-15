//
//  introduction.cpp
//  introduction
//
//  Created by Harshdeep Singh on 15/06/2024.
//

#include "introduction.hpp"
void printHeading() {
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| _________   _      _   _____    _      _     _   __       _   _____   _      _    ________   __________   __________   _________  |" << endl;
    cout << "||___   ___| | |    | | | ____|  | |    | |   | | |   `    | | |  ___| | |    | |  |  ______| |  ______  | |  ______  | |___   ___| |" << endl;
    cout << "|    | |     | |____| | | |___   | |    | |   | | | |` `   | | | |     | |____| |  |  |       | |______| | | |      | |     | |     |" << endl;
    cout << "|    | |     | |____| | |  ___|  | |    | |   | | | | ` `  | | | |     | |____| |  |  |_____  | _________| | |      | |     | |     |" << endl;
    cout << "|    | |     | |    | | | |      | |    | |   | | | |  ` ` | | | |     | |    | |  |______  | | |          | |      | |     | |     |" << endl;
    cout << "|    | |     | |    | | | |___   | |___ | |___| | | |   ` `| | | |___  | |    | |   ______| | | |          | |______| |     | |     |" << endl;
    cout << "|    |_|     |_|    |_| |_____|  |_____||_______| |_|    `___| |_____| |_|    |_|  |________| |_|          |__________|     |_|     |" << endl;
    cout << "|                                                                                                                                   |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void list_options() {
    cout << "1. Weekly Menu" << endl
         << "2. Discounts" << endl
         << "3. Login and Registration for Parents" << endl
         << "4. Login and Registration for Staff" << endl
         << "5. Admin Login" << endl;
}
int get_option() {
    int option;
    bool valid = false;

    while (!valid) {
        cout << "Enter the task number you want to do: ";
        cin >> option;

        if (option >= 1 && option <= 5) {
            valid = true;
        } else {
            cout << "Please enter a valid task number!!" << endl;
        }
    }
    return option;
}
void login_registerparent() {
    int option1;
    cout << "1. Login" << endl << "2. Registration" << endl;
    cout << "Enter 1 for Login and 2 for Registration: ";
    cin >> option1;
    cin.ignore(); // Clear the newline character from the input buffer
    if (option1 == 1) {
        parentlogin_here();
    } else if (option1 == 2) {
        parent_registration();
    } else {
        cout << "Please enter a valid option!" << endl;
        login_registerparent();
    }
}

