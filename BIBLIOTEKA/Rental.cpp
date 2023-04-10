#include <iostream>
#include<string>
#include <sstream>
#include <chrono>
#include "Rental.h"
#include "Books.h"
using namespace std;

string currentDateTime()
{
    time_t ct = time(0);
    string currentDateTime = ctime(&ct);
    currentDateTime.pop_back();
    return currentDateTime;
}

void Rental::requestData()
{
    cout<<"Enter book id: ";
    cin>>book_id;
    cout<<"Enter student id: ";
    cin>>student_id;
    rental_date = currentDateTime();
}

int Rental::getId()
{
    return rental_id;
}

void Rental::setId(int id)
{
    rental_id = id;
}

int Rental::getStudentId()
{
    return student_id;
}

int Rental::getBookId()
{
    return book_id;
}

void Rental:: display()
{
    cout<<"*****************************************"<<endl;
    cout<<"Rental id   : "<<rental_id<<endl;
    cout<<"Student id  : "<<student_id<<endl;
    cout<<"Book id     : "<<book_id<<endl;
    cout<<"Rental date : "<<rental_date<<endl;
}

bool Rental::search(string text)
{
    return to_string(rental_id) == text || to_string(student_id) == text || to_string(book_id) == text;
}

string Rental::toCsv(string delimeter)
{
    stringstream ss;
    ss << rental_id << delimeter << student_id << delimeter << book_id << delimeter << rental_date;
    return ss.str();
}

void Rental::fromCsv(string text, string delimeter)
{
    size_t pos = text.find(delimeter);
    rental_id = stoi(text.substr(0, pos));
    text.erase(0, pos + delimeter.length());

    pos = text.find(delimeter);
    student_id = stoi(text.substr(0, pos));
    text.erase(0, pos + delimeter.length());

    pos = text.find(delimeter);
    book_id = stoi(text.substr(0, pos));
    text.erase(0, pos + delimeter.length());

    pos = text.find(delimeter);
    rental_date = text.substr(0, pos);
    text.erase(0, pos + delimeter.length());
}
