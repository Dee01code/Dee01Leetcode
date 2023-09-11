class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<gs.size(); i++) mp[gs[i]].push_back(i);
        
        vector<vector<int>> ans;
        
        for(auto i : mp){
            
            int grpSize = i.first;
            int memberNo = i.second.size();
            int noOfgrp = memberNo/grpSize;
            
            int ind = 0;
            vector<int> temp;
            while(noOfgrp--){
                int cnt = 0;
                while(++cnt <= grpSize){
                    temp.push_back(i.second[ind++]);
                }
                ans.push_back(temp);
                temp.clear();
            }
            
        }
        return ans;
    }
};