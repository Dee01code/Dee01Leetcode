class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        
        vector<pair<int,int>> keep;
        int n = p.size();
        for(int i = 0; i<n; i++){
            keep.push_back({g[i],p[i]});
        }
        
        sort(keep.begin(),keep.end());
        
        int cnt=0;
        for(auto i: keep){
            cnt = max(cnt,i.first) + i.second;
        }
        return cnt;
    }
};
