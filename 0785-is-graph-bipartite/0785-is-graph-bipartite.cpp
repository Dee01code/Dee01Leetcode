class Solution {
public:
    bool bfs(vector<vector<int>> &graph,vector<int> &col,int i){
        queue<int> q;
        q.push(i);
        col[i]=0;
        while(!q.empty()){
            int id = q.front();
            q.pop();
            for(int ad: graph[id]){
                if(col[ad]==-1){
                    col[ad]=!col[id];
                    q.push(ad);
                }
                else if(col[ad]==col[id]){
                    return false;
                }
            }
            
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(col[i]==-1){
               if( !bfs(graph,col,i))
                   return false;
            }
        } 
        return true;
    }
};
