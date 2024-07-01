
#include "complaintscreen.hpp"
#include "introduction.hpp"
#include "adminscreen.hpp"
vector<string> complaintlist;
vector<string> staffComplaintList;
using namespace std;
void lodgecomplaint() {
    if (recentparent.empty()) {
        cout << "No parent registered. Please register first." << endl;
        return;
    }

    cout << "\t\t\t\t**This is your complaint screen**" << endl;
    string filename = recentparent[0].name + "_complaint.txt";
    recentparent.pop_back();
    ofstream myfile(filename.c_str());
    if (myfile.is_open()) {
        cout << "Enter your complaint: ";
        string complaint;
        getline(cin, complaint);

        myfile << "My complaint:" << endl << complaint << endl;
        myfile.close();
        cout << "Complaint saved successfully! Your Complaint will be reviewed and responded by admin shortly!" << endl;
        complaintlist.push_back(filename);
    } else {
        cout << "Unable to open file" << endl;
    }
}
void parentreview() {
    if (reviewlist.empty()) {
        cout << "No reviews available." << endl;
        return;
    }

    string filename_to_review = reviewlist[0];
    reviewlist.pop_back();
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
void lodgestaffcomplaint() {
    if (recentstaff.empty()) {
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
void staffreview() {
    if (staffComplaintList.empty()) {
        cout << "No staff complaints available." << endl;
        return;
    }

    string filename_to_review = staffComplaintList[0];
    staffComplaintList.pop_back();
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


