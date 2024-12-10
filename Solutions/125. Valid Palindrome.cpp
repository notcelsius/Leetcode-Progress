// Date Completed: 12/9/2024

// Leetcode Problem: https://leetcode.com/problems/valid-palindrome/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        // using 2 pointers approach
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) { // going to squeeze
            // if left is not alphanumeric then move left index left essentially ignoring it
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            // if right is not alphanumeric then move right index right essentially ignoring it
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            // check if the left index and right index chars are the same
            if (tolower(s[left]) != tolower(s[right])) {    // if not the same
                return false;   // then not a palindrome
            }
            if (tolower(s[left]) == tolower(s[right])) {    // if are the same
                // then check next left and next right
                left++;
                right--;
            }
        }
        return true;    // all characters matched up accordingly so s is a palindrome
    }
};