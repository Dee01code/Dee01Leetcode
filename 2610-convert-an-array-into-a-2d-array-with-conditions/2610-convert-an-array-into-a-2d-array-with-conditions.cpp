class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        map<int,vector<int>> m;
        int rows = INT_MIN;
        for(auto i : nums){
            m[i].push_back(0); 
            int size = m[i].size();
            rows = max(rows,size);
        }
        
        vector<vector<int>> ans(rows);
        for(auto i : m){
            vector<int> temp = i.second;
            for(int j = 0; j<temp.size(); j++){
                ans[j].push_back(i.first);
            }
        }
        return ans;
    }
};