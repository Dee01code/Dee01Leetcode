class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size(); 
        vector<long long> premax(n);
        for(int i = 0; i<n; i++){
            premax[i] = nums[i];
        }
        long long temp = INT_MIN;
        
        for(int i = 0; i<n; i++){
            temp = (temp < nums[i]) ? nums[i] : temp;
            premax[i] += temp;
        }
        
        for(int i = 1; i < n ; i++){
            premax[i] += premax[i-1];
        }
        return premax;
    }
};