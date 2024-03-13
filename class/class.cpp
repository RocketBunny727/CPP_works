#include <iostream>
#include <string.h>

using namespace std;

class company
{
    private:
        string country;
        string equipment;
    public:
        company(string cntry, string eqmnt)
        {
            country = cntry;
            equipment = eqmnt;
        }
        string getCntry()
        {
            return country;
        }
        string getEqmnt()
        {
            return equipment;
        }
        void setCntry(string cntry)
        {
            country = cntry;
        }
        void setEqmnt(string eqmnt)
        {
            equipment = eqmnt;
        }
        void output()
        {
            cout<<"Страна:"<<country<<endl;
            cout<<"Тип оборудования:"<<equipment<<endl;
        }
};

int main()
{
    string cntry, eqpmnt;
    cout << "Введите страну" << endl;
    cin >> cntry;
    cout << "Введите тип оборудования" << endl;
    cin >> eqpmnt;
    company cmp(cntry, eqpmnt);
    cmp.output();
    cout << "Введите страну" << endl;
    cin >> cntry;
    cout << "Введите тип оборудования" << endl;
    cin >> eqpmnt;
    cmp.setCntry(cntry);
    cmp.setEqmnt(eqpmnt);
    cmp.output();

    company cmp2("German", "Автомобили");
    cmp2.output();
    return 0;
}