class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        
        vector<vector<int>> v(n,vector<int>(n,0));
        
        for(auto i : q){
            int r1,c1,r2,c2;
            r1 = i[0];
            c1 = i[1];
            r2 = i[2];
            c2 = i[3];
            
            v[r1][c1] += 1;
            if(c2+1<n )v[r1][c2+1] -= 1;
            if(r2+1<n) v[r2+1][c1] -= 1;
            if(r2+1 < n && c2+1 < n) v[r2+1][c2+1] += 1;
        }
        
        for(int r=0; r<n; r++){
            for(int c=1; c<n; c++){
                v[r][c] += v[r][c-1];
            }
        }
        for(int r=1; r<n; r++){
            for(int c=0; c<n; c++){
                v[r][c] += v[r-1][c];
            }
        }
        return v;
    }
};