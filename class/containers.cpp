#include <iostream>
#include <vector>
#include <string>
#include <algorithmes>

using namespace std;

class person
{
    public:
        int phNumber;
        string surname;
        int passNumber;

    void input()
    {
        cout << "Введите фамилию: ";
        cin >> surname;
        cout << "\nВведите номер телефона: ";
        cin >> phNumber;
        cout << "\nВведите номер пасспорта: ";
        cin >> passNumber;
        cout << endl;
    }

    void output()
    {
        cout << "ФИО: " << surname << "\0" << name << " " << patronymic << endl;
        cout << "Номер телефона: " << phNumber << endl;
        cout << "Номер пасспорта: " << passNumber << endl;
    }

}

void sortStorage(vector *str)
{
    for()
}

int main()
{

    vector <person> storage;
    person buff;
    int size;

    cout << "Введите колличество персон: ";
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        buff.input();
        storage.push_back(buff);
    }

    
        
    return 0;
}