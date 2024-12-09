// Date Completed: 12/8/2024

// Leetcode Problem: https://leetcode.com/problems/valid-sudoku/

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;   // keeps track of the rows and the values in each row
        unordered_map<int, unordered_set<char>> cols;   // keeps track of the cols and the values in each col
        map<pair<int,int>, unordered_set<char>> squares;    // keeps track of the squares and the values in each square
                                                            // maps take O(logn) for insertion and O(logn) for finding keys
        for (int r = 0; r < 9; r++) {   // go through each row
            for (int c = 0; c < 9; c++) {   // go through each col
                if (board[r][c] == '.') {   // if it is '.', then we do not care and can move on
                    continue;
                }
                pair<int,int> squareKey = {r/3,c/3};    // determines which square board[r][c] is in
                // checks if the row already has the number
                if (rows[r].contains(board[r][c])) {
                    return false;
                }
                // checks if the col already has the number
                if (cols[c].contains(board[r][c])) {
                    return false;
                }
                // checks if the square already has the number
                if (squares[squareKey].contains(board[r][c])) {
                    return false;
                }
                rows[r].insert(board[r][c]);    // inserts the number into the row
                cols[c].insert(board[r][c]);    // inserts the number into the col
                squares[squareKey].insert(board[r][c]); // inserts the number into the square
            }
        }
        return true;    // returns true if all rows, cols, and squares passed the conditions
    }
};