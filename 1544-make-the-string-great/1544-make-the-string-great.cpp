class Solution {
public:
    string makeGood(string s) {
        string ans;
        int j = -1;
        for(int i = 0; i<s.length();){
            if(abs(s[i]-s[i+1])!=32){
                if(ans.size()>0 ){
                    if(abs(ans[j]-s[i]) != 32){ 
                        ans += s[i];
                        j++;
                    }
                    else{
                        ans = ans.substr(0,j);
                        j--;
                    }
                }
                else if(ans.size()==0){
                    ans += s[i];
                    j++;
                }
                i++;
            }
            else i += 2;
        }
        return ans;
    }
};