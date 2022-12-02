class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>m(26,0),m1(26,0);
        for(auto i:word1)m[i-'a']++;
        for(auto i:word2)m1[i-'a']++;
        for(int i=0;i<26;i++){
            if((m[i]&&!m1[i])||(!m[i]&&m[i]))return false; // if a character exist only in one string then return false..
        }
        sort(m.begin(),m.end());
        sort(m1.begin(),m1.end());
        return m==m1;
    }
};