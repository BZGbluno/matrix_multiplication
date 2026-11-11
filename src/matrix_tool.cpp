#include <iostream>
#include <vector>


using namespace std;

void fillMat(vector<vector<float>> &mat, int r, int c) {

    int sum = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            mat[i][j] = sum;
            sum += 1;
        }
    }
}

void printMat(vector<vector<float>> &mat, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}