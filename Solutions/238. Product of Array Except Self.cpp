// Date Completed: 12/5/2024

// Leetcode Problem: https://leetcode.com/problems/product-of-array-except-self/

// Time Complexity: O(n)
// Space Complexity: O(1) this is excluding the result vector

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // solutions works because the answer is the prefix * suffix
        int n = nums.size();    // gets size of nums
        vector<int> res(n,1);   // initializes result vector with everything having 1

        // first turns res into a prefix vector
        for (int i = 1; i < n; i++) {   // do not need to access i = 0 because it is already 1 and nothing is before it
            res[i] = nums[i - 1] * res[i - 1];  // takes the previous number before i and multiplies it by the previous prefix
                                                // the ith number in res stores the multiplication of all #s in num prior to it
        }

        int suffix = 1; // keeps track of suffix
        for (int i = n - 1; i >= 0; i--) {  // starts at end of res
            res[i] = res[i] * suffix;   // currently res is the prefix, so it should be multiplied by suffix
            suffix = nums[i] * suffix;  // updates the suffix by multiplying it by the number at ith index in nums
        }

        return res;
    }
};