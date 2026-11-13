#include <gtest/gtest.h>
#include "matMul.h"


TEST(LoopReordering, TwoByTwo) {
    std::vector<std::vector<float>> A = {
        {1, 2},
        {3, 4}
    };

    std::vector<std::vector<float>> B = {
        {5, 6},
        {7, 8}
    };

    std::vector<std::vector<float>> C(2, std::vector<float>(2, 0));

    loop_reordering(A, B, C);

    EXPECT_FLOAT_EQ(C[0][0], 19.0f);
    EXPECT_FLOAT_EQ(C[0][1], 22.0f);
    EXPECT_FLOAT_EQ(C[1][0], 43.0f);
    EXPECT_FLOAT_EQ(C[1][1], 50.0f);
}