class Solution {
public:
    string convert(string s, int n) {
        
        string ans = "";
        int size = s.size();
        
        if(n == 1) return s;
        
        int i = 0;
        while(i<n && i<size){
            ans.push_back(s[i]);
            int ft = (n-1-i)*2;
            int sd = (i-0)*2;
            int j = i;
            while(j<size){
                if(ft>0){
                    if(j+ft >= size) break;
                    j+=ft;
                    ans.push_back(s[j]);
                }
                if(sd>0){
                    if(j+sd >= size) break;
                    j+=sd;
                    ans.push_back(s[j]);
                }
            }
            i++;
        }
        return ans;
        
    }
};