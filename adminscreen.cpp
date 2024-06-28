
#include "adminscreen.hpp"
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
