#include <string>

///struktura przechowujaca parametry programu
struct ProgramData
{

    ///sciezka odczytu pliku ksiazek
    std::string bookPath = "books";
    ///sciezka odczytu pliku uczniow
    std::string studentsPath = "students";
    ///sciezka odczytu pliku wypozyczen
    std::string rentalsPath = "rentals";

};

///funkcja wczytuje i parametry do programu w postaci struktury ProgramData
///@param argc ilosc parametrow w programie
///@param argv[] tablica parametrow
ProgramData initData(int argc, char* argv[]);
