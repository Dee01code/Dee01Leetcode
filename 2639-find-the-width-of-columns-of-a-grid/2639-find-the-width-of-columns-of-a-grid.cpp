class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int col = grid[0].size();
        int row = grid.size();
        vector<int> ans(col);
        
        for(int c = 0; c<col; c++){
            int maxi = INT_MIN;
            for(int r = 0; r<row; r++){
                string temp = to_string(grid[r][c]);
                int len = temp.size();
                maxi = max(maxi,len);
            }
            ans[c] = maxi;
        }
        return ans;
        
    }
};