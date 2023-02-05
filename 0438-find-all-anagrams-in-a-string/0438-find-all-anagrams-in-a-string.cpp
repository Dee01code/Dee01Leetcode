class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        if(s1.size() > s2.size()) return {};
        
        vector<int> v(26,0);
        for(auto i : s1){
            v[i-'a']++;
        }
        
        int winSize = s1.size();
        
        vector<int> ans;
        
        vector<int> window(26,0);
        for(int i = 0; i < winSize; i++){
            window[s2[i]-'a']++;
        }
        if(v == window) ans.push_back(0);
        
        for(int i=1; i <= s2.size()-winSize; i++){
            window[s2[i-1]-'a']--;
            window[s2[i+winSize-1]-'a']++;
            if(v == window) ans.push_back(i);
        }
        return ans;
    }
};