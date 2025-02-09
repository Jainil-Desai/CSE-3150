#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"

TEST_CASE("Fisher-Yates Shuffle Test") {

    SUBCASE("Convergence Test") {
        std::vector<int> sequence = {1, 2, 3, 4, 5};
        fisherYatesShuffle(sequence);
        CHECK(sequence.size() == 5);

        for (int i = 0; i < 1000; ++i) {
            fisherYatesShuffle(sequence);
            CHECK(std::is_permutation(sequence.begin(), sequence.end(), std::vector<int>({1, 2, 3, 4, 5}).begin()));
        }
    }

    SUBCASE("Proportion Calculation Test") {
        std::vector<int> sequence = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        fisherYatesShuffle(sequence);
        CHECK(sequence.size() == 10);

        CHECK(isWellBalanced(sequence));
    }
}