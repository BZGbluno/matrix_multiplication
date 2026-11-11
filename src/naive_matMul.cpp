#include <vector>
using namespace std;

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