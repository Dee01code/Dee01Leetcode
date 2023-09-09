class Solution {
public:
    int dp[101][101];
    int solve(vector<int>& values, int i, int j){
        
        if(i+1 == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            int score = values[i]*values[j]*values[k];
            ans = min(ans, score + solve(values,i,k) + solve(values,k,j));
        }
        return dp[i][j] = ans;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return solve(values,0,values.size()-1);
    }
};