//
//  main.cpp
//  introduction
//
//  Created by Harshdeep Singh on 15/06/2024.
//

#include <iostream>
int main()
{
   
    while (true) {
        printHeading();
        list_options();

        int selected_option = get_option(); // Get the user's task choice
        switch (selected_option) {
            
           case 1:
               printheading();
               weekly_menu();
            case 3:
                printHeading();
                login_registerparent();
                break;
            case 5:
                printHeading();
                admin_login();
                break;
           case 6:
                printHeading();
                contact_details();
                break;

            default:
                cout << "Invalid option!" << endl;
                break;
        }

        cout << "Press Enter to return to the main menu...";
        cin.ignore();
        cin.get();
    }
       


