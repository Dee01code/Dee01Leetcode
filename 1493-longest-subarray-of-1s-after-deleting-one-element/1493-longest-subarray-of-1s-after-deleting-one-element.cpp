class Solution
{
    public:
        int longestSubarray(vector<int> &nums)
        {
            int i = 0;
            int j = 0;
            int cnt = 0;
            int n = nums.size();
            int ind0 = -1;
            int ans = INT_MIN;
            
            while(j < n){                
                if(nums[j] == 0){
                    cnt++;
                    if(cnt == 1) ind0 = j;
                }
                if(cnt == 2){
                    int len = j-i-1;
                    i = ind0+1;
                    ind0 = j;
                    cnt = 1;
                    ans = max(ans,len);
                    cout << " I am at ind = " << j  << " ans = " << ans << endl;
                }
                j++;
            }
            
            int len = j-i-1;
            ans = max(ans,len);
            // if(cnt == 1){
            //     int len = j-i-1;
            //     ans = max(ans,len);
            // }
            // if(cnt == 0){
            //     int len = j-i;
            // }
            return ans;
        
        }
};