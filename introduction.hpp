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
const int NUM_DAYS = 5;
const int NUM_CATEGORIES = 8;
const int NUM_DRINKS = 4;

const string categories[NUM_CATEGORIES] = { "Burger", "Pizza", "Sandwich", "Fries", "Eggs", "Noodles", "Wraps", "Soup" };
const string drinks[NUM_DRINKS] = { "Fruit Juice", "Energy Drink", "Soft Drink", "Hydration Drink" };
const double drinkPrices[NUM_DRINKS] = { 2.50, 3.00, 2.00, 3.50 };
const string weekdays[NUM_DAYS] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

MenuItem menu[NUM_DAYS][NUM_CATEGORIES] = {// 2d array for menu
    {{"Classic Cheeseburger", 8.00}, {"Margherita Pizza", 10.00}, {"Grilled Chicken Sandwich", 9.00}, {"Sweet Potato Fries", 4.00}, {"Scrambled Eggs with smoked salmon", 7.00}, {"Pad Thai with shrimp", 12.00}, {"Greek Wrap", 8.00}, {"Tomato Basil Soup", 5.00}},
    {{"BBQ Bacon Burger", 9.50}, {"Pepperoni Pizza", 11.00}, {"Turkey Club Sandwich", 8.50}, {"Curly Fries", 4.00}, {"Eggs Benedict", 9.00}, {"Spaghetti Carbonara", 11.00}, {"Buffalo Chicken Wrap", 8.50}, {"Chicken Noodle Soup", 6.00}},
    {{"Mushroom Swiss Burger", 9.00}, {"Veggie Pizza", 10.00}, {"BLT Sandwich", 7.50}, {"Parmesan Truffle Fries", 5.00}, {"Omelette with spinach, mushrooms, and goat cheese", 7.00}, {"Ramen with pork", 12.00}, {"Falafel Wrap", 7.50}, {"Butternut Squash Soup", 6.00}},
    {{"Spicy Black Bean Burger", 8.50}, {"Hawaiian Pizza", 11.00}, {"Roast Beef Sandwich", 9.00}, {"Waffle Fries", 4.50}, {"Shakshuka", 8.00}, {"Lo Mein with chicken", 11.00}, {"BBQ Pulled Pork Wrap", 8.50}, {"French Onion Soup", 6.50}},
    {{"Blue Cheese Burger", 9.50}, {"Meat Lovers Pizza", 12.00}, {"Caprese Sandwich", 8.00}, {"Chili Cheese Fries", 5.00}, {"Frittata", 7.50}, {"Pesto Pasta", 10.00}, {"Grilled Veggie Wrap", 7.50}, {"Minestrone Soup", 6.00}}
};
void printHeading();
void list_options();
int get_option();
void login_registerparent() ;
void parent_registration();
void parentlogin_here();
void contact_details();
int getCurrentDayOfWeek();
void weekly_menu();
void display_discounts();
void password_check(Details& temp);
void login_registerstaff();
void stafflogin_here();
void staff_registration();
void todays_menu() ;
void wholemenu();
#endif 
