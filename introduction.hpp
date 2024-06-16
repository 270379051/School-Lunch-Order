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
#endif /* introduction_hpp */
