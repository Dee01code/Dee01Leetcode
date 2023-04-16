class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col = mat[0].size();
        
        pair<int,int> p = {INT_MIN,INT_MAX};
        for(int r = 0; r<row; r++){
            int cnt = 0;
            for(int c=0; c<col; c++){
                if(mat[r][c]) cnt++;
            }
            if(p.first < cnt){
                p = {cnt,r};
            }
        }
        return {p.second,p.first};
        
    }
};