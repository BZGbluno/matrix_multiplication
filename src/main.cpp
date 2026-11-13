#include <iostream>
#include <vector>
#include <chrono>

#include "matrix_tool.h"
#include "matMul.h"

using namespace std;


int main() {

    int m = 1024;
    int k = 1024;
    int n = 1024;
    
    
    // // m x k
    // vector<vector<float>> matA(m, vector<float>(k, 0.0f));
    // fillMat(matA, m, k);

    // // k x n
    // vector<vector<float>> matB(k, vector<float>(n, 0.0f));
    // fillMat(matB, k, n);

    // // m x n
    // vector<vector<float>> matC(m, vector<float>(n, 0.0f));

    vector<float> flatMatA(m*k, 0.0f);
    vector<float> flatMatB(k*n, 0.0f);
    
    fillVecMat(flatMatA, m, k);
    fillVecMat(flatMatB, k, n);
    vector<float> flatMatC(m * n, 0.0f);


    auto startTime = chrono::steady_clock::now();
    // loop_reordering(matA, matB, matC);
    // naiveMatMul(matA, matB, matC);
    flattendMatMul(flatMatA, flatMatB, flatMatC, m, k, n);

    
    auto end = chrono::steady_clock::now();
        
    chrono::duration<double> elapsed = end - startTime;

    cout << "Execution time: " << elapsed.count() / 25 << "seconds" << endl;
        


    return 0;
}