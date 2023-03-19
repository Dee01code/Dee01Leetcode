class Solution {
public:
    
    bool moveupleft(int r, int c, int n){
        if(c-1 >= 0 && r-2 >=0 ) return 1;
        return 0;
    }
    
    bool moveupright(int r, int c, int n){ 
        if(c+1 <= n-1 && r-2 >=0 ) return 1;
        return 0;
    }
    
    bool movedownleft(int r, int c, int n){
        if(c-1 >= 0 && r+2 <n ) return 1;
        return 0;
    }
    
    bool movedownright(int r, int c, int n){
        if(c+1<n && r+2 < n ) return 1;
        return 0;
    }
    bool moveleftup(int r, int c, int n){
        if(c-2 >= 0 && r-1 >=0 ) return 1;
        return 0; 
    }
    bool moveleftdown(int r, int c, int n){
        if(c-2 >= 0 && r+1<n ) return 1;
        return 0;
    }
    bool moverightup(int r, int c, int n){
        if(c+2 < n && r-1 >=0 ) return 1;
        return 0;
    }
    bool moverightdown(int r, int c, int n){
        if(c+2 < n && r+1 <n ) return 1;
        return 0;
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int greatest = n*n; 
        int curRow = 0, curCol = 0,start=1;
        while(start<greatest){
            cout << "number to find " << start << " and CurRow = " << curRow << " Curcol = " << curCol << endl;
            if(moveupleft(curRow,curCol,n) && grid[curRow-2][curCol-1]==start){
                start++;
                curRow -= 2;
                curCol--;
                continue;
            }
            if(movedownleft(curRow,curCol,n) && grid[curRow+2][curCol-1]==start){
                start++;
                curRow += 2;
                curCol--;
                continue;
            }
            if(moveupright(curRow,curCol,n) && grid[curRow-2][curCol+1]==start){
                start++;
                curRow -= 2;
                curCol++;
                continue;
            }
            if(movedownright(curRow,curCol,n) && grid[curRow+2][curCol+1]==start){
                start++;
                curRow += 2;
                curCol++;
                continue;
            }
            if(moveleftup(curRow,curCol,n) && grid[curRow-1][curCol-2]==start){
                start++;
                curRow--;
                curCol -= 2;
                continue;
            }
            if(moverightup(curRow,curCol,n) && grid[curRow-1][curCol+2]==start){
                start++;
                curRow--;
                curCol += 2;
                continue;
            }
            if(moveleftdown(curRow,curCol,n) && grid[curRow+1][curCol-2]==start){
                start++;
                curRow++;
                curCol -= 2;
                continue;
            }
            if(moverightdown(curRow,curCol,n) && grid[curRow+1][curCol+2]==start){
                start++;
                curRow++;
                curCol += 2;
                continue;
            }
            
            return false;
        }
        return 1;
        
    }
};