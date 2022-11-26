class Solution {
public:
    int BinSearch(vector<vector<int>>& job, int i){
         int lo = 0;
         int hi = i - 1;
         int ans = -1;
         while(lo <= hi){
             int mid = lo + (hi - lo) / 2;
             if(job[mid][0] <= job[i][1]){
                    ans = mid;
                    lo = mid + 1;
             }
             else hi = mid - 1;
         }
        return ans;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> job;
        int n = profit.size();
        
        for(int i=0; i<n; i++){
             job.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        sort(job.begin(), job.end());
        
        
        vector<int> dp(n, 0);
        dp[0] = job[0][2];
        int ans = job[0][2];
        
        for(int i=1; i<n; i++){
                 dp[i] = job[i][2];
                 int ed = BinSearch(job, i);
                 if(ed != -1) dp[i] += dp[ed];
                 dp[i] = max(dp[i], dp[i-1]);
                 ans = max(ans, dp[i]);
        }
        
        return ans;        
    }
};