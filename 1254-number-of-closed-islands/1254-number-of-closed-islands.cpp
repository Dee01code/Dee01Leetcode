class Solution {
public:
void bfs(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
   
        
    int delr[]={-1,0,1,0};
    int delc[]={0,-1,0,1};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
     for(int i=0;i<4;i++){
        int r=row+delr[i];
        int c=col+delc[i];
        if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]==0){
            q.push({r,c});
            vis[r][c]=1;
        }
     }
    }

}
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(!vis[i][j] && grid[i][j]==0){
                   bfs(i,j,vis,grid);
                }
            }
            
           } 
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;

    }
};