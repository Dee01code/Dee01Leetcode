class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        
        unordered_map<int,int> m;
        priority_queue<vector<int>> p; 
        int n = r1.size();
        for(int i = 0; i<n; i++){
            p.push({r1[i]-r2[i],i});
        }
        
        while(k--){
            vector<int> temp = p.top();
            p.pop();
            m[temp[1]]++;
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(m.count(i)){
                ans += r1[i];
            }
            else ans += r2[i];
        }
        return ans;
        
    }
};