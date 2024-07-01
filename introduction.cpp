#include "introduction.hpp"
#include "orderscreen.hpp"
#include "complaintscreen.hpp"
#include "adminscreen.hpp"
vector<Details> parentinfo;
vector<Details> staffinfo;
vector<Recent> recentstaff;
vector<Recent> recentparent;

MenuItem menu[NUM_DAYS][NUM_CATEGORIES] = {
    {{"Classic Cheeseburger", 8.00}, {"Margherita Pizza", 10.00}, {"Grilled Chicken Sandwich", 9.00}, {"Sweet Potato Fries", 4.00}, {"Scrambled Eggs with smoked salmon", 7.00}, {"Pad Thai with shrimp", 12.00}, {"Greek Wrap", 8.00}, {"Tomato Basil Soup", 5.00}},
    {{"BBQ Bacon Burger", 9.50}, {"Pepperoni Pizza", 11.00}, {"Turkey Club Sandwich", 8.50}, {"Curly Fries", 4.00}, {"Eggs Benedict", 9.00}, {"Spaghetti Carbonara", 11.00}, {"Buffalo Chicken Wrap", 8.50}, {"Chicken Noodle Soup", 6.00}},
    {{"Mushroom Swiss Burger", 9.00}, {"Veggie Pizza", 10.00}, {"BLT Sandwich", 7.50}, {"Parmesan Truffle Fries", 5.00}, {"Omelette with spinach, mushrooms, and goat cheese", 7.00}, {"Ramen with pork", 12.00}, {"Falafel Wrap", 7.50}, {"Butternut Squash Soup", 6.00}},
    {{"Spicy Black Bean Burger", 8.50}, {"Hawaiian Pizza", 11.00}, {"Roast Beef Sandwich", 9.00}, {"Waffle Fries", 4.50}, {"Shakshuka", 8.00}, {"Lo Mein with chicken", 11.00}, {"BBQ Pulled Pork Wrap", 8.50}, {"French Onion Soup", 6.50}},
    {{"Blue Cheese Burger", 9.50}, {"Meat Lovers Pizza", 12.00}, {"Caprese Sandwich", 8.00}, {"Chili Cheese Fries", 5.00}, {"Frittata", 7.50}, {"Pesto Pasta", 10.00}, {"Grilled Veggie Wrap", 7.50}, {"Minestrone Soup", 6.00}}
};

int getCurrentDayOfWeek() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return ltm->tm_wday;
}

void printHeading() {
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| _________   _      _   _____    _      _     _   __       _   _____   _      _    ________   __________   __________   _________  |" << endl;
    cout << "||___   ___| | |    | | | ____|  | |    | |   | | |       | | |  ___| | |    | |  |  ______| |  ______  | |  ______  | |___   ___| |" << endl;
    cout << "|    | |     | |____| | | |___   | |    | |   | | | |    | | | |     | |____| |  |  |       | |______| | | |      | |     | |     |" << endl;
    cout << "|    | |     | |____| | |  ___|  | |    | |   | | | |    | | | |     | |____| |  |  |_____  | _________| | |      | |     | |     |" << endl;
    cout << "|    | |     | |    | | | |      | |    | |   | | | |    | | | |     | |    | |  |______  | | |          | |      | |     | |     |" << endl;
    cout << "|    | |     | |    | | | |___   | |___ | |___| | | |    | | | |___  | |    | |   ______| | | |          | |______| |     | |     |" << endl;
    cout << "|    |_|     |_|    |_| |_____|  |_____||_______| |_|    ___| |_____| |_|    |_|  |________| |_|          |__________|     |_|     |" << endl;
    cout << "|                                                                                                                                   |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void todays_menu() {
    int currentDay = getCurrentDayOfWeek();
    cout << "+==============================+" << endl;
    cout << "|          Today's Menu         |" << endl;
    cout << "+==============================+" << endl;
    
    if (currentDay >= 1 && currentDay <= 5) {
        string currentWeekday = weekdays[currentDay - 1];
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

void wholemenu() {
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

void list_options() {
    cout << "+==============================+" << endl;
    cout << "| Welcome to School Lunch Service! |" << endl;
    cout << "+==============================+" << endl;
    cout << "| 1. View Whole Menu           |" << endl;
    cout << "| 2. View Today's Menu         |" << endl;
    cout << "| 3. View Discounts            |" << endl;
    cout << "| 4. Register/Login as Parent  |" << endl;
    cout << "| 5. Login/Register as Staff   |" << endl;
    cout << "| 6. Admin Login               |" << endl;
    cout << "| 7. Contact Details           |" << endl;
    cout << "+==============================+" << endl;
}

void contact_details() {
    cout << "+==============================+" << endl;
    cout << "| Contact Us                   |" << endl;
    cout << "+==============================+" << endl;
    cout << "| Phone: +123 456 7890         |" << endl;
    cout << "| Email: contact@schoollunch.com |" << endl;
    cout << "| Address: 123 School Road,    |" << endl;
    cout << "| Springfield                  |" << endl;
    cout << "+==============================+" << endl;
}

int get_option() {
    int option;
    cout << "Enter your choice: ";
    cin >> option;
    cin.ignore(); // Ignore the newline character left in the buffer
    return option;
}

void display_discounts() {
    cout << "+==============================+" << endl;
    cout << "| Current Discounts            |" << endl;
    cout << "+==============================+" << endl;
    cout << "| 5% off for students         |" << endl;
    cout << "+==============================+" << endl;
}

void parent_registration() {
    Details temp;
    cout << "Enter parent name: ";
    cin.ignore();
    getline(cin, temp.name);
    cout << "Enter gender: ";
    cin >> temp.gender;
    cout << "Enter date of birth (DD/MM/YYYY): ";
    cin >> temp.DOB;
    cout << "Enter contact number: ";
    cin >> temp.contact;
    cout << "Enter VISA card number: ";
    cin >> temp.visacardnumber;
    cout << "Enter VISA card expiry date (MM/YYYY): ";
    cin >> temp.visacardexpiry;
    cout << "Enter username: ";
    cin >> temp.username;
    password_check(temp);
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

void password_check(Details& temp) {
    string password, confirmPassword;
    do {
        cout << "Enter password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> confirmPassword;
        if (password != confirmPassword) {
            cout << "Passwords do not match. Try again." << endl;
        }
    } while (password != confirmPassword);
    temp.password = password;
    parentinfo.push_back(temp);
    cout << "Registration successful!" << endl;
}

void parentlogin_here() {
    string username, password;
    const int maxAttempts = 3;
    bool loginSuccessful = false;

    for (int attempts = 0; attempts < maxAttempts; ++attempts) {
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

                    int task;
                    while (true) {
                        cout << "1. Order food\n"
                                "2. Weekly Menu\n"
                                "3. Today's Menu\n"
                                "4. Complaint Screen\n"
                                "5. Main Menu\n"
                                "Enter the task you want to do: ";
                        cin >> task;
                        cin.ignore();

                        switch (task) {
                            case 1:
                                printHeading();
                                orderscreen();
                                break;
                            case 2:
                                printHeading();
                                wholemenu();
                                break;
                            case 3:
                                printHeading();
                                todays_menu();
                                break;
                            case 4:
                                printHeading();
                                parentcomplaint();
                                break;
                            case 5:
                                main();
                                return;
                            default:
                                cout << "Invalid task selected." << endl;
                                break;
                        }

                        cout << "Press Enter to return to the Parent Screen";
                        cin.ignore();
                        cin.get();
                        printHeading();
                        cout << "**Welcome to Parent screen**" << endl;
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
void stafflogin_here() {
    string username, password;
    const int maxAttempts = 3;
    bool loginSuccessful = false;

    for (int attempts = 0; attempts < maxAttempts; ++attempts) {
        cout << "Enter your username: ";
        cin >> username;
        cin.ignore(); // Clear the newline character from the input buffer

        bool user_found = false;
        for (auto& staff : staffinfo) {
            if (username == staff.username) {
                user_found = true;
                cout << "Enter your password: ";
                getline(cin, password);
                if (password ==staff.password) {
                    cout << "Hello! " << staff.name << ", you logged in successfully!" << endl;
                    Recent a;
                    a.name = staff.name;
                    a.contact =staff.contact;
                    recentstaff.push_back(a);
                    printHeading();
                    cout << "**Welcome to Staff screen**" << endl;

                    int task;
                    while (true) {
                        cout << "1. Order food\n"
                                "2. Weekly Menu\n"
                                "3. Today's Menu\n"
                                "4. Complaint Screen\n"
                                "5. Main Menu\n"
                                "Enter the task you want to do: ";
                        cin >> task;
                        cin.ignore();

                        switch (task) {
                            case 1:
                                printHeading();
                                orderscreenstaff();
                                break;
                            case 2:
                                printHeading();
                                wholemenu();
                                break;
                            case 3:
                                printHeading();
                                todays_menu();
                                break;
                            case 4:
                                printHeading();
                              staffcomplaint();
                                break;
                            case 5:
                                main();
                                return;
                            default:
                                cout << "Invalid task selected." << endl;
                                break;
                        }

                        cout << "Press Enter to return to the Staff Screen";
                        cin.ignore();
                        cin.get();
                        printHeading();
                        cout << "**Welcome to Parent screen**" << endl;
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

void login_registerstaff() {
    int option1;
    while (true) {
        cout << "1. Login" << endl << "2. Registration" << endl << "3. Main Menu"<< endl;
        cout << "Enter 1 for Login, 2 for Registration and 3 for Main Menu: ";
        cin >> option1;
        cin.ignore(); // Clear the newline character from the input buffer
        if (option1 == 1) {
            stafflogin_here();
        } else if (option1 == 2) {
            staff_registration();
        } else if (option1 == 3) {
            main();
        } else {
            cout << "Please enter a valid option!" << endl;
            login_registerstaff();
        }
        cout << "Press Enter to return to the Login and Registration...";
        cin.ignore();
        cin.get();
    }
}

void staff_registration() {
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
void parentcomplaint() {
    int task;
  
    cout << "**This is complaint screen**" << endl;
    cout << "1. Lodge Complaint \n2. Review Complaint" << endl;
    cout << "Enter your choice for your task: ";
    cin >> task;
    cin.ignore();

    switch (task) {
        case 1:
            lodgecomplaint();
            break;
        case 2:
            parentreview();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            parentcomplaint();
            break;
    }
}
void staffcomplaint() {
    int task;
    cout << "**This is staff complaint screen**" << endl;
    cout << "1. Lodge Complaint \n2. Review Complaint" << endl;
    cout << "Enter your choice for your task: ";
    cin >> task;
    cin.ignore();

    switch (task) {
        case 1:
            lodgestaffcomplaint();
            break;
        case 2:
            staffreview();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}
