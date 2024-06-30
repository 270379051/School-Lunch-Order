#include "introduction.hpp"
#include "adminscreen.hpp"
#include "complaintscreen.hpp"
#include "orderscreen.hpp"

vector<Bill> pendingPaymentOrders;
vector<Bill> savedOrders;

void orderscreen() {
    int choice, quantity;
    Bill bill;

    bill.total = 0.0;
    bill.date = __DATE__;
    bill.parentName = recentparent[0].name;
    bill.parentContact = recentparent[0].contact;
    bill.orderby = "Parent";
    
    cout << "**Welcome to Order Screen**" << endl;
    cout << "Today's Menu:" << endl;
    todays_menu();

    do {
        cout << "Select Item you want to Order (1-8 for food, 9-12 for drinks, 0 to finish):" << endl;
        cout << "1. Burger\n2. Pizza\n3. Sandwich\n4. Fries\n5. Eggs\n6. Noodles\n7. Wrap\n8. Soup\n";
        cout << "9. Fruit Juice\n10. Energy Drink\n11. Soft Drink\n12. Hydration Drink\n";
        cin >> choice;

        if (choice == 0) break;

        if (choice < 1 || choice > 12) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        cout << "Enter Quantity:" << endl;
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity. Please enter a positive number." << endl;
            continue;
        }

        int currentDay = getCurrentDayOfWeek();
        if (currentDay < 1 || currentDay > 5) {
            cout << "Today is not a weekday. Cannot place an order." << endl;
            return;
        }

        if (choice >= 1 && choice <= 8) {
            MenuItem orderedItem = menu[currentDay - 1][choice - 1];
            bill.items.push_back({orderedItem.name, orderedItem.price, quantity, bill.parentName, bill.parentContact, bill.orderby});
            bill.total += orderedItem.price * quantity;
        } else if (choice >= 9 && choice <= 12) {
            int drinkIndex = choice - 9;
            bill.items.push_back({drinks[drinkIndex], drinkPrices[drinkIndex], quantity, bill.parentName, bill.parentContact, bill.orderby});
            bill.total += drinkPrices[drinkIndex] * quantity;
        }

    } while (choice != 0);

    if (bill.items.empty()) {
        cout << "No items ordered. Exiting order screen." << endl;
        return;
    }

    paymentOption(bill);
}
void applyDiscount(Bill &bill) {
    double discount = 0.0;
    if (bill.total > 50) {
        discount = 0.1 * bill.total;
    } else if (bill.total > 30) {
        discount = 0.05 * bill.total;
    }
    cout << "Applying discount: $" << fixed << setprecision(2) << discount << endl;
    bill.total -= discount;
}

void showOrderConfirmation(const Bill &bill) {
    cout << "+==============================+" << endl;
    cout << "|      Order Confirmation      |" << endl;
    cout << "+==============================+" << endl;

    for (const auto &item : bill.items) {
        cout << "| " << item.name << " x" << item.quantity << ": $" << fixed << setprecision(2) << item.price * item.quantity << endl;
        cout << "+------------------------------+" << endl;
    }
    cout << "| Total: $" << fixed << setprecision(2) << bill.total << endl;
    cout << "+==============================+" << endl;
    cout << "| Parent Name: " << bill.parentName << endl;
    cout << "| Parent Contact: " << bill.parentContact << endl;
    cout << "| Order by: " << bill.orderby << endl;
    cout << "| Order Date: " << bill.date << endl;
    cout << "+==============================+" << endl;
}

void paymentOrder(const Bill &bill) {
    pendingPaymentOrders.push_back(bill);
}

void orders(const Bill &bill) {
    savedOrders.push_back(bill);
}

void paymentOption(Bill &bill) {
    int paymentChoice;
    do {
        cout << "Select Payment Option:" << endl;
        cout << "1. Pay Now\n2. Pay Later\n";
        cin >> paymentChoice;

        if (paymentChoice == 1) {
            applyDiscount(bill);
            showOrderConfirmation(bill);
            orders(bill);
            break;
        } else if (paymentChoice == 2) {
            paymentOrder(bill);
            showOrderConfirmation(bill);
            orders(bill);
            cout << "Order saved in Pending Payment Orders." << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    } while (true);
}
void orderscreenstaff() {
    int choice, quantity;
    Bill bill;

    bill.total = 0.0;
    bill.date = __DATE__;
    bill.orderby = "Staff";

    cout << "**Welcome to Order Screen**" << endl;
    cout << "Enter Parent's Name:";
    cin.ignore();
    getline(cin, bill.parentName);
    cout << "Enter Parent's Contact:";
    getline(cin, bill.parentContact);

    cout << "Today's Menu:" << endl;
    todays_menu();

    do {
        cout << "Select Item you want to Order (1-8 for food, 9-12 for drinks, 0 to finish):" << endl;
        cout << "1. Burger\n2. Pizza\n3. Sandwich\n4. Fries\n5. Eggs\n6. Noodles\n7. Wrap\n8. Soup\n";
        cout << "9. Fruit Juice\n10. Energy Drink\n11. Soft Drink\n12. Hydration Drink\n";
        cin >> choice;

        if (choice == 0) break;

        if (choice < 1 || choice > 12) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        cout << "Enter Quantity:" << endl;
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity. Please enter a positive number." << endl;
            continue;
        }

        int currentDay = getCurrentDayOfWeek();
        if (currentDay < 1 || currentDay > 5) {
            cout << "Today is not a weekday. Cannot place an order." << endl;
            return;
        }

        if (choice >= 1 && choice <= 8) {
            MenuItem orderedItem = menu[currentDay - 1][choice - 1];
            bill.items.push_back({orderedItem.name, orderedItem.price, quantity, __DATE__, bill.parentName, bill.parentContact, bill.orderby});
            bill.total += orderedItem.price * quantity;
        } else if (choice >= 9 && choice <= 12) {
            int drinkIndex = choice - 9;
            bill.items.push_back({drinks[drinkIndex], drinkPrices[drinkIndex], quantity, __DATE__, bill.parentName, bill.parentContact, bill.orderby});
            bill.total += drinkPrices[drinkIndex] * quantity;
        }

    } while (choice != 0);

    if (bill.items.empty()) {
        cout << "No items ordered. Exiting order screen." << endl;
        return;
    }

    paymentOption(bill);
}

