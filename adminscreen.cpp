
#include "adminscreen.hpp"
#include"introduction.hpp"
#include "orderscreen.hpp"
#include "complaintscreen.hpp"
vector<string> reviewlist;
using namespace std;
void admin_login() {//function for admin to login
    string username, password;
    bool loginSuccessful = false;

    for (int i = 1; i <= 3; i++) {
        // Prompt for admin username
        cout << "Enter admin username: ";
        cin >> username;
        cin.ignore();

        // Prompt for admin password
        cout << "Enter admin password: ";
        getline(cin, password);

        // Check if the entered username and password match the admin credentials
        if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
            cout << "Admin login successful!" << endl;
            loginSuccessful = true;
            break;
        } else {
            cout << "Invalid admin credentials. Please try again." << endl;
        }
    }

    if (!loginSuccessful) {
        cout << "You exceeded the login try limit! Please try again later!" << endl;
        return;
    }

    // Print heading for the admin screen
    printHeading();

    int task;
    while (true) {
        cout << "\t\t**Welcome to Admin Screen**" << endl;
        cout << "1. Menu update\n2. Daily order report\n3. Pending Payment Report\n";
        cout << "4. Parent Complaint Review\n5. Staff Complaint Review\n6. Main Menu\n";
        cout << "Enter the task you want to accomplish: ";
        cin >> task;

        switch (task) {
            case 1:
                changeMenu(); // Placeholder function for updating menu
                break;
            case 2:
             listOrdersFromSameDay();//Placeholder function for listing orders from same day
                break;
            case 3:
             pendingPayment();//Placeholder function for pending payment orders
                break;
            case 4:
                adminreview(); // Placeholder function for parent complaint review
                break;
            case 5:
                adminreviewstaff(); // Placeholder function for staff complaint review
                break;
            case 6:
                main();
                return; // Exit to main menu or break the loop
            default:
                cout << "Invalid task selected." << endl;
                break;
        }
        
        cout << "Press Enter to return to admin screen...";
        cin.ignore(); // Clear the newline character from the input buffer
        cin.get();    // Wait for Enter key
    }
}
void adminreview() {
    if (complaintlist.empty()) {
        cout << "No complaints to display." << endl;
        return;
    }

    cout << "List of complaints:" << endl;
    for (size_t i = 0; i < complaintlist.size(); ++i) {
        cout << i + 1 << ". " << complaintlist[i] << endl;
    }

    int option2;
    cout << "Enter the number of the complaint you want to review: ";
    cin >> option2;
    cin.ignore();

    if (option2 < 1 || option2 > complaintlist.size()) {
        cout << "Invalid selection." << endl;
        return;
    }

    string filename_to_open = complaintlist[option2 - 1];
    ifstream myfile_to_open(filename_to_open.c_str());
    if (!myfile_to_open.is_open()) {
        cout << "The file could not be opened." << endl;
        return;
    }

    string line;
    cout << "Contents of complaint " << option2 << ":" << endl;
    while (getline(myfile_to_open, line)) {
        cout << line << endl;
    }
    myfile_to_open.close();

    ofstream myfile_to_append(filename_to_open.c_str(), ios::app);
    if (myfile_to_append.is_open()) {
        cout << "Enter your response to the complaint: ";
        string response;
        getline(cin, response);

        myfile_to_append << "Admin's Response: " << endl << response << endl;
        myfile_to_append.close();
        reviewlist.push_back(filename_to_open); // Add to review list
        cout << "Response saved successfully." << endl;
    } else {
        cout << "Unable to open file for appending" << endl;
    }
}
void adminreviewstaff() {
    if (staffComplaintList.empty()) {
        cout << "No staff complaints to display." << endl;
        return;
    }

    cout << "List of staff complaints:" << endl;
    for (size_t i = 0; i < staffComplaintList.size(); ++i) {
        cout << i + 1 << ". " << staffComplaintList[i] << endl;
    }

    int option2;
    cout << "Enter the number of the complaint you want to review: ";
    cin >> option2;
    cin.ignore();

    if (option2 < 1 || option2 > staffComplaintList.size()) {
        cout << "Invalid selection." << endl;
        return;
    }

    string filename_to_open = staffComplaintList[option2 - 1];
    ifstream myfile_to_open(filename_to_open.c_str());
    if (!myfile_to_open.is_open()) {
        cout << "The file could not be opened." << endl;
        return;
    }

    string line;
    cout << "Contents of staff complaint " << option2 << ":" << endl;
    while (getline(myfile_to_open, line)) {
        cout << line << endl;
    }
    myfile_to_open.close();

    ofstream myfile_to_append(filename_to_open.c_str(), ios::app);
    if (myfile_to_append.is_open()) {
        cout << "Enter your response to the complaint: ";
        string response;
        getline(cin, response);

        myfile_to_append << "Admin's Response: " << endl << response << endl;
        myfile_to_append.close();
        reviewlist.push_back(filename_to_open); // Add to review list
        cout << "Response saved successfully." << endl;
    } else {
        cout << "Unable to open file for appending" << endl;
    }
}

void changeMenu() {
    int day, column;
    cout << "Enter the day index (1-5) of which you want to change the menu: ";
    cin >> day;

    if (day < 1 || day > 5) {
        cout << "Invalid day index. Please try again." << endl;
        return;
    }
    
    cout << "Enter the column index (1-8) of the item you want to change: ";
    cin >> column;

    if (column < 1 || column > 8) {
        cout << "Invalid column index. Please try again." << endl;
        return;
    }

    cout << "Enter the new name of the dish: ";
    cin.ignore();
    getline(cin, menu[day - 1][column - 1].name);

    cout << "Enter the new price of the dish: ";
    cin >> menu[day - 1][column - 1].price;

    cout << "Menu item changed successfully." << endl;
    wholemenu();
}

void listOrdersFromSameDay() {
    string currentDate = __DATE__;
    cout << "Listing orders from " << currentDate << ":" << endl;
    for (int i = 0; i < savedOrders.size(); ++i) {
        if (savedOrders[i].date == currentDate) {
            cout << "Order " << i + 1 << ":" << endl;
            for (const auto &item : savedOrders[i].items) {
                cout << "Parent name: " << item.parentName << endl;
                cout << "Parent Contact: " << item.parentContact << endl;
                cout << "Order by: " << item.orderby << endl;
                cout << "Order Date: " << item.date << endl;
                cout << item.name << " x" << item.quantity << ": $" << fixed << setprecision(2) << item.price * item.quantity << endl;
            }
            cout << "Total: $" << fixed << setprecision(2) << savedOrders[i].total << endl;
            cout << "+------------------------------+" << endl;
        }
    }
}

void pendingPayment() {
    if (pendingPaymentOrders.empty()) {
        cout << "No pending payment orders." << endl;
        return;
    }

    cout << "Listing pending payment orders:" << endl;
    for (int i = 0; i < pendingPaymentOrders.size(); ++i) {
        cout << "Order " << i + 1 << ":" << endl;
        for (const auto &item : pendingPaymentOrders[i].items) {
            cout << "Parent name: " << item.parentName << endl;
            cout << "Parent Contact: " << item.parentContact << endl;
            cout << "Order by: " << item.orderby << endl;
            cout << "Order Date: " << item.date << endl;
            cout << item.name << " x" << item.quantity << ": $" << fixed << setprecision(2) << item.price * item.quantity << endl;
        }
        cout << "Total: $" << fixed << setprecision(2) << pendingPaymentOrders[i].total << endl;
        cout << "-----------------------------" << endl;
    }
}

