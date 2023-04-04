class Solution {
public:
    int partitionString(string s) {
        
        vector<int> v(26,0);
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            v[s[i]-'a']++;
            if(count(v.begin(),v.end(),2)){
                fill(v.begin(),v.end(),0);
                ans++;
                v[s[i]-'a']++;
            } 
        }    
        return ans+1;
    }
};