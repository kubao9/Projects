#pragma once
#include<string>

using namespace std;

/// klasa ksiazka
class Book
{
    private:
        int book_id;
        string book_name;
        string author;
        float price;
        int status = 0;

    public:
        ///funkcja wczytuje dane ksiazki z klawiatury
        void requestData();

        ///funkcja podaje id ksiazki
        ///@return identyfikator ksiazki
        int getId();

        ///funkcja podaje status ksiazki
        ///@return status ksiazki
        int getStatus();

        ///funkcja obsluguje wypozyczenie ksiazke
        void rent();

        ///funkcja obsluguje zwrot ksiazki
        void returnBack();

        ///funkcja sprawdza czy tytul lub autor ksiazki pasuje do podanej frazy wyszukiwania
        ///@param text fraza wyszukania
        ///@return prawda gdy ksiazka pasuje, falsz gdy nie pasuje
        bool search(string text);

        ///funkcja wyswietla informacje o ksiazce
        void display();

        ///funkcja zamienia dane ksiazki na napis w formacie csv
        ///@param delimeter odstep pomiedzy danymi
        ///@return dane ksiazki w formacie csv
        string toCsv(string delimeter);

        ///funkcja odczytuje z napisu w formacie csv dane ksiazki
        ///@param text dane do odczytu
        ///@param delimeter odstep pomiedzy danymi
        void fromCsv(string text, string delimeter);
};
