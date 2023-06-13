class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mppr;
        int ans = 0;
        int n = grid.size();
        for(int i = 0;i<n;i++){
            vector<int>temp;
            for(int j = 0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
            mppr[temp]++;
        }
        for(int i = 0;i<n;i++){
            vector<int>temp;
            for(int j = 0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            ans+=mppr[temp];
        }
        return ans;
    }
};