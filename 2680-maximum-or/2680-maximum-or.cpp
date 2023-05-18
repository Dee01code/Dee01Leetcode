class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<long long> pre(n+1,0),suf(n+1,0);
        
        int mul = pow(2,k);
        pre[0] = 0;
        suf[n] = 0;
        for(int i = 0; i<n; i++){
            pre[i+1] = pre[i] | nums[i];
        }
        
        for(int i = n-1; i>=0; i--){
            suf[i] = suf[i+1] | nums[i]; 
        }
        
        long long ans = 0;
        
        for(int i = 0; i<n; i++){
            long long cal;
            cal = nums[i];
            cal *= mul;
         
            ans = max(ans,pre[i] | suf[i+1] | cal);
        }
        return ans;
        
    }
};