class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        
        unordered_set<int> m(nums.begin(), nums.end());
        
        int ans = 1;
        
        while(m.count(ans)) ans <<= 1;
        return ans;
        
    }
};