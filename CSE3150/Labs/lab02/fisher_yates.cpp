#include "fisher_yates.h"
#include <cstdlib>

bool isWellBalanced(const std::vector<int>& array) 
{
    int currentSum = 0;
    
    for (int i : array) {
        currentSum += i;
        if (currentSum < 0) {
            return false; 
        }
    }
    
    return true;
}

void fisherYatesShuffle(std::vector<int>& array) 
{
    int n = array.size();

    for (int j = n - 1; j > 0; --j) {
        int k = std::rand() % (j + 1);
        std::swap(array[j], array[k]);
    }
}