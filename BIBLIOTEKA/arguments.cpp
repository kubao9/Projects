#include "arguments.h"
#include <cstring>
#include <iostream>
#include <conio.h>

using namespace std;

void displayHelp()
{
    cout << "Program requires following arguments: " << endl;
    cout << "-b books file path  " << endl;
    cout << "-s students file path " << endl;
    cout << "-r rentals file path " << endl;
}

void handleError()
{
    cout << "Press any key to close...";
    _getch();
    exit(1);
}

ProgramData initData(int argc, char* argv[])
{
    if(argc==1)
    {
        displayHelp();
        handleError();
    }
    if(argc!=7)
    {
        cout<<"Incorrect amount of arguments"<<endl;
        displayHelp();
        handleError();
    }

    ProgramData result;
    for(int i=1;i<argc;i+=2)
    {
        if (argv[i+1][0] == '-') continue;
        if(strcmp(argv[i],"-b")==0)
        {
            result.bookPath=argv[i+1];

        }
        else if(strcmp(argv[i],"-s")==0)
        {
            result.studentsPath=argv[i+1];
        }

        else if(strcmp(argv[i],"-r")==0)
        {
            result.rentalsPath=argv[i+1];
        }
    }

    if (result.bookPath == result.studentsPath || result.bookPath == result.rentalsPath || result.rentalsPath == result.studentsPath)
    {
        cout<<"All paths need to be unique"<<endl;
        handleError();
    }

    return result;
}
