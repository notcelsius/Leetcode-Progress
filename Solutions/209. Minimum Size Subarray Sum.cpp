// Date Completed: 1/4/2025

// Leetcode Problem: https://leetcode.com/problems/minimum-size-subarray-sum/description/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int sum = 0;
        int shortest = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r]; // add r to sum

            if (sum >= target) {    // if the sum has met the target
                while (sum - nums[l] >= target) {   // reduce the window as much as you can while the window is still valid
                    sum -= nums[l];
                    l++;
                }
                shortest = min(shortest, r - l + 1);    // check the reduced window and compare it with the current shortest window
            }
        }

        if (shortest == INT_MAX) {  // means that target was never reached
            return 0;   // return 0
        }
        else {
            return shortest;    // return shortest window length
        }
    }
};