#include <vector>
using namespace std;

/*
This optimization forces matrix A, B and C too all be more cache friendly by
doing row order traversal
System: 
Avg Execution time (wall time): 0.00290997seconds
       387,963,271      cycles                                                                  ( +-  0.36% )  (45.14%)
     2,291,670,190      instructions                     #    5.91  insn per cycle              ( +-  0.52% )  (46.40%)
       827,826,118      L1-dcache-loads                                                         ( +-  0.58% )  (47.26%)
        68,639,356      L1-dcache-load-misses            #    8.29% of all L1-dcache accesses   ( +-  0.55% )  (47.26%)
        67,403,233      l2_cache_accesses_from_dc_misses                                        ( +-  0.64% )  (47.26%)
        66,027,828      l2_cache_hits_from_dc_misses                                            ( +-  0.41% )  (46.07%)
           695,072      l2_cache_misses_from_dc_misses                                          ( +-  1.99% )  (44.80%)
         1,092,855      dTLB-loads                                                              ( +-  0.62% )  (43.95%)
            20,230      dTLB-load-misses                 #    1.85% of all dTLB cache accesses  ( +-  7.68% )  (43.95%)
         1,897,339      cache-misses                     #    1.27% of all cache refs           ( +-  0.98% )  (43.95%)
       149,854,412      cache-references                                                        ( +-  0.49% )  (43.97%)
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