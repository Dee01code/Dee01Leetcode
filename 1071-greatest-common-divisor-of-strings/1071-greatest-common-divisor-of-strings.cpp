class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        unordered_map<char,int> m1,m2;
        
        for(auto i : s1) m1[i]++;
        for(auto i : s2) m2[i]++;
        
        // int size = min(m1.size(),m2.size());
        int size1 = m1.size();
        int size2 = m2.size();
        
        string ans = "";
        
        if(size1 != size2) return ans;
        
        
        
        for(int i = 0; i<__gcd(s1.size(),s2.size()); i++){
            if(s1[i] != s2[i]) return "";
            ans.push_back(s1[i]);
        }
        
        int gcdsize = ans.size();
        int i = 0,j = 0;
        while(i<s1.size()){
            if(ans != s1.substr(i,gcdsize)) return "";
            i += gcdsize;
        }
        while(j<s2.size()){
            if(ans != s2.substr(j,gcdsize)) return "";
            j += gcdsize;
        }
        return ans;
        
    }
};