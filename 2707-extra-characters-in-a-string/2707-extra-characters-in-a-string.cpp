class Solution {
public:
    
    unordered_set<string> dict;
    int dp[51];
    int solve(int ind, string s){
        if(ind >= s.length()) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int minExtra = INT_MAX;
        string curWord = "";
        for(int i = ind; i<s.length(); i++){
            curWord.push_back(s[i]);
            int extra = (dict.find(curWord) == dict.end()) ? curWord.length() : 0;
            extra += solve(i+1,s);
            minExtra = min(extra,minExtra);
        }
        return dp[ind] = minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto i : dictionary) dict.insert(i);
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};