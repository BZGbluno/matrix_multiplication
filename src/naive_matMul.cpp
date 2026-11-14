#include <vector>
using namespace std;
/*
System: 
Avg Execution time (wall time): 0.0275525seconds
     3,391,855,595      cycles                                                                  ( +-  0.03% )  (45.35%)
     8,665,555,633      instructions                     #    2.55  insn per cycle              ( +-  0.03% )  (45.49%)
     3,239,453,597      L1-dcache-loads                                                         ( +-  0.03% )  (45.60%)
     1,556,872,556      L1-dcache-load-misses            #   48.06% of all L1-dcache accesses   ( +-  0.03% )  (45.60%)
     1,552,458,529      l2_cache_accesses_from_dc_misses                                        ( +-  0.03% )  (45.61%)
     1,513,746,967      l2_cache_hits_from_dc_misses                                            ( +-  0.05% )  (45.59%)
        32,256,903      l2_cache_misses_from_dc_misses                                          ( +-  0.12% )  (45.45%)
     1,090,365,187      dTLB-loads                                                              ( +-  0.04% )  (45.33%)
            23,543      dTLB-load-misses                 #    0.00% of all dTLB cache accesses  ( +-  5.24% )  (45.33%)
       266,476,393      cache-misses                     #   14.46% of all cache refs           ( +-  0.07% )  (45.33%)
     1,842,301,867      cache-references                                                        ( +-  0.03% )  (45.32%)
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