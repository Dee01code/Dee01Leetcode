class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char, int> m;
        
        for(auto i=0; i<26; i++){
            m[order[i]] = i;
        }
        
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                int s=0;
                while(s < min(words[i].size(),words[j].size())){
                    if(m[words[i][s]] > m[words[j][s]]) return false;
                    if(m[words[i][s]] < m[words[j][s]]) break;
                    s++;
                }
                if(words[i].size() > words[j].size() && words[i].substr(0,s) == words[j]) return false;
                // cout << words[i].substr(0,s) << " "<< words[j];
            }
        }
        return true;
    }
};