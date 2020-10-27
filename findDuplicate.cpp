#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

unsigned int findDuplicate(const vector<unsigned int>& intVector)
{
    // find a number that appears more than once ... in O(n) time
    int length = intVector.size(),
        head = intVector[length - 1],
        headPos = length;
        
    int tempPointer = head;
    
    for (int i = 0; i < length; ++i) {
        tempPointer = intVector[tempPointer - 1];
    }
    // now we inside the cycle
    int start = tempPointer,
        cycleLength = 1;
    
    tempPointer = intVector[start - 1];
    while (tempPointer != start) {
        tempPointer = intVector[tempPointer - 1];
        ++cycleLength;
    }
    
    int trackerPointer = head;
    
    for (int i = 0; i < cycleLength; ++i)   {
        trackerPointer = intVector[trackerPointer - 1];
    }
    
    while (head != trackerPointer)   {
        head = intVector[head - 1];
        trackerPointer = intVector[trackerPointer - 1];
    }
    
    return head;
}