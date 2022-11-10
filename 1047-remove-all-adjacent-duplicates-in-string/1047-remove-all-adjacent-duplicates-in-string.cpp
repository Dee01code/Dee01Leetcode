class Solution
{
    void solve(string &ans, stack<char> &s){
        if(s.empty()) return;
        char temp = s.top();
        s.pop();
        solve(ans, s);
        ans += temp;
    }
    public:
        string removeDuplicates(string s){
            int n = s.size();
            stack<char> ans;
            for(int i = 0; i<n;){
                if(s[i] == s[i+1]){
                    i+=2;
                }
                else{
                    if(ans.empty()){
                        ans.push(s[i]);
                    }
                    else{
                        char temp = ans.top();
                        if(temp == s[i]){
                            ans.pop();
                        }
                        else{
                            ans.push(s[i]);
                        }
                    }
                    i++;
                }
            }
            string s2 = "";
            solve(s2, ans);
            return s2;
        }
};