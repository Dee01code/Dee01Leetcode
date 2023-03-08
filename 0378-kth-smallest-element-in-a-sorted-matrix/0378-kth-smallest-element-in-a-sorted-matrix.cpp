class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int row = m.size();
        int col = m[0].size();
        int ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> p;
        
        for(int r = 0; r < min(row,k); r++){
            p.push({m[r][0], r, 0});
        }
        
        for(int i=1; i<k; ++i){
            auto temp = p.top();
            p.pop();
            
            int r = temp[1];
            int c = temp[2];
        
            if(c+1 < col) p.push({m[r][c+1], r, c+1}); 
        }
        return p.top()[0];
    }
};
