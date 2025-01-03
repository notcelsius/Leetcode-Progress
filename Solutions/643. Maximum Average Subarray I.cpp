// Date Completed: 1/2/2025

// Leetcode Problem: https://leetcode.com/problems/maximum-average-subarray-i/description/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // using sliding window technique
        double sum = 0;
        int l = 0;
        int r = 0;
        // set the initial window
        while (r < k) {
            sum += nums[r];
            r++;
        }
        // set the initial max average
        double maxAverage = sum/k;
        // check all other windows of k size for the rest of nums
        while (r < nums.size()) {
            sum -= nums[l];
            l++;
            sum += nums[r];
            // see if those windows have a bigger average
            maxAverage = max(maxAverage, sum/k);
            r++;
        }
        // return the maxAvg
        return maxAverage;
        
    }
};