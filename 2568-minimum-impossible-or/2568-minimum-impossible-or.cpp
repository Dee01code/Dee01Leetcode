class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        
        unordered_map<int,int> m;
        for(auto i : nums) m[i]++;
        
        int ans = 1;
        
        while(m.find(ans) != m.end()) ans <<= 1;
        return ans;
        
    }
};