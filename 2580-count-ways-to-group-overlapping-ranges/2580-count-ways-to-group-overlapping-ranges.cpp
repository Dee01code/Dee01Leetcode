class Solution {
public:
    
    const int MOD = 1e9 + 7;
    
    int powerOfTwo(int n) {
        int ans = 1;
        int base = 2;
        while(n) {
            if(n&1) ans = (1LL * ans * base) % MOD;
            base = (1LL * base * base) % MOD;
            n >>= 1;
        }
        return ans;
    }

    
    int countWays(vector<vector<int>>& intervals) {
        
        //merge intervals code
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]>=intervals[i][0]) ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            else ans.push_back(intervals[i]);
        }
        
        // total distinct ranges
        
        int n = ans.size();
        
        return powerOfTwo(n);
        
    }
};