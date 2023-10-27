class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(begin(arr), end(arr));
        
        unordered_map<int,long long> mp;
        for(auto i : arr) mp[i]++;
        
        int ans = 0;
        
        for(int i = 0; i<arr.size(); i++){
            int root = arr[i];
            
            for(int j = 0; j<i; j++){
                int lc = arr[j];
                int rc = root/lc;
                if(root % lc == 0 && mp.count(rc)){
                    mp[root] = (mp[lc]*mp[rc] + mp[root])%mod;
                } 
            }
            
            ans = (mp[root]+ans)%mod    ;
        }
        return ans;
    }
};