#include "complaintscreen.hpp"
void lodgecomplaint() {//function to lodgecomplaint
    if (parentinfo.empty()) {
        cout << "No parent registered. Please register first." << endl;
        return;
    }
    cout << "\t\t\t\t**This is your complaint screen**" << endl;
    string filename = recentparent[0].name+ "_complaint.txt";
    recentparent.pop_back();
    ofstream myfile(filename.c_str());
    if (myfile.is_open()) {
        cout << "Enter your complaint: ";
        string complaint;
        getline(cin, complaint);

        myfile << "My complaint:" << endl << complaint << endl;
        myfile.close();
        cout << "Complaint saved successfully!Your Complaint will be reviewed and responded by admin shortly!" << endl;
        complaintlist.push_back(filename);
    } else {
        cout << "Unable to open file" << endl;
    }
}
void lodgestaffcomplaint() {// functio for staff to lodge complaint
    if (staffinfo.empty()) {
        cout << "No staff registered. Please register first." << endl;
        return;
    }
    cout << "\t\t\t\t**This is your complaint screen**" << endl;
    string filename = recentstaff[0].name + "_staff_complaint.txt";
    recentstaff.pop_back();
    ofstream myfile(filename.c_str());
    if (myfile.is_open()) {
        cout << "Enter your complaint: ";
        string complaint;
        getline(cin, complaint);

        myfile << "My complaint:" << endl << complaint << endl;
        myfile.close();
        cout << "Complaint saved successfully to " << filename << endl;
        staffComplaintList.push_back(filename);
    } else {
        cout << "Unable to open file" << endl;
    }
}

void parentreview() {//function for  parent to get response
    if (reviewlist.empty()) {
        cout << "No reviews available." << endl;
        return;
    }

    string filename_to_review = recentparent[0].name+ "_complaint.txt";
       recentparent.pop_back();
    ifstream myfile_to_review(filename_to_review.c_str());
    if (!myfile_to_review.is_open()) {
        cout << "The file could not be opened." << endl;
        return;
    }

    string line;
    cout << "Review of complaint:" << endl;
    while (getline(myfile_to_review, line)) {
        cout << line << endl;
    }
    myfile_to_review.close();
}

void staffreview() {//function for staff to get response
    if (staffComplaintList.empty()) {
        cout << "No staff complaints available." << endl;
        return;
    }

    string filename_to_review = recentstaff[0].name + "_staff_complaint.txt";
    recentstaff.pop_back();
    ifstream myfile_to_review(filename_to_review.c_str());
    if (!myfile_to_review.is_open()) {
        cout << "The file could not be opened." << endl;
        return;
    }

    string line;
    cout << "Review of staff complaint:" << endl;
    while (getline(myfile_to_review, line)) {
        cout << line << endl;
    }
    myfile_to_review.close();
}

void parentcomplaint() {//function forparent to choose for complaint lodging or review complaint
    int task;
  
    cout << "**This is complaint screen**" << endl;
    cout << "1. Lodge Complaint \n2. Review Complaint" << endl;
    cout << "Enter your choice for your task: ";
    cin >> task;
    cin.ignore();

    switch (task) {
        case 1:
            lodgecomplaint();
            break;
        case 2:
            parentreview();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

void staffcomplaint() {//function for staff to choose for complaint lodging or review complaint
    int task;
    cout << "**This is staff complaint screen**" << endl;
    cout << "1. Lodge Complaint \n2. Review Complaint" << endl;
    cout << "Enter your choice for your task: ";
    cin >> task;
    cin.ignore();

    switch (task) {
        case 1:
            lodgestaffcomplaint();
            break;
        case 2:
            staffreview();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}
