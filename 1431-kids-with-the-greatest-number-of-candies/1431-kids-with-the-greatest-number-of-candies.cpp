class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ex) {
        int n = candies.size();
        vector<bool> ans(n,0);
        int maxi = *max_element(candies.begin(),candies.end());
        for(int i = 0; i<n; i++){
            ans[i] = candies[i] + ex >= maxi;
        }
        return ans;
    }
};