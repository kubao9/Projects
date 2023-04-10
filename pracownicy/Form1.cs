using Microsoft.VisualBasic.FileIO;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace pracownicy
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Pracownik pracownik = new Pracownik();
            pracownik.Imie = pole_imie.Text;
            pracownik.Nazwisko = pole_nazwisko.Text;
            pracownik.DataUrodzenia = pole_data.Value;
            pracownik.Stanowisko = pole_stanowisko.Text;
            pracownik.Pensja = pole_pensja.Value;

            if(radioButton1.Checked)
            {
                pracownik.RodzajUmowy = "umowa zlecenie";
            }


            if (radioButton2.Checked)
            {
                pracownik.RodzajUmowy = "umowa na czas nieokreślony";
            }


            if (radioButton3.Checked)
            {
                pracownik.RodzajUmowy = "umowa na czas określony";
            }


            listBox1.Items.Add(pracownik);

        }

        private void button3_Click(object sender, EventArgs e)
        {
            //StreamWriter myOutputStream = new StreamWriter("C:\\Users\\Kuba\\Desktop\\Myfile.csv");
            StreamWriter myOutputStream = new StreamWriter("Myfile.csv");

            foreach (var item in listBox1.Items)
            {
                myOutputStream.WriteLine(item.ToString());
            }

            myOutputStream.Close();
        }



        private void button2_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            //var path = @"C:\\Users\\Kuba\\Desktop\\Myfile.csv";
            var path = @"Myfile.csv";
            using (TextFieldParser csvParser = new TextFieldParser(path))
            {
                csvParser.CommentTokens = new string[] { "#" };
                csvParser.SetDelimiters(new string[] { ";" });
                csvParser.HasFieldsEnclosedInQuotes = true;

                // Skip the row with the column names
                //csvParser.ReadLine();

                while (!csvParser.EndOfData)
                {
                    Pracownik pracownik = new Pracownik();

                    // Read current line fields, pointer moves to the next line.
                    string[] fields = csvParser.ReadFields();
                    string name = fields[0];
                    string surname = fields[1];
                    string birthday = fields[2];
                    string posession = fields[3];
                    string pension = fields[4];
                    string contract = fields[5];


                    pracownik.Imie = name;
                    pracownik.Nazwisko = surname;

                    DateTime loadedDate = DateTime.ParseExact(birthday, "d", null);

                    pracownik.DataUrodzenia = loadedDate;
                    pracownik.Stanowisko = posession;
                    pracownik.Pensja = int.Parse(pension);
                    pracownik.RodzajUmowy = contract;

                    listBox1.Items.Add(pracownik);

                }
            }
        }

        private void pole_imie_TextChanged(object sender, EventArgs e)
        {
            if(string.IsNullOrEmpty(pole_imie.Text))
            {
                //e.Cancel = true;
                pole_imie.Focus();
                errorProvider1.SetError(pole_imie, "Proszę wprowadzić imię!");

            }
            else
            {
                //e.Cancel = true;
                errorProvider1.SetError(pole_imie, null);
            }
        }

        private void pole_nazwisko_TextChanged(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(pole_nazwisko.Text))
            {
                //e.Cancel = true;
                pole_nazwisko.Focus();
                errorProvider1.SetError(pole_nazwisko, "Proszę wprowadzić nazwisko!");

            }
            else
            {
                //e.Cancel = true;
                errorProvider1.SetError(pole_nazwisko, null);
            }
        }
    }
}
