class Solution {
public:
    
    
    
    void dfs(vector<vector<int>>& grid, int r, int c, int row, int col, int &cnt){
        cout << "(" << r << "," <<c<<")"<<endl;
        if(r < 0 || r>=row || c<0 || c>=col || grid[r][c] == 0) return;
        
        cnt += grid[r][c];
        grid[r][c] = 0; 
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for(int i = 0; i<4; i++){
            int newR = r+dx[i];
            int newC = c+dy[i];
            dfs(grid, newR, newC, row, col, cnt);
        }
    }
    
//     void bfs(vector<vector<int>>& grid, int r, int c, int row, int col, int &cnt, vector<vector<bool>> &visited){
        
//         queue<pair<int,int>> q;
        
//         q.push({r,c});
        
//         while(!q.empty()){
            
//             int R = q.front().first;
//             int C = q.front().second;
//             q.pop();
//             visited[R][C] = 1;
//             cnt += grid[R][C];
            
//             for(int i = 0; i<4; i++){
                
//                 int dx[] = {-1, 1, 0, 0};
//                 int dy[] = {0, 0, -1, 1};
                
//                 int newR = R+dx[i];
//                 int newC = C+dy[i];
                
//                 if(newR >= 0 && newR < row && newC >= 0 && newC < col && !visited[newR][newC] && grid[newR][newC] > 0) q.push({newR,newC});
//             }
            
//         }
//         return;
//     }
    
    int findMaxFish(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        int ans = 0;
        // vector<vector<bool>> visited(row,vector<bool>(col,0));
        
        for(int r = 0; r<row; r++){
            for(int c = 0; c<col; c++){
                if(grid[r][c]>0){
                    
                    int temp = 0;
                    dfs(grid,r,c,row,col,temp);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};