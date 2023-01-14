class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        
        int row = grid.size();
        int col = grid[0].size();
        
        int ans= 0;
        
        vector<int> colSum;
        
        for(int c=0; c<col; c++){
            int sum = 0;
            for(int r = 0; r<row; r++){
                sum += grid[r][c];
            }
            colSum.push_back(sum);
        }
        
        for(auto i : colSum){
            cout << i << " ";
        }
        
        for(int r = 0; r<row; r++){
            int sum = accumulate(grid[r].begin(),grid[r].end(),0);
            for(int c=0; c<col; c++){
                if(grid[r][c] && (sum > 1 || colSum[c] > 1)) ans += 1;
            }
        }
        return ans;
    
        
    }
};