#include <vector>
using namespace std;
/*
System: 
Avg Execution time: 0.0277771seconds
Cache Misses: 269,838,197
Cache References: 1,834,681,480 
IPC: 2.53
Cache Miss Rate: 14.71%
Instructions: 8,641,081,341
*/
void naiveMatMul(const vector<vector<float>> &matA, const vector<vector<float>> &matB, vector<vector<float>> &matC) {

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