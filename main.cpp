//
//  main.cpp
//  introduction
//
//  Created by Harshdeep Singh on 15/06/2024.
//

#include "introduction.hpp"
#include "adminscreen.hpp"
int main() {
    while (true) {
        printHeading();
        list_options();
        
        int selected_option = get_option(); // Get the user's task choice
        switch (selected_option) {
            case 1:
                printHeading();
                wholemenu();
                break;
            case 2:
                printHeading();
                todays_menu();
                break;
            case 3:
                printHeading();
                display_discounts();
                break;
            case 4:
                printHeading();
                login_registerparent();
                break;
            case 5:
                printHeading();
                login_registerstaff();
                break;
            case 6:
                printHeading();
                admin_login();
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
        
        cout << "Press Enter to return to the main menu...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
