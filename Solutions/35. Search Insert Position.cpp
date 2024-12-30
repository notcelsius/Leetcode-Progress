// Date Completed: 12/29/2024

// Leetcode Problem: https://leetcode.com/problems/binary-search/description/

// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (target < nums[(l+r)/2]) {
            return (l + r)/2;
        }
        else {
            return (l + r)/2 + 1;
        }
    }
};