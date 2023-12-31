class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        unordered_map<char,vector<int>> mp;
        
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]].size() == 1) mp[s[i]].push_back(i);
                else mp[s[i]][1] = i;
            }
            else
                mp[s[i]].push_back(i);
        }
        
        int ans = -1;
        // cout << mp.size();
        for(auto i : mp){
            cout << i.first << " : " ;
            for(auto j : i.second) cout << j << " ";
            cout << endl;
            vector<int> temp = i.second;
            if(temp.size() == 2){
                int sum = temp[1]-temp[0]-1;
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};