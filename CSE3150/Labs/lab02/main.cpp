#include <iostream>
#include <vector>
#include <cstdlib> 
#include "fisher_yates.h"

std::vector<int> generateRandomSequence(int n) 
{
    std::vector<int> sequence;
    for (int i = 0; i < 2 * n; ++i) {
        int num = (std::rand() % 2 == 0) ? 1 : -1; 
        sequence.push_back(num);
    }
    return sequence;
}

int main() 
{
    int n; 
    std::cout << "Enter n: ";
    std::cin >> n;

    int totalSequences = 0;
    int wellBalancedSequences = 0;

    while (totalSequences < 10000) { 
        std::vector<int> sequence = generateRandomSequence(n);
        fisherYatesShuffle(sequence);
 
        if (isWellBalanced(sequence)) {
            wellBalancedSequences++;
        }

        totalSequences++;
    }

    double proportion = static_cast<double>(wellBalancedSequences) / totalSequences;

    std::cout << "Total runs: " << totalSequences << std::endl;
    std::cout << "Well-balanced count: " << wellBalancedSequences << std::endl;
    std::cout << "Proportion of well-balanced lists: " << proportion << std::endl;

    return 0;
}