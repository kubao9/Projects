#include <iostream>
#include<string>
#include <sstream>
#include "Book.h"

using namespace std;

void Book::requestData()
{
    cout<<"Enter book id:";
    cin>>book_id;
    cout<<"Enter book name:";
    getline(cin>> ws, book_name);
    cout<<"Enter author name:";
    getline(cin>> ws, author);
    cout<<"Enter price:";
    cin>>price;
    status = 0;
}

int Book::getId()
{
    return book_id;
}

int Book::getStatus()
{
    return status;
}

void Book::rent()
{
    status = 1;
}

void Book::returnBack()
{
    status = 0;
}

void Book:: display()
{
    cout<<"*****************************************"<<endl;
    cout<<"Name   : "<<book_name<<endl;
    cout<<"ID     : "<<book_id<<endl;
    cout<<"Author : "<<author<<endl;
    cout<<"Price  : "<<price<<endl;
    if(status == 0)
    {
        cout<<"Status : Not Issued"<<endl;
    }
    else
    {
        cout<<"Status : Issued"<<endl;
    }
    cout<<"*****************************************"<<endl;
}

bool Book::search(string text)
{
    return book_name.find(text) != std::string::npos || author.find(text) != std::string::npos;
}

string Book::toCsv(string delimeter)
{
    stringstream ss;
    ss << book_id << delimeter << book_name << delimeter << author << delimeter << price << delimeter << status;
    return ss.str();
}

void Book::fromCsv(string text, string delimeter)
{
    size_t pos = text.find(delimeter);
    book_id = stoi(text.substr(0, pos));
    text.erase(0, pos + delimeter.length());

    pos = text.find(delimeter);
    book_name = text.substr(0, pos);
    text.erase(0, pos + delimeter.length());

    pos = text.find(delimeter);
    author = text.substr(0, pos);
    text.erase(0, pos + delimeter.length());

    pos = text.find(delimeter);
    price = stoi(text.substr(0, pos));
    text.erase(0, pos + delimeter.length());

    pos = text.find(delimeter);
    status = stoi(text.substr(0, pos));
    text.erase(0, pos + delimeter.length());
}
