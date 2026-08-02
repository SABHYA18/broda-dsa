class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows, cols;
        map<pair<int, int>, unordered_set<int>> squares;

        for(int r = 0; r<9; r++){
            for(int c = 0; c <9; c++){
                int val = board[r][c];
                if(val=='.') continue;
                else if(rows[r].count(val)|| 
                   cols[c].count(val) || 
                   squares[{r/3, c/3}].count(val)) return false;
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[{r/3, c/3}].insert(board[r][c]);
            }
        }
        return true;
    }
};
