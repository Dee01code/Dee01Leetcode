class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int j = -1;
        for(int i = 0; i<s.size();){
            if(s[i] == s[i+1]){
                i+=2;    
            }
            else{
                if(j>=0 && s[i] == ans[j]){
                    // ans = ans.substr(0,j);
                    j--;
                    i++;
                }
                else{
                    if(ans.size() == j+1){
                        ans += s[i++];
                    }
                    else{
                        ans[j+1] = s[i++];
                    }
                    j++;
                }
            }
        }
        return ans.substr(0,j+1);
    }
};