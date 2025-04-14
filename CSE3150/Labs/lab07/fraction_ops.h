#ifndef FRACTION_OPS_H
#define FRACTION_OPS_H

#include <utility>
#include <string>

class bigint;

using bigFraction = std::pair<bigint, bigint>;

bigFraction bigFractionAdd(const bigFraction& a, const bigFraction& b);
bigFraction bigFractionMultiply(const bigFraction& a, const bigFraction& b);

#endif
