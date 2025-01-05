// Date Completed: 1/2/2025

// Leetcode Problem: https://leetcode.com/problems/max-consecutive-ones-iii/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // using sliding window technique
        int maxW = 0;
        int num0 = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) { // go through all of nums
            if (nums[r] == 0) { // if there is a 0
                num0++; // then keep note of it
            }

            while (num0 > k) {  // if there is more 0s than allowed, then move l forward until the number of 0s is good again
                if (nums[l] == 0) {
                    num0--;
                }
                l++;
            }

            maxW = max(maxW, r - l + 1);    // get width of the current window and compare it to maxW
        }
        return maxW;    // return the max consecutive ones
        
    }
};