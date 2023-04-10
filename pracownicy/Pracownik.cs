using System;

namespace pracownicy
{
    internal class Pracownik
    {

        private string _imie;
        private string _nazwisko;
        private DateTime _dataUrodzenia;
        private string _stanowisko;
        private decimal _pensja;
        private string _rodzajUmowy;


        public string Imie
        {
            get { return _imie; }
            set { _imie = value; }
        }

        public string Nazwisko
        {
            get { return _nazwisko; }
            set { _nazwisko = value; }
        }

        public DateTime DataUrodzenia
        {
            get { return _dataUrodzenia; }
            set
            {
                _dataUrodzenia = value;
            }
        }

        public string Stanowisko
        {
            get { return _stanowisko; }
            set
            {
                _stanowisko = value;
            }
        }

        public decimal Pensja
        {
            get { return _pensja; }
            set
            {
                _pensja = value;
            }
        }

        public string RodzajUmowy
        {
            get { return _rodzajUmowy; }
            set
            {
                _rodzajUmowy = value;
            }
        }

        public override string ToString()
        {
            //return $"IMIE:  {_imie},NAZWISKO: {_nazwisko}, DATA URODZENIA:  {_dataUrodzenia.ToShortDateString()}, STANOWISKO:  {_stanowisko}, PENSJA:  {_pensja}, RODZAJ UMOWY:  {_rodzajUmowy}";
            return $"{_imie};{_nazwisko};{_dataUrodzenia.ToShortDateString()};{_stanowisko};{_pensja};{_rodzajUmowy}";
        }
    }
}