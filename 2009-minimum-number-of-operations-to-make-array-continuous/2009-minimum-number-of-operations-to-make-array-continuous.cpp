class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i] = INT_MAX;
            }
        }
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int maxm = nums[i] + nums.size()-1;
            int it  = upper_bound(nums.begin()+i, nums.end(), maxm) - nums.begin();
            it = n-it+i;
            ans = min(ans, it);
        }

        return ans;
        
    }
};