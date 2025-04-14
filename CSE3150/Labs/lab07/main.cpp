#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fraction_ops.h"
#include "bigint.h"

TEST_CASE("BigFraction Addition") {
    bigFraction f1 = {bigint("1"), bigint("2")};
    bigFraction f2 = {bigint("1"), bigint("3")};
    bigFraction result = bigFractionAdd(f1, f2);

    CHECK(result.first == bigint("5"));
    CHECK(result.second == bigint("6"));
}

TEST_CASE("BigFraction Multiplication") {
    bigFraction f1 = {bigint("2"), bigint("3")};
    bigFraction f2 = {bigint("3"), bigint("4")};
    bigFraction result = bigFractionMultiply(f1, f2);

    CHECK(result.first == bigint("6"));
    CHECK(result.second == bigint("12"));
}
