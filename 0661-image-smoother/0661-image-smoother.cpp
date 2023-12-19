class Solution {
public:

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int dx[10] = {-1,1,-1,0,1,1,0,0,-1,-1};
                    
        
        int row = img.size();
        int col = img[0].size();
        vector<vector<int>> ans(row, vector<int>(col,0));
        
        for(int r = 0; r<row; r++){
            for(int c = 0; c<col; c++){
                int cnt = 0;
                int sum = 0;
                
                for(int i = 0; i<9; i++){
                    int newR = r+dx[i];
                    int newC = c+dx[i+1];
                    
                    if(newR >= 0 && newR < row && newC >= 0 && newC < col){
                        sum += img[newR][newC];
                        cnt++;
                    }
                }
                ans[r][c] = floor(sum/cnt);
                
            }
        }
        return ans;
    }
};