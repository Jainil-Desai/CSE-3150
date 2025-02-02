#include "prefix_sum.h"
#include <iostream>

bool non_neg_prefix_sum(int array[], int length) // should not go below 0
{
    int currentSum = 0;

    for (int i = 0; i < length; i++) {
        currentSum +=  array[i];

        if (currentSum < 0) {
            return false;
        }
    }

    return true;
}

bool non_pos_prefix_sum(int array[], int length) // should not go above 0
{
    int currentSum = 0;

    for (int j = 0; j < length; j++) {
        currentSum += array[j];

        if (currentSum > 0) {
            return false;
        }
    }

    return true;
}

