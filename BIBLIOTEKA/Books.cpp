#include<iostream>
#include<string>
#include<fstream>
#include <map>
#include "Book.h"
#include "Books.h"

void Books::add()
{
    Book newBook;
    newBook.requestData();

    if (!exists(newBook.getId()))
    {
        books.insert(pair<int,Book>(newBook.getId(), newBook));
        serialize();
    }
    else
    {
        cout << "Book with the same id already exists!";
    }
}

bool Books::exists(int id)
{
    return books.find(id) != books.end();
}

bool Books::isAvailable(int id)
{
    return exists(id) && books[id].getStatus() == 0;
}

Book Books::get(int id)
{
    return books[id];
}

void Books::rent(int id)
{
    books[id].rent();
    serialize();
}

void Books::returnBack(int id)
{
    books[id].returnBack();
    serialize();
}

void Books::display()
{
    map<int, Book>::iterator it;

    for (it = books.begin(); it != books.end(); it++)
    {
        it->second.display();
    }
}

void Books::search()
{
    string text;
    cout << "Phrase to search: ";
    cin >> text;

    map<int, Book>::iterator it;
    for (it = books.begin(); it != books.end(); it++)
    {
        if (it->second.search(text))
        {
            it->second.display();
        }
    }
}

void Books::remove()
{
    int id;
    cout << "Id to remove: ";
    cin >> id;

    books.erase(id);
    serialize();
}


void Books::serialize()
{
    ofstream wr(filePath);

    map<int, Book>::iterator it;
    for (it = books.begin(); it != books.end(); it++)
    {
        wr << it->second.toCsv(getDelimeter()) << endl;
    }

    wr.close();
}

void Books::deserialize()
{
    ifstream rd(filePath);

    string line;
    while (getline(rd, line))
    {
        Book b;
        b.fromCsv(line, delimiter);
        books.insert(pair<int,Book>(b.getId(), b));
    }

    rd.close();
}
