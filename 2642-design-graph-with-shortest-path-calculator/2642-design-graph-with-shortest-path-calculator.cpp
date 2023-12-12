class Graph {
public:
    unordered_map<int,vector<pair<int,int>>> mp;
    typedef pair<int,int> pi;
    int m = 0;
    Graph(int n, vector<vector<int>>& edges) {
        for (int i=0; i< edges.size();i++){
            pi p = {edges[i][1],edges[i][2]};
            mp[edges[i][0]].emplace_back(p);
        }
        m = n;
    }
    
    void addEdge(vector<int> edge) {
        pi p = {edge[1],edge[2]};
        mp[edge[0]].emplace_back(p);
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pi,vector<pi>,greater<pi> > pq;
        vector<int> dist(m,1000000000);
        dist[node1] = 0;
        pi p = {0, node1};
        pq.push(p);
        while (!pq.empty()){
            int dis = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            for (int i=0; i< mp[cur].size();i++){
                int next = mp[cur][i].first;
                if (dis + mp[cur][i].second < dist[next]){
                    dist[next] = dis + mp[cur][i].second;
                    pi p ={dist[next],next};
                    pq.push(p);
                }
            }
        }
        if (dist[node2] == 1000000000){
            return -1;
        }
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */