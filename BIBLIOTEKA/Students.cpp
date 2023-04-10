#include<iostream>
#include<string>
#include<fstream>
#include <map>
#include "Student.h"
#include "Students.h"

void Students::add()
{
    Student newStudent;
    newStudent.requestData();

    students.insert(pair<int,Student>(newStudent.getId(), newStudent));
    serialize();
}

bool Students::exists(int id)
{
    return students.find(id) != students.end();
}

Student Students::get(int id)
{
    return students[id];
}

void Students::display()
{
    map<int, Student>::iterator it;

    for (it = students.begin(); it != students.end(); it++)
    {
        it->second.display();
    }
}

void Students::search()
{
    string text;
    cout << "Phrase to search: ";
    cin >> text;

    map<int, Student>::iterator it;
    for (it = students.begin(); it != students.end(); it++)
    {
        if (it->second.search(text))
        {
            it->second.display();
        }
    }
}

void Students::remove()
{
    int id;
    cout << "Id to remove: ";
    cin >> id;

    students.erase(id);
    serialize();
}


void Students::serialize()
{
    ofstream wr(filePath);

    map<int, Student>::iterator it;
    for (it = students.begin(); it != students.end(); it++)
    {
        wr << it->second.toCsv(getDelimeter()) << endl;
    }

    wr.close();
}

void Students::deserialize()
{
    ifstream rd(filePath);

    string line;
    while (getline(rd, line))
    {
        Student s;
        s.fromCsv(line, delimiter);
        students.insert(pair<int,Student>(s.getId(), s));
    }

    rd.close();
}
