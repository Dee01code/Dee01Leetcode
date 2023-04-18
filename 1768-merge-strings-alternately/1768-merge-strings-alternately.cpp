class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string ans = "";
        int n = w1.size();
        int m = w2.size();
        int i=0,j=0;
        while(i<n && j<m){
            ans.push_back(w1[i++]);
            ans.push_back(w2[j++]);
        }
        while(i<n){
            ans.push_back(w1[i++]);
        }
        while(j<m){
            ans.push_back(w2[j++]);
        }
        return ans;
    }
};