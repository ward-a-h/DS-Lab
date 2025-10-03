#include <iostream>
using namespace std;

bool isSafe(char** arr, int x, int y, int n) {
    for (int row = 0; row < x; row++) {
        if (arr[row][y] == 'Q') {
            return false;
        }
    }

    int row = x, col = y;
    while (row >= 0 && col >= 0) {
        if (arr[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n) {
        if (arr[row][col] == 'Q') {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(char** arr, int x, int n) {
    if (x >= n) {
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(arr, x, col, n)) {
            arr[x][col] = 'Q';

            if (nQueen(arr, x + 1, n)) {
                return true;
            }

            arr[x][col] = '.';
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    char** arr = new char*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new char[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = '.';
        }
    }

    if (nQueen(arr, 0, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
