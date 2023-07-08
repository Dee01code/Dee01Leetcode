#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<ll> qmin;
        priority_queue<ll,vector<ll>,greater<ll>> qmax;
        ll smin = nums[0]+nums[n-1], smax = nums[0]+nums[n-1];
        for(int i = 0; i<n-1;++i){
            qmin.push(nums[i]+nums[i+1]); qmax.push(nums[i]+nums[i+1]);
            smin+=nums[i]+nums[i+1],smax+=nums[i]+nums[i+1];
            if(qmin.size()>k-1){
                smin-=qmin.top(); qmin.pop();
            }
            if(qmax.size()>k-1){
                smax-=qmax.top(); qmax.pop();
            }
        }
        return smax-smin;
    }
};