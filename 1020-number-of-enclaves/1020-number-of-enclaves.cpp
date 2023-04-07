class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &visit){
        
        int Rows = grid.size();
        int Cols = grid[0].size(); 
        
        visit[row][col] = 1;
        int DirRow[] = {-1,0,1,0};
        int DirCol[] = {0,1,0,-1};
        
        for(int i = 0; i<4; i++){
            int nextR = row + DirRow[i];
            int nextC = col + DirCol[i];

            if(nextR >= 0 && nextR<Rows && nextC >= 0 && nextC < Cols && grid[nextR][nextC]==1  && !visit[nextR][nextC] ){
                dfs(nextR, nextC, grid, visit);
            }
        }
        
    }
    
    void boundary(vector<vector<int>>& grid, vector<vector<int>> &visit, int row, int col){
         for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if((r==0 || c==0 || r==row-1 || c==col-1) && grid[r][c] == 1 && !visit[r][c]){
                    dfs(r,c,grid,visit);
                }
            }
        }
        
    }
    
//     int solve(vector<vector<int>>& grid){
        
//         int row = grid.size();
//         int col = grid[0].size();
        
//         vector<vector<int>> visit(row,vector<int>(col,0));
        
//         queue<pair<int,int>> q;
        
//         for(int r=0; r<row; r++){
//             for(int c=0; c<col; c++){
//                 if((r==0 || c==0 || r==row-1 || c==col-1) && grid[r][c]){
//                     q.push({r,c});
//                     visit[r][c] = 1;
//                 }
//             }
//         }

//         int DirRow[] = {-1,0,1,0};
//         int DirCol[] = {0,1,0,-1};
        
//         while(!q.empty()){
//             int r = q.front().first;
//             int c = q.front().second;
            
//             q.pop();
            
//             for(int i = 0; i<4; i++){
//                 int nextR = r + DirRow[i];
//                 int nextC = c + DirCol[i];
                
//                 if(nextR >= 0 && nextR<row && nextC >= 0 && nextC < col && grid[nextR][nextC]  && !visit[nextR][nextC] ){
//                     q.push({nextR,nextC});
//                     visit[nextR][nextC] = 1;
//                 }
//             }
//         }

//         int ans = 0;
//         for(int i = 0; i<row; i++){
//             for(int j = 0; j<col; j++){
//                 if(grid[i][j] && !visit[i][j]) ans++;
//             }
//         }
        
//         return ans;
//     }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> visit(row,vector<int>(col,0));
        boundary(grid, visit, row, col); 
        
        int ans = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] && !visit[i][j]) ans++;
            }
        }
        
        return ans;
    }
};