#include <iostream>
#include <vector>
#include <chrono>

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
            cout << mat[i][j];
        }
        cout << endl;
    }
}


void matMul(const vector<vector<float>> &matA, const vector<vector<float>> &matB, vector<vector<float>> &matC) {

    int m = matA.size();
    int k = matB.size();
    int n = matC[0].size();
    
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            float sum = 0.0f;
            for(int z = 0; z < k; z++) {
                sum += matA[i][z] * matB[z][j];
            }

            matC[i][j] = sum;
        }
    }



}

int main() {

    int m = 100;
    int k = 50;
    int n = 60;
    
    // vector<int, vector<int>> matA = vector(1);

    // m x k
    vector<vector<float>> matA(m, vector<float>(k, 0.0f));
    fillMat(matA, m, k);
    // printMat(matA, m, k);
    cout << endl;

    // k x n
    vector<vector<float>> matB(k, vector<float>(n, 0.0f));
    fillMat(matB, k, n);
    // printMat(matB, k, n);
    cout << endl;
    // m x n
    vector<vector<float>> matC(m, vector<float>(n, 0.0f));
    // printMat(matC, m, n);


    auto startTime = chrono::steady_clock::now();
    matMul(matA, matB, matC);
    auto end = chrono::steady_clock::now();

    chrono::duration<double> elapsed = end - startTime;

    cout << "Execution time: " << elapsed.count() << "seconds" << endl;



    return 0;
}