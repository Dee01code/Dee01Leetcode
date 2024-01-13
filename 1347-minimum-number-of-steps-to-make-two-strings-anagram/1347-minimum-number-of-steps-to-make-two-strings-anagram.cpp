class Solution {
public:
    int minSteps(string s, string t) {
        
        unordered_map<char, int> mps,mpt;
        
        for(int i = 0; i < s.size(); i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        
        int ans = 0;
        
        for(auto i : mps){
            char key = i.first;
            int val = i.second;
            if(mpt.find(key) != mpt.end()){
                mpt[key] -= min(mpt[key],mps[key]);
            }
        }
        
        for(auto i : mpt) ans += i.second;
        
        return ans;
    }
};