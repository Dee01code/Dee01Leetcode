class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<unordered_map<long, int>> mp(n);
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                auto diff = (long)nums[i]-nums[j];
                auto it = mp[j].find(diff);
                
                int countATj = it==end(mp[j]) ? 0 : it->second;
                
                mp[i][diff] += countATj+1;
                result      += countATj;
                
            }
        }
        return result;
    }
};