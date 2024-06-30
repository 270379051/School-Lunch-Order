//
//  introduction.cpp
//  introduction
//
//  Created by Harshdeep Singh on 15/06/2024.
//

#include "introduction.hpp"
#include "adminscreen.hpp"
#include "complaintscreen.hpp"
#include "orderscreen.hpp"
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
// List of options
void list_options() {
    cout << "1. Weekly Menu" << endl
         << "2. Today's Menu" << endl
         << "3. Discounts" << endl
         << "4. Login and Registration for Parents" << endl
         << "5. Login and Registration for Staff" << endl
         << "6. Admin Login" << endl;
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
void login_registerparent() {// function for parent to choose login or register
    int option1;
    while (true) {
        cout << "1. Login" << endl << "2. Registration" << endl << "3. Main Menu"<< endl;
           cout << "Enter 1 for Login,2 for Registration and 3 for main menu: ";
           cin >> option1;
           cin.ignore(); // Clear the newline character from the input buffer
           if (option1 == 1) {
               parentlogin_here();
           } else if (option1 == 2) {
               parent_registration();
           }else if(option1 ==3){
                   main();
               }
           
           else {
               cout << "Please enter a valid option!" << endl;
               login_registerparent();
           }
        cout << "Press Enter to return to the Login and Registration...";
        cin.ignore();
        cin.get();
    }
   
    
}

void parent_registration() {//parent registration function
    Details temp;
    cout << "Hello Parent! This is your Registration Screen.Enter your details please. " << endl;
    cout << "Enter full name: ";
    getline(cin, temp.name);//using getline to include spaces as string

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

    cout << "\nPlease check registered details" << endl;// displaying registered screen
    for (int i = 0; i < parentinfo.size(); i++) {
        if (temp.username == parentinfo[i].username) {
            cout << "Full name: " << parentinfo[i].name << endl;
            cout << "Gender: " << parentinfo[i].gender << endl;
            cout << "Date of Birth: " << parentinfo[i].DOB << endl;
            cout << "Contact number: " << parentinfo[i].contact << endl;
            cout << "Visa card number: " << parentinfo[i].visacardnumber << endl;
            cout << "Visa card expiry date: " << parentinfo[i].visacardexpiry << endl;
            cout << "Username: " << parentinfo[i].username << endl;
            cout << "--------------------------------------" << endl;
        }
    }
    
}
void parentlogin_here() {//parent login function
    string username, password;
    const int maxAttempts = 3;
    bool loginSuccessful = false;

    for (int attempts = 0; attempts < maxAttempts; ++attempts) {//implementing
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
                    Recent a;
                    a.name = parent.name;
                    a.contact = parent.contact;
                    recentparent.push_back(a);
                    printHeading();
                    cout << "**Welcome to Parent screen**" << endl;
                    cout << "1. Order food\n2. Weekly Menu\n3. Today's Menu\n4. Complaint Screen\n";
                    cout << "Enter the task you want to do: ";
                    int task;
                    cin >> task;
                    switch (task) {
                        case 1: orderscreen(); break;
                        case 2: wholemenu(); break;
                        case 3: todays_menu(); break;
                        case 4: parentcomplaint(); break;
                        default: cout << "Invalid task selected." << endl; break;
                    }
                    loginSuccessful = true;
                    break;
                } else {
                    cout << "Incorrect password! Please try again." << endl;
                }
            }
        }

        if (!user_found) {
            cout << "You have entered the wrong username! Please try again!" << endl;
        }

        if (loginSuccessful) {
            break;
        }

        if (attempts == maxAttempts - 1) {
            cout << "You exceeded the login try limit! Please try again later!" << endl;
        }
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
int getCurrentDayOfWeek() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return ltm->tm_wday;  // tm_wday is 0 for Sunday, 1 for Monday, ..., 6 for Saturday
}
void wholemenu(){// functions dispalying whole menu
    for (int day = 0; day < NUM_DAYS; day++) {
        cout << weekdays[day] << ":" << endl;
        cout << "+------------------------------+" << endl;
        for (int category = 0; category < NUM_CATEGORIES; category++) {
            cout << "| " << left << setw(10) << categories[category] << ": " << menu[day][category].name << " ($" << fixed << setprecision(2) << menu[day][category].price << ")" << endl;
        }
        cout << "+------------------------------+" << endl;
        cout << "| Drinks:                      |" << endl;
        for (int drink = 0; drink < NUM_DRINKS; drink++) {
            cout << "| " << left << setw(20) << drinks[drink] << ": $" << fixed << setprecision(2) << drinkPrices[drink] << endl;
        }
        cout << "+------------------------------+" << endl << endl;
    }
    
}
void todays_menu() {//function displays present day menu
    int currentDay = getCurrentDayOfWeek();
    cout << "+==============================+" << endl;//heading
    cout << "|          Today's Menu         |" << endl;
    cout << "+==============================+" << endl;
    
    if (currentDay >= 1 && currentDay <= 5) { // Monday to Friday
        string currentWeekday = weekdays[currentDay - 1];//displaying food items
        cout << currentWeekday << ":" << endl;
        cout << "+------------------------------+" << endl;
        for (int category = 0; category < NUM_CATEGORIES; category++) {
            cout << "| " << categories[category] << ": " << menu[currentDay - 1][category].name << " ($" << menu[currentDay - 1][category].price << ")" << endl;
        }
    } else {
        cout << "Today is not a weekday. Please check the menu on a weekday." << endl;
    }
    
    cout << "+------------------------------+" << endl;
    cout << "| Drinks:                      |" << endl;
    cout << "+------------------------------+" << endl;
    for (int drink = 0; drink < NUM_DRINKS; drink++) {
        cout << "| " << drinks[drink] << ": $" << drinkPrices[drink] << endl;
    }
    cout << "+------------------------------+" << endl;
    
}
void display_discounts() {
    cout << "+==============================+" << endl;
    cout << "|        Discounts             |" << endl;
    cout << "+==============================+" << endl;
    cout << "10% off for 5 or more orders!" << endl;
    cout << "Contact us for more bulk order discounts." << endl;
  cout << "+==============================+" << endl;
}
void password_check(Details& temp) {
    string password;
    cout << "Enter your password (no spaces allowed): ";
    getline(cin, temp.password);
    cout << "Confirm your password: ";
    getline(cin, password);
    if (password == temp.password) {
        cout << "You have successfully registered!" << endl;
    } else {
        cout << "Your passwords do not match! Please try again." << endl;
        password_check(temp); // Recursive call to try again
    }
}  
void staff_registration() {//function for staff to register
    Details temp1;

    cout << "Enter full name: ";
    getline(cin, temp1.name);

    cout << "Enter gender (M for male / F for female): ";
    cin >> temp1.gender;
    cin.ignore(); // Clear the newline character from the input buffer

    cout << "Enter date of birth (DOB): ";
    getline(cin, temp1.DOB);

    cout << "Enter contact number: ";
    getline(cin, temp1.contact);

    cout << "Enter Visa card number: ";
    getline(cin, temp1.visacardnumber);

    cout << "Enter Visa card expiry date: ";
    getline(cin, temp1.visacardexpiry);

    cout << "Enter your username: ";
    getline(cin, temp1.username);

    password_check(temp1);

    staffinfo.push_back(temp1);

    for (int i = 0; i < staffinfo.size(); i++) {
        if (temp1.username == staffinfo[i].username) {
            cout << "Full name: " << staffinfo[i].name << endl;
            cout << "Gender: " << staffinfo[i].gender << endl;
            cout << "Date of Birth: " << staffinfo[i].DOB << endl;
            cout << "Contact number: " << staffinfo[i].contact << endl;
            cout << "Visa card number: " << staffinfo[i].visacardnumber << endl;
            cout << "Visa card expiry date: " << staffinfo[i].visacardexpiry << endl;
            cout << "Username: " << staffinfo[i].username << endl;
            cout << "--------------------------------------" << endl;
        }
    }
}


void stafflogin_here() {//login function for staff
    string username, password;
    const int maxAttempts = 3;
    bool loginSuccessful = false;

    // Loop for login attempts
    for (int attempts = 0; attempts < maxAttempts; ++attempts) {
        cout << "Enter your username: ";
        cin >> username;
        cin.ignore(); // Clear the newline character from the input buffer

        bool user_found = false;

        // Loop through staffinfo to find matching username
        for (auto& staff : staffinfo) {
            if (username == staff.username) {
                user_found = true;
                cout << "Enter your password: ";
                getline(cin, password);

                // Check if password matches
                if (password == staff.password) {
                    cout << "Hello! " << staff.name << ", you logged in successfully!" << endl;

                    // Add staff to recentstaff
                    Recent a;
                    a.name = staff.name;
                    a.contact = staff.contact;
                    recentstaff.push_back(a);

                    // Print heading
                    printHeading();

                    // Display staff menu options in a loop
                    while (true) {
                        cout << "**Welcome to Staff screen**" << endl;
                        cout << "1. Order food\n2. Weekly Menu\n3. Today's Menu\n4. Staff Complaint Screen\n5. Main Menu\n";
                        cout << "Enter the task you want to do: ";
                        int task;
                        cin >> task;

                        switch (task) {
                            case 1: orderscreenstaff(); break;
                            case 2: wholemenu(); break;
                            case 3: todays_menu(); break;
                            case 4: staffcomplaint(); break;
                            case 5: return; // Exit to main menu
                            default: cout << "You entered the wrong choice! Try Again!" << endl; break;
                        }

                        cout << "Press Enter to return to staff screen...";
                        cin.ignore();
                        cin.get();
                    }

                    loginSuccessful = true;
                    break;
                } else {
                    cout << "Incorrect password! Please try again." << endl;
                }
            }
        }

        if (!user_found) {
            cout << "You have entered the wrong username! Please try again!" << endl;
        }

        if (loginSuccessful) {
            break; // Exit the login attempts loop if login is successful
        }

        if (attempts == maxAttempts - 1) {
            cout << "You exceeded the login try limit! Please try again later!" << endl;
        }
    }
}
void login_registerstaff() {//function for staff to login  or register
    int option1;
    while (true) {
        cout << "1. Login" << endl << "2. Registration" << endl << "3. Main Menu"<< endl;
            cout << "Enter 1 for Login,2 for Registration and 3 for Main Menu: ";
            cin >> option1;
            cin.ignore(); // Clear the newline character from the input buffer
            if (option1 == 1) {
                stafflogin_here();
            } else if (option1 == 2) {
                staff_registration();
            }
            else if (option1 == 3){
                main();
            }
            else {
                cout << "Please enter a valid option!" << endl;
                login_registerstaff();
            }
        cout << "Press Enter to return to the Login and Registration...";
        cin.ignore();
        cin.get();
    }
    
}


