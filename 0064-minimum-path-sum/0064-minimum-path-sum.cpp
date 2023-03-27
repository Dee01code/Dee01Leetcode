class Solution {
public:
    
//     void solve(vector<vector<int>>& grid, int r, int c,int sum, int &res){
//         int row = grid.size();
//         int col = grid[0].size();
        
//         if(r == row-1 && c == col-1){
//             res = min(res,sum);
//             return;
//         }
//         else{
//             if(r < row) solve(grid, r+1, c, sum+grid[r+1][c], res);
//             if(c < col) solve(grid, r, c+1, sum+grid[r][c+1], res);
//         }
        
//         return;
        
//     }
    
//     int minPathSum(vector<vector<int>>& grid) {
//         int res = INT_MAX;
//         solve(grid,0,0,0,res);
//         return res;
//     }
 int calculate(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(row == 0 && col == 0) 
        return grid[0][0];
    if(row < 0 || col < 0)
        return INT_MAX;
    if(dp[row][col] != -1)
        return dp[row][col];
    
    int left = calculate(row, col - 1, grid, dp);
    int up = calculate(row - 1, col, grid, dp);
    return dp[row][col] = min(left, up) + grid[row][col];
}

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int> (col, -1));
    return calculate(row - 1, col - 1, grid, dp);
}
};