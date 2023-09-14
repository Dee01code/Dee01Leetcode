class Solution {
public:
    
    int tktCnt = 0;
    unordered_map<string,vector<string>> adj;
    vector<string> res;
    
    bool dfs(string src, vector<string>&path){
        path.push_back(src);
        
        if(path.size() == tktCnt+1){
            res = path;
            return 1;
        }
        
        vector<string> &nbr = adj[src];
        for(int i = 0; i<nbr.size(); i++){
            string dest = nbr[i];
            nbr.erase(nbr.begin()+i);
            if(dfs(dest,path)){
                return 1;
            }
            nbr.insert(nbr.begin()+i,dest);
        }
        path.pop_back();
        return 0;
    }
        
    vector<string> findItinerary(vector<vector<string>>& tic) {
        tktCnt = tic.size();
        for(auto &i : tic){
            string a = i[0];
            string b = i[1];
            
            adj[a].push_back(b);
            // adj[b].push_back(a);
        }
        
        for(auto &i : adj){
            sort(begin(i.second),end(i.second));
        }
        vector<string> path;
        dfs("JFK", path);
        return res;
        
    }
};