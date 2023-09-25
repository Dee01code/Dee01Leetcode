class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for(int i = 0; i<t.size(); i++){
            if(i < s.size()) ans ^= s[i] - 'a';
            ans ^= t[i]-'a';
        }
        return 'a'+ans;
    }
};