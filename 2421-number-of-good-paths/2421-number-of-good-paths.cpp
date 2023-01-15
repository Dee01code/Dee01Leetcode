class Solution {
public:
    int find(int i, vector<int> &ds) {
    return ds[i] < 0 ? i : ds[i] = find(ds[i], ds);
}
int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int n = vals.size(), left = 0;
    vector<vector<int>> al(n);
    for (auto &e : edges) {
        if (vals[e[0]] < vals[e[1]])
            swap(e[0], e[1]);
        al[e[0]].push_back(e[1]);
    }
    vector<int> ids(n), ds(n, -1), cnt(n);
    iota(begin(ids), end(ids), 0);
    sort(begin(ids), end(ids), [&](int i, int j){ return vals[i] < vals[j]; });
    for (int i = 0; i < n  && vals[ids[left]] < vals[ids.back()]; ++i) {
        while (vals[ids[left]] != vals[ids[i]])
            ++cnt[find(ids[left++], ds)];
        for (int j : al[ids[i]])
            ds[find(j, ds)] = find(ids[i], ds);
    }
    return accumulate(begin(cnt), end(cnt), (n - left) * (n - left + 1) / 2,
        [](int s, int cnt){ return s + cnt * (cnt + 1) / 2; });
}
    
};