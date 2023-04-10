#pragma once
#include <map>
#include "Serializer.h"
#include "Rental.h"
#include "Books.h"
#include "Students.h"

using namespace std;

/// klasa do obsugi wypozyczen
class Rentals : public Serializer
{
    private:
        map<int, Rental> rentals;
        Books* books;
        Students* students;

    public:
        ///konstruktor
        ///@param books wskaznik obiektu ksiazek
        ///@param students wskaznik obiektu uczniow
        Rentals(string filePath, Books* books, Students* students) : Serializer(filePath)
        {
            this->books = books;
            this->students = students;
        }

        ///funkcja obsluguje dodanie nowego wypozyczenia
        void add();

        ///funkcja zwraca dane wypozyczenia o podanym id
        ///@param id identyfikator wypozyczenia
        ///@return obiekt wypozyczenia
        Rental get(int id);

        ///funkcja wyswietla wszystkie wypozyczenia
        void display();

        /// funkcja szuka wypozycznia wedlug frazy wyszukiwania
        void search();

        /// funkcja usuwa wypozycznie o podanym id
        void remove();

        ///funkcja zapisuje wszystkie wypozyczenia do pliku (wypozyczenia reprezentowane sa w formacie csv)
        void serialize();

        ///funkcja odczytuje wypozyczenia z pliku csv
        void deserialize();
};
