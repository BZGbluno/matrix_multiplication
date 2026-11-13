#ifndef MATRIX_MULT_H
#define MATRIX_MULT_H

#include <vector>
using namespace std;

void naiveMatMul(const vector<vector<float>> &matA, const vector<vector<float>> &matB, vector<vector<float>> &matC);
void loop_reordering(const vector<vector<float>> &matA, const vector<vector<float>> &matB, vector<vector<float>> &matC);
void flattendMatMul(const vector<float> &matA, const vector<float> &matB, vector<float> &matC, int m, int k, int n);
#endif