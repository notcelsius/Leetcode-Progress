// Date Completed: 12/3/2024

// Leetcode Problem: https://leetcode.com/problems/roman-to-integer/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues;   // create a map to store roman numerals to value pairs
        // adding pairs in
        romanValues['I'] = 1;
        romanValues['V'] = 5;
        romanValues['X'] = 10;
        romanValues['L'] = 50;
        romanValues['C'] = 100;
        romanValues['D'] = 500;
        romanValues['M'] = 1000;
        int value = 0;  // keeps track of overall value of the roman numeral
        int previousValue = 0;  // keeps track of the value of the previous character
        for (int i = s.length() - 1; i >= 0; i--) { // traverses the string backwards
            char currChar = s[i];   // gets the current character
            // the roman numeral should be ordered in decreasing order, when it is not in decreasing order, you know subtraction needs to occur
            if (previousValue > romanValues[currChar]) {    // if previous value is greater than current value
                value -= romanValues[currChar]; // subtract current value from overall value
            }
            else {  // if previous value is less than current value
                value += romanValues[currChar]; // add current value from overall value
            }
            previousValue = romanValues[currChar];  // set previous value to the current value
        }
        return value;   // returns overall value
    }
};