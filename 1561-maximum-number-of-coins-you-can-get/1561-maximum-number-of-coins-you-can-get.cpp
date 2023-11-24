class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int ans = 0;
        sort(piles.begin(), piles.end());
        
        int i = 0, j = n-1;
        
        while(i < j){
            ans += piles[j-1];
            j -= 2;
            i++;
        }
        return ans;
    }
};