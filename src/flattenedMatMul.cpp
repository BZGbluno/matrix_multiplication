#include <vector>
using namespace std;
/*
System: 
Avg Execution time (wall time): 0.00297248seconds
       393,589,157      cycles                                                                  ( +-  1.07% )  (44.18%)
     2,266,047,078      instructions                     #    5.76  insn per cycle              ( +-  0.48% )  (44.14%)
       824,729,354      L1-dcache-loads                                                         ( +-  0.55% )  (44.15%)
        67,686,464      L1-dcache-load-misses            #    8.21% of all L1-dcache accesses   ( +-  0.57% )  (45.22%)
        66,235,086      l2_cache_accesses_from_dc_misses                                        ( +-  0.50% )  (46.39%)
        65,320,300      l2_cache_hits_from_dc_misses                                            ( +-  0.70% )  (46.51%)
           504,011      l2_cache_misses_from_dc_misses                                          ( +-  2.21% )  (46.55%)
         1,073,044      dTLB-loads                                                              ( +-  0.55% )  (46.54%)
            17,707      dTLB-load-misses                 #    1.65% of all dTLB cache accesses  ( +-  9.32% )  (46.56%)
         1,652,789      cache-misses                     #    1.12% of all cache refs           ( +-  1.52% )  (45.47%)
       148,150,880      cache-references                                                        ( +-  0.36% )  (44.30%)
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