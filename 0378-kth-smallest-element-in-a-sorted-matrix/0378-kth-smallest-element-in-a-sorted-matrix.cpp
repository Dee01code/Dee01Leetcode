class Solution {
public:
    
    int cnt_equal_less(vector<vector<int>>& m, int mid){
        int row = m.size(), col = m[0].size();
        int r = 0, c = col-1;
        int cnt = 0;
        
        while(r < row && c >= 0){
            
            if(m[r][c] <= mid){
                cnt += c+1;
                r++;
            }
            else c--;
        }
        cout << "Cnt of " << mid << " = " << cnt << endl;
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& m, int k) {
        
        int row = m.size();
        int col = m[0].size();
        int ans;
        
        // MIN HEAP
//         priority_queue<vector<int>, vector<vector<int>>, greater<>> p;
        
//         for(int r = 0; r < min(row,k); r++){
//             p.push({m[r][0], r, 0});
//         }
        
//         for(int i=1; i<k; ++i){
//             auto temp = p.top();
//             p.pop();
            
//             int r = temp[1];
//             int c = temp[2];
        
//             if(c+1 < col) p.push({m[r][c+1], r, c+1}); 
//         }
//         return p.top()[0];
        
        int low = m[0][0];
        int high = m[row-1][col-1];
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            if(cnt_equal_less(m,mid) >= k){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        return ans;
    }
};
