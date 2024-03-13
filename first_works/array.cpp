#include <iostream>

using namespace std;

int main()
{
    int N, k = 0, m = 0;
    cout << "Введите N: ";
    cin >> N;

    int *X = new int[N];
    int *Y = new int[N];
    int *Z = new int[N];

    cout << "Вводите элементы массива X: ";
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        if (X[i] >= 0) {
            Y[k] = X[i];
            k++;
        } else {
            Z[m] = X[i];
            m++;
        }
    }

    int max_Y = Y[0], max_Z = Z[0];

    cout << "Массив Y: ";
    for (int i = 0; i < k; i++) {
        cout << Y[i] << " ";
        if (Y[i] > max_Y) {
            max_Y = Y[i];
        }
    }
    cout << endl;

    cout << "Массив Z: ";
    for (int i = 0; i < m; i++) {
        cout << Z[i] << " ";
        if (Z[i] > max_Z) {
            max_Z = Z[i];
        }
    }
    cout << endl;

    cout << "Максимальный элемент Y: " << max_Y << endl;
    cout << "Максимальный элемент Z: " << max_Z << endl;

    for (int i = 0; i < N-1; i++) {
        X[i] = X[i+1];
    }
    cout << "Массив X: ";
    for(int i = 0; i < N-1; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;

    free(X);
    free(Y);
    free(Z);

    return 0;
}
