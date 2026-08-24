class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> nums = {};
        for(int i = 0; i < board.size(); i++){
            nums.clear();
            for(int j = 0; j < board.size(); j++){
                if(nums.contains(board[i][j])) return false;
                if(board[i][j] == '.') continue;
                nums.insert(board[i][j]);
            }
        }
        cout << "Rows Passed. \n";
        for(int i = 0; i < board.size(); i++){
            nums.clear();
            for(int j = 0; j < board.size(); j++){
                if(nums.contains(board[j][i])) return false;
                if(board[j][i] == '.') continue;
                nums.insert(board[j][i]);
            }
        }
        cout << "Columns Passed. \n";
        for(int i = 0; i < board.size(); i += 3){
            for(int j = 0; j < board.size(); j += 3){
                nums.clear();
                for(int k = 0; k < 3; k++){
                    for(int l = 0l; l < 3; l++){
                        char value = board[i+k][j+l];
                        if(nums.contains(value)) return false;
                        if(value == '.') continue;
                        nums.insert(value);
                    }
                }
            }
        }
        return true;
    }
};
