// link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#include <stdexcept>
#include <cmath>
#include <limits.h>

typedef std::vector<int> vi;

class Solution {
public:
    int calculate(vi nums, int numsSize, int divisor) {
        int sum = 0;
        for (int i=0; i<numsSize; i++) {
            sum += ceil(nums[i]*1.0/divisor);
        }
        return sum;
    }

    int smallestDivisor(std::vector<int> &nums, int threshold){
        int numsSize = nums.size();
        int lo = 1, hi = nums[numsSize-1];

        // Binary search to reduce time complexity
        while (lo <= hi) {
            int mid = (lo + hi)/2;
            int curr = calculate(nums, numsSize, mid);

            if (curr > threshold) 
                lo = mid+1;
            else
                hi = mid-1;
        }

        return lo;
    }
};