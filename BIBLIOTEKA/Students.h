#pragma once
#include<iostream>
#include <map>
#include "Serializer.h"
#include "Student.h"

using namespace std;

/// klasa do obslugi wielu uczniow
class Students : public Serializer
{
    private:
        map<int, Student> students;

    public:
        ///konstruktor
        Students(string filePath) : Serializer(filePath) {}

        ///funkcja obluguje dodanie nowego ucznia
        void add();

        /// funkcja sprawdza czy uczen o podanym id istnieje
        ///@param id identyfikator ucznia
        ///@return prawda jezeli uczen istnieje, falsz jezeli nie istnieje
        bool exists(int id);

        ///funkcja zwraca dane ucznia o podanym id
        ///@param id identyfikator ucznia
        ///@return obiekt ucznia
        Student get(int id);

        /// funkcja wyswietla wszystkich uczniow
        void display();

        /// funkcja wyszukuje ucznia wedlug frazy wyszukiwania
        void search();

        /// funkcja usuwa ucznia o podanym id
        void remove();

        ///funkcja zapisuje wszystkich uczniow do pliku (uczen reprezentowane sa w formacie csv)
        void serialize();

        ///funkcja odczytuje uczniow z pliku csv
        void deserialize();
};
