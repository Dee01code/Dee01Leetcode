class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        
        int n = s.size();
        map<string,vector<string>> m;
        
        for(auto i: s){
            string temp = i;
            sort(i.begin(),i.end());
            m[i].push_back(temp);
            // if(m.find(i)!=m.end()){
            //     m[i].push_back(temp);
            // }
            // else{
            //     m[i].push_back(temp)
            // }
        }
        vector<vector<string>> ans;
        for(auto i: m){
            ans.push_back(i.second);
        }
        return ans;
    }
};