class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target >= matrix[m][0] && target <= matrix[m][matrix[m].size() - 1]) {
                int l2 = 0;
                int r2 = matrix[m].size() - 1;
                while (l2 <= r2) {
                    int m2 = l2 + (r2 - l2) / 2;
                    if (target == matrix[m][m2])
                        return true;
                    else if (target > matrix[m][m2])
                        l2 = m2 + 1;
                    else
                        r2 = m2 - 1;
                }
                return false;
            } else if (target > matrix[m][matrix[m].size() - 1])
                l = m + 1;
            else
                r = m - 1;
        }

        return false;
    }
};
