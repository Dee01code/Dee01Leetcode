class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> rem(k,0);
        rem[0] = 1;
        int ans = 0;
        int sum = 0;
        for(auto i : nums){
            sum += i;
            
            int mod = sum%k;
            if(mod<0)   mod += k;
            
            ans += rem[mod];
            rem[mod]++;
        }
        return ans;
    }
};