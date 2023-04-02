class Solution {
public:
    
    void solve(vector<vector<int>>& image, int r, int c, int color, int stcolor, int cnt){
        int row = image.size();
        int col = image[0].size();
        
        if(r < 0 || c >= col || cnt > row*col){
            return;
        }
        image[r][c] = color;
        cout << " hi";
        if(r-1 >= 0 && image[r-1][c] == stcolor){
            // image[r-1][c] = color;
            solve(image, r-1, c, color,stcolor, cnt+1);
        }
        if(r+1 < row && image[r+1][c] == stcolor){
            // image[r+1][c] = color;
            solve(image, r+1, c, color,stcolor, cnt+1);
        }
        if(c+1 < col && image[r][c+1] == stcolor){
            // image[r][c+1] = color;
            solve(image, r, c+1, color,stcolor, cnt+1);
        }
        if(c-1 >= 0 && image[r][c-1] == stcolor){
            // image[r][c-1] = color;
            solve(image, r, c-1, color,stcolor, cnt+1);
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int stcolor = image[sr][sc];
        solve(image,sr,sc,color, stcolor, 1);
        return image;
    }
};