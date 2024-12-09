// Date Completed: 12/8/2024

// Leetcode Problem: https://leetcode.com/problems/two-sum/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> remainderIndex;  // remainder of target - num is key, index of num is value
        for (int i = 0; i < nums.size(); i++) { // goes through each number in num
            if (remainderIndex.contains(nums[i])) { // if num is in the map already, then that means that it was the remainder of target - another num in nums
                return {i, remainderIndex[nums[i]]};    // return {i (index of num), and remainderIndex[nums[i]] (index of remainder)}
            }
            remainderIndex[target-nums[i]] = i; // if num is not in map, then add target - num -> i to the map
            
        }
        return {};

    }
};