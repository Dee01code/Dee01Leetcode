class Solution {
public:
    void getCount(int i, vector<vector<int>>& tree, string& labels, vector<int>& counts, vector<int>& res) {
        //saving initial count
        int count = counts[labels[i] - 'a'];
        //marking this 0 to signify the node is visited
        res[i] = 0;
        for(int node : tree[i]) {
            if(res[node] == -1) {//visited check
                getCount(node, tree, labels, counts, res);
            }
        }
        //increment label count after child nodes traversal
        counts[labels[i] - 'a'] += 1;
        //final count is current count - initial count
        res[i] = counts[labels[i] - 'a'] - count;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        //to store counts of labels
        vector<int> counts(26, 0);
        //result vector that will be returned
        vector<int> res(n, -1);
        //adjacency list for tree
        vector<vector<int>> tree(n);
        for(auto edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        getCount(0, tree, labels, counts, res);
        return res;
    }
};