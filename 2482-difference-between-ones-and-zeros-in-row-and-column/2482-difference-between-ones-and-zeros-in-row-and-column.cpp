class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> onesRow(row,0), zeroRow(row,0);
        vector<int> onesCol(col,0), zeroCol(col,0);
        
        // Will traverse in rows to count 1,0
        
        for(int i = 0; i<row; i++){
            int cnt1 = 0, cnt0 = 0;
            for(int j = 0; j<col; j++){
                if(grid[i][j]) cnt1++;
                else cnt0++;
            }
            onesRow[i] = cnt1;
            zeroRow[i] = cnt0;
        }
        
        for(int i = 0; i<col; i++){
            int cnt1 = 0, cnt0 = 0;
            for(int j = 0; j<row; j++){
                if(grid[j][i]) cnt1++;
                else cnt0++;
            }
            onesCol[i] = cnt1;
            zeroCol[i] = cnt0;
        }
        
        // for(int i = 0; i < row; i++)
        //     cout << "Row " << i+1 << " = " << onesRow[i] << " ones " << zeroRow[i] << " zeroes"<<endl; 
        // for(int i = 0; i < col; i++)
        //     cout << "Col " << i+1 << " = " << onesCol[i] << " ones " << zeroCol[i] << " zeroes"<<endl; 
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                grid[i][j] = onesRow[i]+ onesCol[j] - (zeroRow[i]+ zeroCol[j]);
        return grid;
    }
};