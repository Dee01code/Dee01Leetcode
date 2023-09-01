class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        int ans = -1;
        
        
        
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1) fresh++;
                if(grid[r][c] == 2) q.push({r,c});
            }
        }
        
        int dr[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curR = q.front().first;
                int curC = q.front().second;
                
                q.pop();
                
                for(int i = 0; i<4; i++){
                    int newR = curR + dr[i][0];
                    int newC = curC + dr[i][1];
                    
                    if(newR >= 0 && newR < row && newC >= 0 && newC < col && grid[newR][newC] == 1){
                        grid[newR][newC] = 2;
                        fresh--;
                        q.push({newR,newC});
                    }
                    
                }
            }
            ans++;
        }
        
        if(fresh > 0) return -1;
        if(ans == -1) return 0;
        return ans;
        
    }
};


