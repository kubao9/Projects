#include<iostream>
#include<string>
#include<fstream>
#include <map>
#include "Rental.h"
#include "Rentals.h"

void Rentals::add()
{
    Rental newRental;
    newRental.requestData();

    bool isValid = true;

    if (!students->exists(newRental.getStudentId()))
    {
        cout << "Student doesn't exist!" << endl;
        isValid = false;
    }

    if (!books->exists(newRental.getBookId()))
    {
        cout << "Book doesn't exist!" << endl;
        isValid = false;
    }

    if (isValid && !books->isAvailable(newRental.getBookId()))
    {
        cout << "Book not available!" << endl;
        isValid = false;
    }

    if (isValid)
    {
        int nextId = rentals.empty() ? 1 : (--rentals.end())->first+1;
        newRental.setId(nextId);

        rentals.insert(pair<int,Rental>(newRental.getId(), newRental));
        books->rent(newRental.getBookId());
        serialize();
    }
}

Rental Rentals::get(int id)
{
    return rentals[id];
}

void Rentals::display()
{
    map<int, Rental>::iterator it;

    for (it = rentals.begin(); it != rentals.end(); it++)
    {
        it->second.display();
    }
}

void Rentals::search()
{
    string text;
    cout << "Phrase to search: ";
    cin >> text;

    map<int, Rental>::iterator it;
    for (it = rentals.begin(); it != rentals.end(); it++)
    {
        if (it->second.search(text))
        {
            it->second.display();
        }
    }
}

void Rentals::remove()
{
    int id;
    cout << "Id to remove: ";
    cin >> id;

    books->returnBack(rentals[id].getBookId());
    rentals.erase(id);
    serialize();
}


void Rentals::serialize()
{
    ofstream wr(filePath);

    map<int, Rental>::iterator it;
    for (it = rentals.begin(); it != rentals.end(); it++)
    {
        wr << it->second.toCsv(getDelimeter()) << endl;
    }

    wr.close();
}

void Rentals::deserialize()
{
    ifstream rd(filePath);

    string line;
    while (getline(rd, line))
    {
        cout << "rent " << line;
        Rental r;
        r.fromCsv(line, delimiter);
        rentals.insert(pair<int,Rental>(r.getId(), r));
    }

    rd.close();
}
