
#ifndef adminscreen_hpp
#define adminscreen_hpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;
extern vector<string> reviewlist;
const string ADMIN_USERNAME = "admin@thelunchspot";
const string ADMIN_PASSWORD = "admin123";
void admin_login() ;
void adminreview() ;
void adminreviewstaff();
void changeMenu() ;
void listOrdersFromSameDay();
void pendingPayment();
int main();
#endif /* adminscreen_hpp */
