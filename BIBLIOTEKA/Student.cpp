#include <iostream>
#include<string>
#include <sstream>
#include "Student.h"

using namespace std;


void Student::requestData()
{
    cout<<"Enter student id: ";
    cin>>student_id;
    cout<<"Enter student name: ";
    getline(cin>> ws, name);
    cout<<"Enter student surname: ";
    getline(cin>> ws, surname);
}

int Student::getId()
{
    return student_id;
}

void Student:: display()
{
    cout<<"*****************************************"<<endl;
    cout<<"Name   : "<<name<<endl;
    cout<<"Surname: "<<surname<<endl;
    cout<<"ID     : "<<student_id<<endl;
}

bool Student::search(string text)
{
    return name.find(text) != std::string::npos || surname.find(text) != std::string::npos;
}

string Student::toCsv(string delimeter)
{
    stringstream ss;
    ss << student_id << delimeter << name << delimeter << surname;
    return ss.str();
}

void Student::fromCsv(string text, string delimeter)
{
    size_t pos = text.find(delimeter);
    student_id = stoi(text.substr(0, pos));
    text.erase(0, pos + delimeter.length());

    pos = text.find(delimeter);
    name = text.substr(0, pos);
    text.erase(0, pos + delimeter.length());

    pos = text.find(delimeter);
    surname = text.substr(0, pos);
    text.erase(0, pos + delimeter.length());
}
