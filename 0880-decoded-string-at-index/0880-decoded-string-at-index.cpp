class Solution {
public:
    string decodeAtIndex(string s, int k) {
        #define int long long
        int ss = 0;
        string ans = "";
        for(int i=0;i<s.size();i++) {
            if(s[i] >= '2' && s[i] <= '9') {
                ss*=(s[i]-'0');
            } else {
                ss++;
            }
            if(ss >= k) {
                if(s[i] >= '2' && s[i] <= '9') {
                    int prevSize = ss/(s[i]-'0');
                    return decodeAtIndex(s, k%prevSize == 0 ? prevSize : k%prevSize);
                } else {
                    return ans+=s[i];
                }
            }
        }
        return "";
        #undef int
    }
};