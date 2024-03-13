#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

class quadro
{
    public:
        double x1, x2, x3, x4, y1, y2, y3, y4;

        quadro(double X1, double X2, double X3, double X4, double Y1, double Y2, double Y3, double Y4)
        {
            x1 = X1;
            x2 = X2;
            x3 = X3;
            x4 = X4;
            y1 = Y1;
            y2 = Y2;
            y3 = Y3;
            y4 = Y4;
        }
        int check()
        {
            double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); 
            double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
            double c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
            double d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));

            double e = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
            double f = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2));

            if (a + b + c > d && a + b + d > c && a + c + d > b && b + c + d > a && e + f > 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        double perimeter()
        {
            double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
            double c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
            double d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
            return a + b + c + d;
        }
        double area()
        {
        double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        double c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
        double d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
        double p = (a + b + c + d) / 2;
        double area = sqrt((p - a) * (p - b) * (p - c) * (p - d));
        return area;
        }
        void output()
        {
            cout << "Периметр: " << perimeter() << endl;
            cout << "Площадь: " << area() << endl;
        }
};

class paralelogram: public quadro
{
    public:
        paralelogram(double X1, double X2, double X3, double X4, double Y1, double Y2, double Y3, double Y4) : quadro(X1, X2, X3, X4, Y1, Y2, Y3, Y4)
        {
            // par.x1 = X1;
            // par.x2 = X2;
            // par.x3 = X3;
            // par.x4 = X4;
            // par.y1 = Y1;
            // par.y2 = Y2;
            // par.y3 = Y3;
            // par.y4 = Y4;
        }
        int check()
        {
            double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
            double c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
            double d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));

            if(a == c && b == d)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
};

int main()
{
    int menu, num, areaSR, perimSR;
    int points[8];

    cout << "Выберите фигуру" << endl << "1 - Произвольный 4х-угольник" << endl << "2 - Паралелограмм" << endl;
    cin >> menu;
    
    for(int i = 0, j = 0; i < 8; i += 2)
    {
        cout << "Введите координаты X" << j + 1 << "Y" << j+1 << ": " << endl;
        cin >> points[i];
        cin >> points[i + 1];
        j++;
    }

    if(menu == 1)
    {
        quadro qwerty(points[1], points[3], points[5], points[7], points[2], points[4], points[6], points[8]);
            if(qwerty.check() == 1)
            {
                cout << "Является четырехугольником" << endl;
                qwerty.output();
            }
            else
            {
                cout << "Не является четырехугольником" << endl;
            }
    }
    else if(menu == 2)
    {
        paralelogram qwerty(points[1], points[3], points[5], points[7], points[2], points[4], points[6], points[8]);
            if(qwerty.check() == 1)
            {
                cout << "Является паралелограммом" << endl;
                qwerty.output();
            }
            else
            {
                cout << "Не является паралелограммом" << endl;
            }
    }    

    cout << "Введите колличество паралелограммов: " << endl;
    cin >> num;

    for(int i = 0; i < 8; i++)
    {
        points[i] = rand()%10;
    }

    for(int i = 0; i < num; i++)
    {
        paralelogram New();
    }

    return 0;
}
