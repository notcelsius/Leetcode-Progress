// Date Completed: 12/7/2024

// Leetcode Problem: https://leetcode.com/problems/contains-duplicates/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique;  // use an unordered set to keep track of seen numbers
        for (int num: nums) {    // go through each number in nums
            if (unique.contains(num)) { // if it has been seen before
                return true;    // then contains duplicate
            }
            else {  // has not been seen before
                unique.insert(num); // then insert it into the set
            }
        }
        return false;   // if goes through all numbers in num and all of them unique, then does not contain duplicates
    }
};