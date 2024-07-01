#ifndef INTRODUCTION_HPP
#define INTRODUCTION_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>

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

struct Recent {
    string name;
    string contact;
};

struct MenuItem {
    string name;
    double price;
};

extern vector<Details> parentinfo;
extern vector<Details> staffinfo;
extern vector<Recent> recentstaff;
extern vector<Recent> recentparent;

const int NUM_DAYS = 5;
const int NUM_CATEGORIES = 8;
const int NUM_DRINKS = 4;

extern MenuItem menu[NUM_DAYS][NUM_CATEGORIES];

const string categories[NUM_CATEGORIES] = { "Burger", "Pizza", "Sandwich", "Fries", "Eggs", "Noodles", "Wraps", "Soup" };
const string drinks[NUM_DRINKS] = { "Fruit Juice", "Energy Drink", "Soft Drink", "Hydration Drink" };
const double drinkPrices[NUM_DRINKS] = { 2.50, 3.00, 2.00, 3.50 };
const string weekdays[NUM_DAYS] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int getCurrentDayOfWeek();
void printHeading();
void todays_menu();
void wholemenu();
void list_options();
void contact_details();
int get_option();
void display_discounts();
void parent_registration();
void password_check(Details& temp);
void login_registerparent();
void parentlogin_here();
void stafflogin_here();
void login_registerstaff();
void staff_registration();
void parentcomplaint();
void staffcomplaint();

#endif // INTRODUCTION_HPP
