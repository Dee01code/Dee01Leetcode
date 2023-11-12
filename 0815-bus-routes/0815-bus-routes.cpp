class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int tar) {
        
        if(src==tar) return 0;
        
        unordered_map<int,vector<int>> mp;
        
        for(int i = 0; i<routes.size(); i++){
            for(auto & stop : routes[i]) mp[stop].push_back(i);
        }
        
        queue<int> q;
        vector<int> visited(501,0);
        
        for(auto & st : mp[src]){
            visited[st] = 1;
            q.push(st);
        }
        
        int ans = 1;
        
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int ind = q.front();
                q.pop();
                for(auto& cur : routes[ind]){
                    if(cur == tar) return ans;
                    
                    for(auto& stop : mp[cur]){
                        if(!visited[stop]){
                            visited[stop] = 1;
                            q.push(stop);
                        }
                    }
                    
                }
            }
            ans++;
        }
        return -1;
    }
};