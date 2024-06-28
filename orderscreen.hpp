#ifndef ORDERSCREEN_HPP
#define ORDERSCREEN_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct OrderItem {
    string name;
    double price;
    int quantity;
    string date = __DATE__;
    string parentName;
    string parentContact;
    string orderby;
};

struct Bill {
    vector<OrderItem> items;
    double total;
    string date;
    string parentName;
    string parentContact;
    string orderby;
};

extern vector<Bill> pendingPaymentOrders;  // Global vector for pending payment orders
extern vector<Bill> savedOrders;           // Global vector for all orders

// Function prototypes
void orderscreen();
void paymentOption(Bill &bill);
void applyDiscount(Bill &bill);
void showOrderConfirmation(const Bill &bill);
void paymentOrder(const Bill &bill);
void orders(const Bill &bill);
void todays_menu();
int getCurrentDayOfWeek();

#endif // ORDERSCREEN_HPP
