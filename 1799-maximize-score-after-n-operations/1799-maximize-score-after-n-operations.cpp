class Solution {
public:

int rec(int op,int cantake,vector<int>& nums,vector<vector<int>>&dp){
    if(op==nums.size()/2 ){
        return 0;
    }
    
    if(dp[op][cantake]!=-1)
    return dp[op][cantake];
  int ans=0;
    for(int i=0;i<nums.size();i++){
        if(cantake & (1<<i)){
            for(int j=i+1;j<nums.size();j++){
                if(cantake & (1<<j)){
                     ans=max(ans, (op+1)*gcd(nums[i],nums[j])+rec(op+1,(cantake&(~(1<<j)))&(~(1<<i)),nums,dp));
                 
                }
            }
        }
    }

    return dp[op][cantake]=ans;
     

}

    int maxScore(vector<int>& nums) {

        int cantake=(1<<(nums.size()))-1;
         vector<vector<int>>dp(nums.size()/2,vector<int>(cantake+1,-1));
        return rec(0,cantake,nums,dp);

        return 0;
    }
};