class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        
        unordered_map<int,vector<int>> mp;
        
        vector<int> ans;
        
        for(auto &i : ap) mp[i[0]].push_back(i[1]), mp[i[1]].push_back(i[0]);
        
        int st = 0;
        for(auto &i : mp){
            if(i.second.size()==1) {
                
                st = i.first;
                break;
            }
        } 
        
        int prev = 0;
        
        ans.push_back(st);
        prev = st;
        st = mp[st][0];
        
        while(mp[st].size() != 1){
            ans.push_back(st);
            int tot = mp[st][0] + mp[st][1];
            int next = tot-prev;
            prev = st;
            st = next;
        }
        
        ans.push_back(st);
        return ans;
    }
};