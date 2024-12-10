// Date Completed: 12/10/2024

// Leetcode Problem: https://leetcode.com/problems/top-k-frequent-elements/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // uses bucket sort
        vector<int> result;
        unordered_map<int,int> count;   // will keep track of frequency of each number in nums
        vector<vector<int>> buckets(nums.size() + 1);   // the index of buckets is the frequency of the number, the contents in buckets[i] is the numbers that have that frequency
                                                        // ex: buckets[10] = {1,2} means 1 and 2 appear 10 times each in nums
        // get frequency of each number
        for (int num : nums) {
            count[num]++;
        }
        // put each number in its respective bucket
        for (auto& pair : count) {
            buckets[pair.second].push_back(pair.first);
        }
        for (int i = buckets.size() - 1; i >= 0; i--) { // start from end of buckets vector because that is where the largest elements are
            for (int num : buckets[i]) {    // go through the ith bucket
                result.push_back(num);  // add 1 number from the ith bucket to result
                if (result.size() == k) {   // check if result has k elements after addition of the element
                    return result;  // if it has k elements, then that means result has the top k elements and return it
                }
            }
        }
        return result;  // return result


    }
};