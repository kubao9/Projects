#pragma once
#include <map>
#include "Serializer.h"
#include "Book.h"

using namespace std;

/// klasa do obslugi wielu ksiazek
class Books : public Serializer
{
    private:
        map<int, Book> books;

    public:
        ///konstruktor
        Books(string filePath) : Serializer(filePath) {}

        ///funkcja obluguje dodanie nowej ksiazki
        void add();

        ///funkcja zwraca informacje czy ksiazka o podanym id istnieje
        ///@param id identyfikator ksiazki
        ///@return prawda jezeli ksiazka istnieje, falsz jezeli nie istnieje
        bool exists(int id);

        ///funkcja zwraca informacje czy ksiazka o podanym id jest dostepna do wypozyczenia
        ///@param id identyfikator ksiazki
        ///@return prawda jezeli ksiazka jest dostepna, falszy jezeli jest niedostepna
        bool isAvailable(int id);

        ///funkcja zwraca dane ksiazki o podanym id
        ///@param id identyfikator ksiazki
        ///@return obiekt ksiazki
        Book get(int id);

        /// funcja obsluguje wypozyczenie ksiazki o podanym id
        ///@param id identyfikator ksiazki
        void rent(int id);

        ///funkcja obsluguje zwrot ksiazki o podanym id
        ///@param id identyfikator ksiazki
        void returnBack(int id);

        ///funkcja wyswietla wszystkie ksiazki
        void display();

        ///funkcja szuka ksiazek wedlug frazy wyszukiwania
        void search();

        ///funkcja usuwa ksiazke o podanym id
        void remove();

        ///funkcja zapisuje wszystkie ksiazki do pliku (ksiazki reprezentowane sa w formacie csv)
        void serialize();

        ///funkcja odczytuje ksiazki z pliku csv
        void deserialize();
};
