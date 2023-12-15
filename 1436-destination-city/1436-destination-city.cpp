class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_map<string, int> ans;
        
        for(auto i : paths){
            string x1 = i[0];
            string x2 = i[1];
            ans[x1] = 2;
            if(ans.count(x2) == 0)
                ans[x2]++;
        }
        
        for(auto i : ans){
            if(i.second == 1) return i.first;
        }
        
        return "";
    }
};