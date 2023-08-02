#include "floyd.h"

#include <gtest/gtest.h>

class FloydTest : public ::testing::Test {
   public:
    int size = 5;
    std::vector<std::vector<int>> tab{std::vector<std::vector<int>>(size, std::vector<int>(size, 0))};
    std::vector<std::vector<int>> distances{std::vector<std::vector<int>>(size, std::vector<int>(size, 0))};

   protected:
    void SetUp() override {
        tab[0][0] = 0;
        tab[0][1] = 1;
        tab[0][2] = -1;
        tab[0][3] = 1;
        tab[0][4] = 5;
        tab[1][0] = 9;
        tab[1][1] = 0;
        tab[1][2] = 3;
        tab[1][3] = 2;
        tab[1][4] = -1;
        tab[2][0] = -1;
        tab[2][1] = -1;
        tab[2][2] = 0;
        tab[2][3] = 4;
        tab[2][4] = -1;
        tab[3][0] = -1;
        tab[3][1] = -1;
        tab[3][2] = 2;
        tab[3][3] = 0;
        tab[3][4] = 3;
        tab[4][0] = 3;
        tab[4][1] = -1;
        tab[4][2] = -1;
        tab[4][3] = -1;
        tab[4][4] = 0;
    }

    void TearDown() override {}
};

TEST_F(FloydTest, floydAlrorithm_ok) {
    floyd::floyd(tab, distances);

    std::vector<std::vector<int>> tabRef{std::vector<std::vector<int>>(size, std::vector<int>(size, 0))};
    tabRef[0][0] = 0;
    tabRef[0][1] = 1;
    tabRef[0][2] = 3;
    tabRef[0][3] = 1;
    tabRef[0][4] = 4;
    tabRef[1][0] = 8;
    tabRef[1][1] = 0;
    tabRef[1][2] = 3;
    tabRef[1][3] = 2;
    tabRef[1][4] = 5;
    tabRef[2][0] = 10;
    tabRef[2][1] = 11;
    tabRef[2][2] = 0;
    tabRef[2][3] = 4;
    tabRef[2][4] = 7;
    tabRef[3][0] = 6;
    tabRef[3][1] = 7;
    tabRef[3][2] = 2;
    tabRef[3][3] = 0;
    tabRef[3][4] = 3;
    tabRef[4][0] = 3;
    tabRef[4][1] = 4;
    tabRef[4][2] = 6;
    tabRef[4][3] = 4;
    tabRef[4][4] = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            EXPECT_EQ(tab[i][j], tabRef[i][j]);
        }
    }

    testing::internal::CaptureStdout();

    floyd::path(distances, 4, 2);

    std::string output{testing::internal::GetCapturedStdout()};

    EXPECT_EQ("v1 v4 ", output);
}