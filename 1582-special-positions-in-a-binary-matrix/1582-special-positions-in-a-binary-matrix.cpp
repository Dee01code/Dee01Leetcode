class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int ans = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j]){
                    int colCnt = 0;
                    for(int r = 0; r < row; r++){
                        if(mat[r][j] && r != i) colCnt++;         
                    }
                    
                    int rowCnt = 0;
                    for(int c = 0; c < col; c++){
                        if(mat[i][c] && c != j) rowCnt++;
                    }
                    if(colCnt == 0 && rowCnt == 0) ans++;
                }
            }
        }
        return ans;
    }
};