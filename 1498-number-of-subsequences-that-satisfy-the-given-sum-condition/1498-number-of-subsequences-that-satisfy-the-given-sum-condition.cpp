class Solution {
public:
    int mod=1000000007;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0, i = 0, n = nums.size(), j = n-1;
        vector<int>powOf2(n+1, 1);
        for(int i=1; i<=n; i++){
            powOf2[i] = (2*powOf2[i-1]) % mod;
        }
        while(i<=j){
            if(nums[i] + nums[j] <= target){
                cnt = (cnt + powOf2[j-i]) % mod;
                i++;
            }
            else{
                j--;
            }
        }
        return cnt;
    }
};