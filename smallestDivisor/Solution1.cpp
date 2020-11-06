// link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#include <stdexcept>
#include <cmath>
#include <limits.h>

typedef std::vector<int> vi;

class Solution {
public:
    auto sumOfAllDivision(const vi &nums, int divisor) -> long {
        long sum{0};
        
        if (divisor == 0)
            throw new std::invalid_argument("\nThe divisor cannot be zero\n");
        
        for (auto num : nums)   {
            sum += std::ceil(num/(divisor * 1.0));
        }
        
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = INT_MAX,
            currentSumOfAllDivision = 0;
        
        int low = 1, 
            high = nums[nums.size() - 1],
            mid;

        while (low <= high) {
            mid = low + (high - low)/2;
            currentSumOfAllDivision = sumOfAllDivision(nums, mid);

            if (currentSumOfAllDivision <= threshold && mid < ans) {
                ans = mid;
                high = mid - 1;
            }
            else { // currentSumOfAllDivision > threshold
                low = mid + 1;
            }
        }

        return ans;
    }
};