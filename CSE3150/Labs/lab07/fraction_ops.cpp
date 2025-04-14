#include "fraction_ops.h"
#include "bigint.h"

bigFraction bigFractionAdd(const bigFraction& a, const bigFraction& b) {
    bigint a1 = a.first;
    bigint b1 = a.second;
    bigint a2 = b.first;
    bigint b2 = b.second;

    bigint numerator = (a1 * b2) + (a2 * b1);
    bigint denominator = b1 * b2;

    return std::make_pair(numerator, denominator);
}

bigFraction bigFractionMultiply(const bigFraction& a, const bigFraction& b) {
    bigint a1 = a.first;
    bigint b1 = a.second;
    bigint a2 = b.first;
    bigint b2 = b.second;

    bigint numerator = a1 * a2;
    bigint denominator = b1 * b2;

    return std::make_pair(numerator, denominator);
}
