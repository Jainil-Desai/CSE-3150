#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"

TEST_CASE("Non-negative Prefix Sum - Valid Case 1") {
    int testArray1[] = {1, -1, 1, -1}; 
    CHECK(non_neg_prefix_sum(testArray1, 4) == true);
}

TEST_CASE("Non-negative Prefix Sum - Valid Case 2") {
    int testArray2[] = {1, 1, -1, 1, -1, -1};  
    CHECK(non_neg_prefix_sum(testArray2, 6) == true);
}

TEST_CASE("Non-negative Prefix Sum - Invalid Case") {
    int testArray3[] = {1, -1, -1, -1};  
    CHECK(non_neg_prefix_sum(testArray3, 4) == false);
}

TEST_CASE("Non-negative Prefix Sum - Empty Array") {
    int testArray4[] = {};  
    CHECK(non_neg_prefix_sum(testArray4, 0) == true);
}

TEST_CASE("Non-negative Prefix Sum - Single Positive Element") {
    int testArray5[] = {1}; 
    CHECK(non_neg_prefix_sum(testArray5, 1) == true);
}

TEST_CASE("Non-positive Prefix Sum - Valid Case 1") {
    int testArray6[] = {-1, 1, -1, 1}; 
    CHECK(non_pos_prefix_sum(testArray6, 4) == true);
}

TEST_CASE("Non-positive Prefix Sum - Valid Case 2") {
    int testArray7[] = {-1, -1, 1, -1, -1, 1}; 
    CHECK(non_pos_prefix_sum(testArray7, 6) == true);
}

TEST_CASE("Non-positive Prefix Sum - Invalid Case") {
    int testArray8[] = {-1, 1, 1, -1};  
    CHECK(non_pos_prefix_sum(testArray8, 4) == false);
}

TEST_CASE("Non-positive Prefix Sum - Empty Array") {
    int testArray9[] = {};  
    CHECK(non_pos_prefix_sum(testArray9, 0) == true);
}

TEST_CASE("Non-positive Prefix Sum - Single Negative Element") {
    int testArray10[] = {-1}; 
    CHECK(non_pos_prefix_sum(testArray10, 1) == true);
}
