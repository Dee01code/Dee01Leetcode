class Solution {
public:
    
    unordered_map<int,int> mp;
    int dp[2001][2001];
    
    bool solve(int curStonePos, int preJump){
        
        if(mp[curStonePos] == mp.size()-1) return 1;
        
        if(dp[mp[curStonePos]][preJump] != -1)  return dp[mp[curStonePos]][preJump]; 
        
        bool temp = 0;
        for(int next = preJump-1; next <= preJump+1; next++){
            if(next > 0 && mp.count(curStonePos + next)){
                temp |= solve(curStonePos + next, next);
            }
        }
        
        return dp[mp[curStonePos]][preJump] = temp;
        
    }
    
    bool canCross(vector<int>& s) {
    
        if(s[1] != 1) return 0;
        
        for(int i = 0; i<s.size(); i++){
            mp[s[i]] = i;
        }
        memset(dp,-1,sizeof(dp));

        return solve(1,1);
    }
};