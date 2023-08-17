class Solution {
public:

    bool out(int r, int c, int row, int col){
        if(r<0 || c<0 || r>=row || c>=col) return 1;
        return 0;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> ans(row,vector<int>(col,0));
        
        vector<vector<int>> vis = ans;
        
        queue<vector<int>> q;
        
        for(int r = 0; r<row; r++){
            for(int c= 0; c<col; c++){
                if(mat[r][c] == 0){
                    q.push({r,c,0});
                    vis[r][c] = 1;
                }
            }
        }
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty()){
            
            int r = q.front()[0];
            int c = q.front()[1];
            int d = q.front()[2];
            q.pop();
            
            for(int i = 0; i<4; i++){
                int newR = r+dx[i];
                int newC = c+dy[i];
                if(!out(newR,newC,row,col) && !vis[newR][newC]){
                    q.push({newR,newC,d+1});
                    ans[newR][newC] = d+1;
                    vis[newR][newC] = 1;
                }
            }
            
        }
        
        return ans;
    }
};