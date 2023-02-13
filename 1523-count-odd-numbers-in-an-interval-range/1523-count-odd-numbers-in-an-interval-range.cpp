class Solution {
public:
    int countOdds(int low, int high) {
        int odd1 = low - low/2;
        int odd2 = high - high/2;
        int ans = odd2-odd1;
        if(low % 2 == 1){
            ans++;
        }
        return ans;
    }
};