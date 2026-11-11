#include <iostream>
#include <vector>
#include <chrono>

#include "matrix_tool.h"
#include "matMul.h"

using namespace std;


int main() {

    int m = 3;
    int k = 2;
    int n = 3;
    
    
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
    naiveMatMul(matA, matB, matC);
    auto end = chrono::steady_clock::now();

    printMat(matC, m, n);

    chrono::duration<double> elapsed = end - startTime;

    cout << "Execution time: " << elapsed.count() << "seconds" << endl;



    return 0;
}