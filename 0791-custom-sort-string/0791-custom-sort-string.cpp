class Solution {
public:
    string customSortString(string order, string s) {
        
        string ans="";
        
        unordered_map<char,int> m;
        for(auto i : s) m[i]++;
        
        for(auto i : order){
            if(m.find(i) != m.end()){
                for(int n=0; n<m[i]; n++) ans.push_back(i);
            }
            m.erase(i);
        }
        for(auto i : m){
            int n = i.second;
            char c = i.first;
            while(n--){
                ans.push_back(c);
            }
        }
        
        return ans;
        
    }
};