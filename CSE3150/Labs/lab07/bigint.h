#ifndef BIGINT_H
#define BIGINT_H

#include <string>

class bigint {
public:
    std::string str;

    bigint() : str("0") {}
    bigint(const std::string& s) : str(s) {}
    bigint(const char* s) : str(s) {}

    static std::string add(std::string a, std::string b);
    static std::string multiply(std::string a, std::string b);

    friend bigint operator+(const bigint& a, const bigint& b) {
        return bigint(add(a.str, b.str));
    }

    friend bigint operator*(const bigint& a, const bigint& b) {
        return bigint(multiply(a.str, b.str));
    }

    bool operator==(const bigint& other) const {
        return str == other.str;
    }

    friend std::ostream& operator<<(std::ostream& os, const bigint& b) {
        os << b.str;
        return os;
    }
};

#endif // BIGINT_H
