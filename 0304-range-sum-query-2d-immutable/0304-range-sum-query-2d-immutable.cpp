class NumMatrix {
public:
    
    vector<vector<int>> v;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        v.resize(row+1,vector<int>(col+1,0));
        for(int r=1; r<=row; r++){
            for(int c=1; c<=col; c++){
                v[r][c] = v[r-1][c] + v[r][c-1] + matrix[r-1][c-1] - v[r-1][c-1];
                // cout << v[r][c] << " ";
            }
            // cout << endl;
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        
        return v[r2+1][c2+1] - v[r2+1][c1] - v[r1][c2+1] + v[r1][c1];
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */





