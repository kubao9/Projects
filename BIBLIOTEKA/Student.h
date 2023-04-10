#pragma once
#include<string>

using namespace std;

/// klasa uczen
class Student
{
    private:
        int student_id;
        string name;
        string surname;

    public:
        /// funkcja wczytuje dane ucznia z klawiatury
        void requestData();

        ///funkcja podaje id ucznia
        ///@return identyfikator ucznia
        int getId();

        /// funkcja sprawdza czy imie lub nazwisko ucznia pasuje do podanej frazy wyszukiwania
        ///@param text fraza wyszukania
        ///@return prawda gdy uczen pasuje, falsz gdy nie pasuje
        bool search(string text);

        /// funkcja wyswietla informacje o uczniu
        void display();

        ///funkcja zamienia dane ucznia na napis w formacie csv
        /// @param delimeter odstep pomiedzy danymi
        ///@return dane ucznia w formacie csv
        string toCsv(string delimeter);

        ///funkcja odczytuje z napisu w formacie csv dane ucznia
        ///@param text dane do odczytu
        ///@param delimeter odstep pomiedzy danymi
        void fromCsv(string text, string delimeter);
};
