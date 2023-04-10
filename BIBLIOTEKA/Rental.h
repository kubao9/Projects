#pragma once
#include<string>

using namespace std;

///klasa wypozyczenie
class Rental
{
    private:
        int rental_id;
        int student_id;
        int book_id;
        string rental_date;
    public:
        /// funckja wczytuje dane wypozyczenia z klawiatury
        void requestData();

        ///funkcja podaje id wypozyczenia
        ///@return identyfikator wypozyczenia
        int getId();

        /// funkcja ustawia id wypozyczenia
        ///@param id identyfikator wypozyczenia
        void setId(int id);

        ///funkcja podaje id ucznia
        ///@return identyfikator ucznia
        int getStudentId();

        ///funkcja podaje id ksiazki
        ///@return identyfikator ksiazki
        int getBookId();

        ///funkcja sprawdza czy id wypozyczenie, ksiazki lub ucznia pasuje do podanej frazy wyszukiwania
        ///@param text fraza wyszukania
        ///@return prawda gdy wypozyczenie pasuje, falsz gdy nie pasuje
        bool search(string text);

        ///funkcja wyswietla informacje o wypozyczeniu
        void display();

        ///funkcja zamienia dane wypozyczenie na napis w formacie csv
        ///@param delimeter odstep pomiedzy danymi
        ///@return dane wypozyczenia w formacie csv
        string toCsv(string delimeter);

        ///funkcja odczytuje z napisu w formacie csv dane wypozyczenia
        ///@param text dane do odczytu
        ///@param delimeter odstep pomiedzy danymi
        void fromCsv(string text, string delimeter);
};
