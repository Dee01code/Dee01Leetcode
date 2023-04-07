class Solution {
public:
    
    void helper(vector<vector<char>>& grid, vector<vector<int>> &visit, int row, int col){
        
        queue<pair<int,int>> q;
        
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if((r==0 || c==0 || r==row-1 || c==col-1) && grid[r][c] == 'O'){
                    q.push({r,c});
                    visit[r][c] = 1;
                }
            }
        }

        int DirRow[] = {-1,0,1,0};
        int DirCol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            for(int i = 0; i<4; i++){
                int nextR = r + DirRow[i];
                int nextC = c + DirCol[i];
                
                if(nextR >= 0 && nextR<row && nextC >= 0 && nextC < col && grid[nextR][nextC]=='O'  && !visit[nextR][nextC] ){
                    q.push({nextR,nextC});
                    visit[nextR][nextC] = 1;
                }
            }
        }
        return;
    }
    
    void solve(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> visit(row,vector<int>(col,0));
        helper(grid, visit, row, col);
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 'O' && !visit[i][j]) grid[i][j] = 'X';
            }
        }
        return;
    }
};