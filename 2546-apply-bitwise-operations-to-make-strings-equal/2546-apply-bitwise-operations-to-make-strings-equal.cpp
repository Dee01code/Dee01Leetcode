class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int cnt1 = 0;
        int cnt01 = 0, cnt10 = 0;
        for(auto i=0; i<s.size(); i++){
            if(s[i] == '1') cnt1++;
            if(s[i] == '1' && t[i] == '0') cnt10++;
            if(s[i] == '0' && t[i] == '1') cnt01++;
        }
        if(cnt10 == 0 && cnt01 == 0) return true;
        if(cnt1 == 0 && cnt01 != 0) return false;
        if(cnt01 + cnt1 > cnt10) return true;
        return false;
    }
};