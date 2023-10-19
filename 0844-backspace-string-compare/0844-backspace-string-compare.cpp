class Solution {
public:
    string solve(string s){
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '#'){
                if(ans.size())
                    ans.pop_back();
            } 
            else
                ans.push_back(s[i]);
        }
        cout << ans << endl;
        return ans;
        
    }
    bool backspaceCompare(string s, string t) {
        return solve(s) == solve(t);
    }
};