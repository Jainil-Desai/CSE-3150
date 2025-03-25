#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "cosine_distance.h"


TEST_CASE("file reading") {
    vector<vector<double>> correct_answer = {{1.2, 2.4, 3.6}, {4.8, 6.0, 7.2}};
    vector<vector<double>> current_answer = accessing_file("vector_test.txt");
    CHECK(current_answer == correct_answer);
}

TEST_CASE("sort") {
    vector<pair<pair<int, int>, double>> dist = {{{1, 2}, 0.9}, {{1, 3}, 0.8}, {{2, 3}, 0.7}};
    auto sorted_distances = sorting_function(dist);
    CHECK(sorted_distances.size() == 3);
    CHECK(sorted_distances[0].second == 0.9);
    CHECK(sorted_distances[1].second == 0.8);
    CHECK(sorted_distances[2].second == 0.7);
}

TEST_CASE("2 vect.") {
    vector<vector<double>> vect = {{1, 2, 3}, {4, 5, 6}};
    auto pairs = distance_calculation(vect);
    CHECK(pairs.size() == 1);
    CHECK(pairs[0].second == doctest::Approx(0.974632));
}
TEST_CASE("3 vect.") {
        vector<vector<double>> vect2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        auto pairs = distance_calculation(vect2);
        CHECK(pairs.size() == 3);
        CHECK(pairs[0].second == 0.0);
        CHECK(pairs[1].second == 0.0);
        CHECK(pairs[2].second == 0.0);
    }
TEST_CASE("identical vectors") {
    vector<vector<double>> vect = {{1, 2, 3}, {1, 2, 3}};
    auto pairs = distance_calculation(vect);
    CHECK(pairs.size() == 1);
    CHECK(pairs[0].second == doctest::Approx(1.0));
}
TEST_CASE("zero vector") {
    vector<vector<double>> vect = {{0, 0, 0}, {1, 2, 3}};
    auto pairs = distance_calculation(vect);
    CHECK(pairs.size() == 1);
    CHECK(pairs[0].second == doctest::Approx(0.0)); 
}
