#include <vector>
using namespace std;
/*
System: 
Avg Execution time: 0.00305614seconds
Cache Misses: 1,678,941
Cache References: 140,247,121
IPC: 5.54
Cache Miss Rate: 1.20%
Instructions: 2,212,899,287
*/
void flattendMatMul(const vector<float> &matA, const vector<float> &matB, vector<float> &matC, int m, int k, int n) {

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            for(int z = 0; z < n; z++) {
                matC[i * m + z] += matA[i * m + j] * matB[j * k + z];
            }
        }
    }

}