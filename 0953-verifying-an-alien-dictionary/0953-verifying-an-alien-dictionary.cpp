class Solution {
public:
    unordered_map<char, int> m;
    
    bool compare(string a, string b){
        
        for(int i=0; i<min(a.size(),b.size()); i++){
            if(m[a[i]] < m[b[i]]) return true;
            if(m[a[i]] > m[b[i]]) return false;
        }
        
        if(a.size()>b.size()) return false;
        return true;
    }
    
    
    bool isAlienSorted(vector<string>& words, string order) {
        
        
        for(auto i=0; i<26; i++){
            m[order[i]] = i;
        }
        
        vector<string> checker = words;
        
        sort(words.begin(),words.end(),[&](string a, string b){
            return compare(a,b);
        });
        
        return words == checker;
        
    }
};