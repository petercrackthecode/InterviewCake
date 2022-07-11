// link: https://www.interviewcake.com/question/cpp/highest-product-of-3?course=fc1&section=greedy
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits.h>

int highestProductOf3(const vector<int>& vectorOfInts)	{
    // calculate the highest product of three numbers
    if (vectorOfInts.size() < 3) {
    	throw new std::exception();
    }

    int highestProductOf3{INT_MIN},
    	highestProductOf2{vectorOfInts[0] * vectorOfInts[1]},
    	highest{std::max(vectorOfInts[0], vectorOfInts[1])},
    	lowestProductOf2{vectorOfInts[0] * vectorOfInts[1]},
    	lowest{std::min(vectorOfInts[0], vectorOfInts[1])};

    for (int index= 2; index < vectorOfInts.size(); ++index) {
    	int currentNum= vectorOfInts[index];

    	highestProductOf3= std::max(highestProductOf3,
    								std::max(currentNum * highestProductOf2, currentNum * lowestProductOf2));
    	highestProductOf2= std::max(highestProductOf2, std::max(currentNum * highest, currentNum * lowest));
    	lowestProductOf2= std::min(lowestProductOf2, std::min(currentNum * highest, currentNum * lowest));
    	highest= std::max(highest, currentNum);
    	lowest= std::min(lowest, currentNum);
    }

    return highestProductOf3;
}