// Date Completed: 12/5/2024

// Leetcode Problem: https://leetcode.com/problems/summary-ranges/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ranges;  // stores ranges
        int i = 0;  // will be the index used to traverse the array

        while (i  < nums.size()) {  // while the index is within nums
            int start = nums[i];    // start of the range
            // this will find the end of the range
            // nums[i] + 1 == nums[i+1] checks if the next number after i is consecutive
            while (i < nums.size() - 1 && nums[i] + 1 == nums[i+1]) {
                i++;
            }

            if (start != nums[i]) { // if the next number after i was not consecutive
                ranges.push_back(to_string(start) + "->" + to_string(nums[i])); // range is from start to i
            }

            else {  // if i reached the end of nums or there was only 1 number in the range
                ranges.push_back(to_string(nums[i]));
            }

            i++;    // goes forward in nums and will be the new start
        }
        return ranges;
    }
};