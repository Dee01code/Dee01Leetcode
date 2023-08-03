class Solution {
public:
    
    void solve(string digits, int ind, vector<string> mp, vector<string> &ans, string cur){
        
        if(ind >= digits.size()){
            ans.push_back(cur);
            return;
        }
        
        string alp = mp[digits[ind]-'0'];

        for(auto i : alp){
            string newC = cur+i;
            solve(digits, ind+1, mp, ans, newC);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.size()==0) return ans;
        solve(digits,0,mp,ans,"");
        return ans;
    }
};