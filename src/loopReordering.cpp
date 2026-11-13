#include <vector>
using namespace std;

/*
This optimization forces matrix A, B and C too all be more cache friendly by
doing row order traversal
System: 
Avg Execution time: 0.00302813seconds
Cache Misses: 1,950,971
Cache References: 142,373,006
IPC: 5.52
Cache Miss Rate: 1.37%
Instructions: 2,210,759,710
*/
void loop_reordering(const vector<vector<float>> &matA, const vector<vector<float>> &matB, vector<vector<float>> &matC){

    int m = matA.size();
    int k = matB.size();
    int n = matC[0].size();
    
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            for(int z = 0; z < n; z++) {
                matC[i][z] += matA[i][j] * matB[j][z];
            }
        }
    }
}