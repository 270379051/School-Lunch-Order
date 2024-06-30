#ifndef COMPLAINTSCREEN_HPP
#define COMPLAINTSCREEN_HPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Recent{// structure for reecentparent to be used in complaint and order functions
    string name;
    string contact;
};
vector<string> complaintlist;// vector to store complaint names
vector<Recent> recentparent;//vector to store recentparent in complaint and order function
vector<string> staffComplaintList;//vector to store staff compalaint list
vector<Recent> recentstaff;//vector to store recentstaff in complaint and order function
void lodgecomplaint();
void lodgestaffcomplaint();
void parentreview();
void staffreview();
void parentcomplaint();
void staffcomplaint();
#endif
