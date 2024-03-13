#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



class company
{
    public:
        string country;
        string equipment;
        int year;
        
        void input()
        {
            cout << "Введите страну: ";
            cin >> country;
            cout << "Введите тип оборудования: ";
            cin >> equipment;
            cout << "Введите год создания компании: ";
            cin >> year;
        }

        void output()
        {
            cout<<"Страна:"<<country<<endl;
            cout<<"Тип оборудования:"<<equipment<<endl;
            cout<<"Год создания: "<<year<<endl;
        }

};

int main()
{
    int size;

    cout << "Enter size of vector: ";
    cin >> size;

    vector <company> comp;
    company buff;

    cout << "Введите информацию о производящей компании\n" << endl;

    for(int i = 0; i < size; i++)
    {
        buff.input();
        comp.push_back(buff);
        cout << endl;
    }

    system("clear");

    for(int i = 0; i < size; i++)
    {
        comp[i].output();
        cout << endl;
    }

    vector <company> newcomp;
    int newsize = 0;

    for(int i = 0; i < size; i++)
    {
        if(comp[i].year > 1950)
        {
            buff.country = comp[i].country;
            buff.equipment = comp[i].equipment;
            buff.year = comp[i].year;
            newcomp.push_back(buff);
            newsize++;
        }
    }

    cout << "==============newcomp==============" << endl;

    for(int i = 0; i < newsize; i++)
    {
        newcomp[i].output();
        cout << endl;
    }
    return 0;
}