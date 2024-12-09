// Date Completed: 12/9/2024

// Leetcode Problem: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // VERY similar to binary search
        // using 2 pointers
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {  // will squeeze numbers vector, but need 2 indexes so won't set left <= right
            if (numbers[left] + numbers[right] == target) { // if left + right = target
                return {left+1,right+1};    // return it
            }
            else if (numbers[left] + numbers[right] > target) { // if left + right > target, then need to decrease value of left + right
                right--;    // since numbers in non decreasing order, can decrement right to decrease value of right
            }
            else if (numbers[left] + numbers[right] < target) { // if left + right < target, then need to increase value of left + right
                left++; // since numbers in non decreasing order, can increment left to increase value of left
            }
        }
        return {};
    }
};