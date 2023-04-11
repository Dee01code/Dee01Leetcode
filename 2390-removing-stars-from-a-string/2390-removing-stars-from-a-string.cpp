class Solution {
public:
    string removeStars(string s) {
        
        string ans = "";
        stack <char> store;
        
        for(auto i : s){
            if(i == '*') store.pop();
            else store.push(i);
        }
        
        while(!store.empty()){
            ans.push_back(store.top());
            store.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};