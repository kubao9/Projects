#pragma once
#include<string>

using namespace std;

///klasa bazowa zapewniajaca mozliwosc zapisu i odczytu z pliku w formacie csv
class Serializer
{
    protected:
        string filePath;
        string delimiter = ";";

    public:
        ///konstruktor
        ///@param fileName nazwa pliku
        Serializer(string filePath)
        {
            this -> filePath = filePath;
        };

        /// funkcja podaje odstep pomiędzy danymi
        ///@return odstep pomiędzy danymi
        string getDelimeter()
        {
            return delimiter;
        }

        ///funkcja wirtualna obslugujaca zapis do pliku
        virtual void serialize()
        {
            cout << "Serialization not implemented";
        };

        ///funkcja wirtualna obslugujaca odczyt z pliku
        virtual void deserialize()
        {
            cout << "Deserialization not implemented";
        };
};
