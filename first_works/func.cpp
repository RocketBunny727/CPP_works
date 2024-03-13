#include <iostream>

using namespace std;

void formArrayY(int* X, int N, int* Y, int& k) {
    for (int i = 0; i < N; i++) {
        if (X[i] >= 0) {
            Y[k] = X[i];
            k++;
        }
    }
}

void formArrayZ(int* X, int N, int* Z, int& m) {
    for (int i = 0; i < N; i++) {
        if (X[i] < 0) {
            Z[m] = X[i];
            m++;
        }
    }
}

int findMaxAbsoluteElement(int* arr, int size) {
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) > abs(maxElement)) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

void removeFirstElement(int* arr, int& size) {
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main() {
    int N, k = 0, m = 0;
    cout << "Введите N: ";
    cin >> N;

    int* X = new int[N];
    int* Y = new int[N];
    int* Z = new int[N];

    cout << "Вводите элементы массива X: ";
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    formArrayY(X, N, Y, k);
    formArrayZ(X, N, Z, m);

    int max_Y = findMaxAbsoluteElement(Y, k);
    int max_Z = findMaxAbsoluteElement(Z, m);

    cout << "Массив Y: ";
    for (int i = 0; i < k; i++) {
        cout << Y[i] << " ";
    }
    cout << endl;

    cout << "Массив Z: ";
    for (int i = 0; i < m; i++) {
        cout << Z[i] << " ";
    }
    cout << endl;

    cout << "Максимальный по модулю элемент Y: " << max_Y << endl;
    cout << "Максимальный по модулю элемент Z: " << max_Z << endl;

    removeFirstElement(X, N);

    cout << "Массив X: ";
    for (int i = 0; i < N; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    delete[] X;
    delete[] Y;
    delete[] Z;

    return 0;
}
