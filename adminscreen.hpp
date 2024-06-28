#ifndef ADMINCREEN_HPP
#define ADMINSCREEN_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const string ADMIN_USERNAME = "admin@thelunchspot";//admin username and password
const string ADMIN_PASSWORD = "admin123";
vector<string> reviewlist;// vector to store responded complaints
void admin_login();
void adminreview() ;
void adminreviewstaff();
void changeMenu();
void listOrdersFromSameDay();
void pendingPayment();

#endif
