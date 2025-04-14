#include <iostream>
#include <chrono>
#include "bigint.h"

using namespace std;
using namespace std::chrono;

int main() {
    const int iterations = 100000;

    // Test int
    {
        int a = 12345, b = 6789, result;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < iterations; i++) {
            result = a * b;
        }
        auto end = high_resolution_clock::now();
        cout << "int multiply time: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    }

    // Test long
    {
        long a = 123456789L, b = 987654321L, result;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < iterations; i++) {
            result = a * b;
        }
        auto end = high_resolution_clock::now();
        cout << "long multiply time: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    }

    // Test bigint
    {
        bigint a("123456789123456789"), b("987654321987654321"), result("0");
        auto start = high_resolution_clock::now();
        for (int i = 0; i < 100000; i++) {  // fewer iterations for bigint
            result = a * b;
        }
        auto end = high_resolution_clock::now();
        cout << "bigint multiply time: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    }

    return 0;
}
