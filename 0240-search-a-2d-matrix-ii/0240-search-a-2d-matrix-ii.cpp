class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int x) {
        int row = m.size();
        int col = m[0].size();
        int r=0,c=col-1;
        while(r<row && c>=0){
            if(m[r][c] == x) return true;
            else if(m[r][c] > x) c--;
            else r++;
        }
        return false;
    }
};