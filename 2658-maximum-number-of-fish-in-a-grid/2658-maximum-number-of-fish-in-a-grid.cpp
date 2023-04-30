class Solution {
public:
    
    
    
    void dfs(vector<vector<int>>& grid, int r, int c, int row, int col, int &cnt, vector<vector<bool>> &visited){
        cout << "(" << r << "," <<c<<")"<<endl;
        if(r < 0 || r>=row || c<0 || c>=col || visited[r][c] || grid[r][c] == 0) return;
        
        cnt += grid[r][c];
        visited[r][c] = 1;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for(int i = 0; i<4; i++){
            int newR = r+dx[i];
            int newC = c+dy[i];
            dfs(grid, newR, newC, row, col, cnt, visited);
        }
        return;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        int ans = 0;
        vector<vector<bool>> visited(row,vector<bool>(col,0));
        
        for(int r = 0; r<row; r++){
            for(int c = 0; c<col; c++){
                if(grid[r][c]>0 && !visited[r][c]){
                    
                    int temp = 0;
                    dfs(grid,r,c,row,col,temp,visited);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};