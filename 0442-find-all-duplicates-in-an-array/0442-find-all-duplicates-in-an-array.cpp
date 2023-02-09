class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        unordered_map<int,int> m;
        for(auto i : nums){
            m[i]++;
        }
        
        vector<int> ans;
        for(auto i : m){
            if(i.second > 1) ans.push_back(i.first);
        }
        
        return ans;
        
        
    }
};