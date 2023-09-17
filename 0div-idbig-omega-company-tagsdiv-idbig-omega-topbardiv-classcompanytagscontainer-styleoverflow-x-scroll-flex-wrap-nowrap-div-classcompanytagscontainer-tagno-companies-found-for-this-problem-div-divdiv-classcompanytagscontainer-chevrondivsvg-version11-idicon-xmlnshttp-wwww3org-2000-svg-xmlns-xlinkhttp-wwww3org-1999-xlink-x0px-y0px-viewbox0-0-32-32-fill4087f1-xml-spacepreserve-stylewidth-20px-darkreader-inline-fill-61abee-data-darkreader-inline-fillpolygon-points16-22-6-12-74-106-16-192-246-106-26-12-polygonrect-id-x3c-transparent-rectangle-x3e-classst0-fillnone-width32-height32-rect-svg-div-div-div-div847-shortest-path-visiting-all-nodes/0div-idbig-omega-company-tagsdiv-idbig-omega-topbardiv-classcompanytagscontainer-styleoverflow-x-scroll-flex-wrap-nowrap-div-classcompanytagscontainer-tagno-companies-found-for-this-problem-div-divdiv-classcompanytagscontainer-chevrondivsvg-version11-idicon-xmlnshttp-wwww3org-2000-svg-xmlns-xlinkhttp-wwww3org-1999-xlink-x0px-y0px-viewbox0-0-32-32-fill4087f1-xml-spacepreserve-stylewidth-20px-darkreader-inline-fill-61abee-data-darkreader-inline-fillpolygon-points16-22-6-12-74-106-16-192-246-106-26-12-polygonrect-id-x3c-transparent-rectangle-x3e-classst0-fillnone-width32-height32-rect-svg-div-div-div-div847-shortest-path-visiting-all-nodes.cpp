typedef pair<int,int> p;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        if(graph.size() == 0 || graph.size() == 1) return 0;
        
        unordered_map<int,vector<int>> adj;
        for(int i = 0; i<graph.size(); i++){
            for(auto j : graph[i]) adj[i].push_back(j);
        }
        
        queue<p> q;
        set<p> inPath;
        for(int i = 0; i<graph.size(); i++){
            int mask = (1 << i);
            q.push({i,mask});
            inPath.insert({i,mask}); 
        }
        int path = 0;
        int totalMask = (1<<graph.size())-1;
        while(!q.empty()){
            
            int n = q.size();
            path++;
            
            for(int i = 0; i<n; i++){
                int node = q.front().first;
                int mask = q.front().second;
                q.pop();
                
                for(auto nb : adj[node]){
                    int newMask = (1 << nb) | mask;
                    
                    if(newMask == totalMask) return path;
                    
                    if(inPath.find({nb,newMask}) == inPath.end()){
                        inPath.insert({nb,newMask});
                        q.push({nb,newMask});
                    }
                }
                
            }
        }
        return -1;
        
    }
};