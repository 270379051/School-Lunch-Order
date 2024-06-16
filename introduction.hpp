//
//  introduction.hpp
//  introduction
//
//  Created by Harshdeep Singh on 15/06/2024.
//

#ifndef introduction_hpp
#define introduction_hpp

#include <iostream>
using namespace std;
struct Details {
    string name;
    char gender;
    string DOB;
    string contact;
    string visacardnumber;
    string visacardexpiry;
    string password;
    string username;
};
struct MenuItem {
    string name;
    double price;
};

extern vector<Details> parentinfo;
const string ADMIN_USERNAME = "admin@thelunchspot";
const string ADMIN_PASSWORD = "admin123";
void printHeading();
void list_options();
int get_option();
void login_registerparent() ;
void parent_registration();
void parentlogin_here();
void admin_login();
void contact_details();
int getCurrentDayOfWeek();
void weekly_menu();
void display_discounts();
void password_check(Details& temp);
void login_registerstaff();
void stafflogin_here();
void staff_registration();


#endif /* introduction_hpp */
