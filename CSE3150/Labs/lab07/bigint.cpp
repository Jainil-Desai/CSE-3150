#include "bigint.h"
#include <algorithm>


std::string bigint::add(std::string a, std::string b) {
    std::string result = "";
    int carry = 0;

    int n1 = a.size();
    int n2 = b.size();
    int diff = abs(n1 - n2);

    if (n1 < n2)
        a.insert(0, diff, '0');
    else
        b.insert(0, diff, '0');

    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result.insert(0, 1, (sum % 10) + '0');
    }

    if (carry)
        result.insert(0, 1, carry + '0');

    return result;
}

// Helper: multiply two numeric strings
std::string bigint::multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int len1 = num1.size();
    int len2 = num2.size();
    std::vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2];

            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }

    std::string str;
    for (int num : result)
        if (!(str.empty() && num == 0)) str += std::to_string(num);
    return str.empty() ? "0" : str;
}
