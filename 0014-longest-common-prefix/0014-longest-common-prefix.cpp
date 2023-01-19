class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string ans= "";
        for(int i = 0; i < strs[0].size();  i++){
            char ch = strs[0][i];
            for(int j = 1; j<n; j++){
                char t = strs[j][i];
                if(ch != t) return ans; 
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};