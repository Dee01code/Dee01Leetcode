class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans(col, vector<int>(row,0));
        for(int r = 0; r<row; r++){
            for(int c = 0; c < col; c++) ans[c][r]=(mat[r][c]);
        }
        return ans;
    }
};