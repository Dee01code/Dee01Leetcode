class Solution {
public:

    int find_parent(int u, vector<int> & parent){
        if(parent[u] == u) return u;
        return (parent[u] = find_parent(parent[u], parent));
    }

    void make_set(int u, int v, vector<int> & parent){
        u = find_parent(u, parent);
        v = find_parent(v, parent);
        if(u != v) parent[v] = u;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int e_size = edges.size();
        int no_need = 0;
        vector<int>parent_a(n+2), parent_b(n+2);
        for(int i=1; i<=n; i++){
            parent_a[i] = parent_b[i] = i;
        }

        for(int i=0; i<e_size; i++){
            int type = edges[i][0], u = edges[i][1], v = edges[i][2];
            if(type == 3){
                if(find_parent(u, parent_a) == find_parent(v, parent_a) || find_parent(u, parent_b) == find_parent(v, parent_b)){
                    no_need++;
                    continue;
                }
                make_set(u, v, parent_a);
                make_set(u, v, parent_b);
            }
        }

        for(int i=0; i<e_size; i++){
            int type = edges[i][0], u = edges[i][1], v = edges[i][2];
            if(type == 1){
                if(find_parent(u, parent_a) == find_parent(v, parent_a)){
                    no_need++;
                    continue;
                }
                make_set(u, v, parent_a);
            }
            if(type == 2){
                if(find_parent(u, parent_b) == find_parent(v, parent_b)){
                    no_need++;
                    continue;
                }
                make_set(u, v, parent_b);
            }
        }

        for(int i=1; i<=n; i++){
            if(find_parent(i, parent_a) != find_parent(n, parent_a) || find_parent(i, parent_b) != find_parent(n, parent_b)){
                return -1;
            }
        }
        return no_need;
    }
};