// Date Completed: 1/2/2025

// Leetcode Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r)/2;
            if (nums[mid] == target) {  // target is at m
                return mid;
            }
            if (nums[mid] >= nums[l]) { // mid is in left sorted portion
                if (target >= nums[l] && target <= nums[mid]) { // target is between [l,m)
                    r = mid - 1;
                }
                else {      // target is between (m,r]
                    l = mid + 1;
                }
            }
            else {  // mid is in right sorted portion
                if (target <= nums[r] && target >= nums[mid]) { // target is between (m,r]
                    l = mid + 1;
                }
                else {      // target is between [l,m)
                    r = mid - 1;
                }
            }

        }
        return -1;
    }
};