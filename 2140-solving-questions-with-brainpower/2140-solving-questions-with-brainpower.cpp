class Solution {
public:
    long long solve(vector<vector<int>>& questions,vector<long long> &dp,int index,int len) {
        if(dp[index]!=-1)
            return dp[index];
        long long first=0,second=questions[index][0];
        
        if(index+1<len)
            first=solve(questions,dp,index+1,len);
        if(index+questions[index][1]+1<len)
            second+=solve(questions,dp,index+questions[index][1]+1,len);
        
        return dp[index]=max(first,second);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int len=questions.size();
        vector<long long> dp(len,-1);
        
        return solve(questions,dp,0,len);
    }
};