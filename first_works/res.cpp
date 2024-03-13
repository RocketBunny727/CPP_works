#include "header.h"

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