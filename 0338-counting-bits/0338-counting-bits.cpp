class Solution {
public:
    
    int cnt1(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n &= n-1;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<=n; i++) ans.push_back(cnt1(i));
        return ans;
    }
};