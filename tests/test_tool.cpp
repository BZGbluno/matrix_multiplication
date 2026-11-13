#include <gtest/gtest.h>
#include "matrix_tool.h"

TEST(FlattenMat, TwoByTwo) {
    std::vector<std::vector<float>> A = {
        {1, 2},
        {3, 4}
    };

    std::vector<float> vec = flattenMat(A, 2, 2); 

    EXPECT_FLOAT_EQ(vec[0], 1.0f);
    EXPECT_FLOAT_EQ(vec[1], 2.0f);
    EXPECT_FLOAT_EQ(vec[2], 3.0f);
    EXPECT_FLOAT_EQ(vec[3], 4.0f);
}