class Solution {
public:
    
    int ans, pt, dp[10002];
    
    int solve(int x){
        
        if(x <= pt) return pt-x;
        if(x <= 0) return INT_MAX;
        
        auto & it = dp[x];
        if(it != -1) return it;
        
        int div5, div11, dec1;
        
        if(x%5 == 0){
            div5 = 1 + solve(x/5);
        }
        else{
            int quot = x/5;
            int newX = 5*(quot+1);
            div5 = (newX - x) + 1 + solve(newX/5);
        }
        
        if(x%11 == 0){
            div11 = 1 + solve(x/11);
        }
        else{
            int quot = x/11;
            int newX = 11*(quot+1);
            div11 = (newX - x) + 1 + solve(newX/11);
        }
        
        dec1 = 1 + solve(x-1);
        
        return it = min({dec1, div5, div11});
        
    }
    
    int minimumOperationsToMakeEqual(int x, int y) {
      
        memset(dp, -1, sizeof(dp));
        pt = y;
    
        return solve(x);                
    
    }
};