// Date Completed: 1/2/2025

// Leetcode Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = INT_MAX;  // will be the minimum
        int l = 0;
        int r = nums.size() - 1;
        // using binary search
        while (l <= r) {
            if (nums[l] <= nums[r]) {   // this means the array is sorted, so min will either be the res or the leftmost element
                return min(res, nums[l]);
            }
            int mid = (l + r)/2;    // mid for binary search
            if (nums[mid] >= nums[l]) { // mid is in the left sorted portion, so we want to search the right sorted portion for a better min
                                        // for ex: 3, 4, 5, 1, 2 we see that 5 is greater than 3 so that means we know it is sorted so we look to the right
                l = mid + 1;
            }
            else {                      // mid is in the right sorted portion, so we want to search the left sorted portion for a better min
                r = mid - 1;
            }
            res = min(nums[mid], res);  // update if found better min
        }
        return res; // return min
    }
};