
#ifndef orderscreen_hpp
#define orderscreen_hpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct OrderItem {
    string name;
    double price;
    int quantity;
    string date;
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

extern vector<Bill> pendingPaymentOrders;
extern vector<Bill> savedOrders;
void orderscreen();
void paymentOption(Bill &bill);
void paymentOrder(const Bill &bill) ;
void orders(const Bill &bill);
void applyDiscount(Bill &bill);
void showOrderConfirmation(const Bill &bill);
void pendingpaymentOrder(const Bill &bill);
void todaysorders(const Bill &bill);
void orderscreenstaff();

#endif /* orderscreen_hpp */
