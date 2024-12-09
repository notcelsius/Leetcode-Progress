// Date Completed: 12/9/2024

// Leetcode Problem: https://leetcode.com/problems/reverse-string/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        // uses 2 pointers approach
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) { // squeezing the vector
            char temp = s[left];    // temp variable for swapping
            // swaps the left character and right character
            s[left] = s[right];
            s[right] = temp;
            left++; // moves left up
            right--;    // moves right down
        }
    }
};