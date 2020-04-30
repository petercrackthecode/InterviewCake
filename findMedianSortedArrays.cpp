// link: https://leetcode.com/problems/median-of-two-sorted-arrays/
bool isEven(const int &num) {
        return num % 2 == 0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizeSum{static_cast<int>(nums1.size() + nums2.size())},
            midIndexTracker= sizeSum / 2;
        
        bool isEvenSize{ isEven(sizeSum) };
        
        int nums1Index{0},
            nums2Index{0};
        
        if (isEvenSize) {
            double firstMid, secondMid;
            
            while (midIndexTracker >= 0) {
                if (nums1Index < static_cast<int>(nums1.size()) && nums2Index < static_cast<int>(nums2.size())) {
                    if (nums1[nums1Index] <= nums2[nums2Index]) {
                        if ( isEven(nums1Index + nums2Index) ) {
                            firstMid= nums1[nums1Index];
                        }
                        else {
                            secondMid= nums1[nums1Index];
                        }

                        ++nums1Index;
                    }
                    else {
                        if ( isEven(nums1Index + nums2Index) ) {
                            firstMid= nums2[nums2Index];
                        }
                        else {
                            secondMid= nums2[nums2Index];
                        }

                        ++nums2Index;
                    }
                }
                else if (nums1Index == nums1.size()) {
                    if ( isEven(nums1Index + nums2Index) ) {
                        firstMid= nums2[nums2Index];
                    }
                    else {
                        secondMid= nums2[nums2Index];
                    }
                    
                    ++nums2Index;
                }
                else {
                    if ( isEven(nums1Index + nums2Index) ) {
                        firstMid= nums1[nums1Index];
                    }
                    else {
                        secondMid= nums1[nums1Index];
                    }
                    
                    ++nums1Index;
                }
                
                
                --midIndexTracker;
            }
            
            return (firstMid + secondMid) / 2;
        }
        else {
            double median;
            
            while (midIndexTracker >= 0) {
                if (nums1Index < static_cast<int>(nums1.size()) && nums2Index < static_cast<int>(nums2.size())) {
                    if (nums1[nums1Index] <= nums2[nums2Index]) {
                        median= nums1[nums1Index];
                        ++nums1Index;
                    }
                    else {
                        median= nums2[nums2Index];
                        ++nums2Index;
                    }
                }
                else if (nums1Index == nums1.size()) {
                    median= nums2[nums2Index];
                    
                    ++nums2Index;
                }
                else {
                    median= nums1[nums1Index];
                    
                    ++nums1Index;
                }
                
                --midIndexTracker;
            }
            
            return median;
        }
    }