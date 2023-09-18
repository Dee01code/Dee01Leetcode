class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> cnt(mat.size(),{0,0});
        for(int i = 0; i<mat.size(); i++){
            cnt[i].first = i;
            for(int j = 0; j<mat[0].size(); j++){
                if(mat[i][j]) cnt[i].second++;
            }
        }
        
        sort(cnt.begin(), cnt.end(), [&](pair<int,int> a, pair<int,int> b){
            if(b.second > a.second) return true;
            if(b.second == a.second) return a.first < b.first;
            return false;
        });
        
        for(auto i : cnt){
            cout << i.first << " = " << i.second << endl;
        }
        
        vector<int> ans;
        for(int i = 0; i<k; i++) ans.push_back(cnt[i].first);
        return ans;
    }
};