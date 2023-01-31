class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = size(ages);
        vector<int> dp(n), id(n);
        iota(begin(id), end(id),0);
        sort(begin(id), end(id), [&](int const & i, int const & j)->bool{
            return (ages[i] < ages[j]) | (ages[i] == ages[j] && scores[i] < scores[j]);
        });
        for(int i=0; i<n; i++){
            int score = scores[id[i]];
            dp[i] = score;
            for(int j=0; j<i; j++){
                if(score >= scores[id[j]]){
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};