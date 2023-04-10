#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <conio.h>
#include "Serializer.h"
#include "Books.h"
#include "Students.h"
#include "Rentals.h"
#include "arguments.h"

using namespace std;

void deserialize(vector<shared_ptr<Serializer>> serializers)
{
    for (auto&& serializer : serializers)
    {
        serializer->deserialize();
    }
}

///funkcja do wyswietlanie menu
void displayMenu()
{
    cout<<"********************* Welcome To Library Management System ********************"<<endl;
    cout<<"What would you want me to do ?"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"1. Add Book"<<endl;
    cout<<"2. View Book"<<endl;
    cout<<"3. Search Book"<<endl;
    cout<<"4. Remove Book"<<endl;
    cout<<"5. Add Student"<<endl;
    cout<<"6. View Student"<<endl;
    cout<<"7. Search Student"<<endl;
    cout<<"8. Remove Student"<<endl;
    cout<<"9. Add Rental"<<endl;
    cout<<"10. View Rental"<<endl;
    cout<<"11. Search Rental"<<endl;
    cout<<"12. Remove Rental"<<endl;
}
///funkcja czeka na wybor polecenia
void operationConfirmation()
{
    cout << "Press any key to go back to menu...";
    _getch();
}
///glowna funkcja obsugujaca polecenia w programie
int main(int argc, char* argv[])
{
    ProgramData data=initData(argc,argv);

    auto books = make_shared<Books>(data.bookPath);
    auto students = make_shared<Students>(data.studentsPath);
    auto rentals = make_shared<Rentals>(data.rentalsPath, books.get(), students.get());

    vector<shared_ptr<Serializer>> serializers;
    serializers.push_back(books);
    serializers.push_back(students);
    serializers.push_back(rentals);

    deserialize(serializers);

    int choice = 0;
    bool requestedExit = false;

    while(!requestedExit)
    {
        system("CLS");

        displayMenu();
        cin>>choice;

        system("CLS");

        switch (choice)
        {
            case 0:
            {
                requestedExit = true;
                break;
            }
            case 1: // add book
            {
                books->add();
                break;
            }

            case 2: // view books
            {
                books->display();
                break;
            }

            case 3: // search book
            {
                books->search();
                break;
            }

            case 4: // remove book
            {
                books->remove();
                break;
            }

            case 5: // add student
            {
                students->add();
                break;
            }

            case 6: // view students
            {
                students->display();
                break;
            }

            case 7: // search student
            {
                students->search();
                break;
            }

            case 8: // remove student
            {
                students->remove();
                break;
            }

            case 9: // add rental
            {
                rentals->add();
                break;
            }

            case 10: // view rentals
            {
                rentals->display();
                break;
            }

            case 11: // search rental
            {
                rentals->search();
                break;
            }

            case 12: // remove rentals
            {
                rentals->remove();
                break;
            }

            default:
            {
                cout << "Unknown option. Choose correct option number." << endl;
                break;
            }
        }

        if (!requestedExit) operationConfirmation();
    }

    cout<<"Thank You for using our software"<<endl<<"Have a Nice Day !"<<endl;
    return 0;
}
