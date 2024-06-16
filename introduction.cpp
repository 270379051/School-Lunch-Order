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
void parent_registration() {
    Details temp;

    cout << "Enter full name: ";
    cin.ignore(); // Ignore any leftover newline character in the input buffer
    getline(cin, temp.name);

    cout << "Enter gender (M for male / F for female): ";
    cin >> temp.gender;
    cin.ignore(); // Clear the newline character from the input buffer

    cout << "Enter date of birth (DOB): ";
    getline(cin, temp.DOB);

    cout << "Enter contact number: ";
    getline(cin, temp.contact);

    cout << "Enter Visa card number: ";
    getline(cin, temp.visacardnumber);

    cout << "Enter Visa card expiry date: ";
    getline(cin, temp.visacardexpiry);

    cout << "Enter your username: ";
    getline(cin, temp.username);

    password_check(temp);

    parentinfo.push_back(temp);

    cout << "\nPlease check registered details" << endl;
    for (const auto& parent : parentinfo) {
        cout << "Full name: " << parent.name << endl;
        cout << "Gender: " << parent.gender << endl;
        cout << "Date of Birth: " << parent.DOB << endl;
        cout << "Contact number: " << parent.contact << endl;
        cout << "Visa card number: " << parent.visacardnumber << endl;
        cout << "Visa card expiry date: " << parent.visacardexpiry << endl;
        cout << "Username: " << parent.username << endl;
        cout << "--------------------------------------" << endl;
    }
}
void parentlogin_here() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cin.ignore(); // Clear the newline character from the input buffer

    bool user_found = false;
    for (auto& parent : parentinfo) {
        if (username == parent.username) {
            user_found = true;
            cout << "Enter your password: ";
            getline(cin, password);

            if (password == parent.password) {
                cout << "Hello! " << parent.name << ", you logged in successfully!" << endl;
            } else {
                cout << "Incorrect password! Please try again." << endl;
                // Ideally, you should implement a limited number of retries to avoid infinite loop
            }
            break;
        }
    }
void admin_login() {
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cin.ignore(); // Clear the newline character from the input buffer
    cout << "Enter admin password: ";
    getline(cin, password);

    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
        cout << "Admin login successful!" << endl;
        // Placeholder for admin functionalities
        cout << "Welcome, Admin! [Admin functionalities will be implemented here]" << endl;
    } else {
        cout << "Invalid admin credentials. Please try again." << endl;
    }
}
void contact_details() {
    cout << "_____________________________________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\t\t The Lunch Spot\t **All Rights Reserved**" << endl;
    cout << "_____________________________________________________________________________________________________________________________________" << endl;
    cout << "Welcome to our School Lunch Service!\nWe believe in Quality and Customer Satisfaction.\n";
    cout << "\n\nContact Details- 0234123443 , 0787890907\n";
    cout << "223 VDR ROAD , AUXXL\n";
    cout << "_____________________________________________________________________________________________________________________________________" << endl;
}
