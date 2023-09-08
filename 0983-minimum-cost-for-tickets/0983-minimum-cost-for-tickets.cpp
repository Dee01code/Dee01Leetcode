class Solution {
public:
    
//     int solve(int ind, vector<int>& days, int validity , vector<int>& costs, ){
        
//         if(ind >= days.size()) return 0;
        
        
//         int ans = INT_MAX;
//         if(days[ind] <= validity)
//             ans = min(ans, solve(ind+1, days, validity, costs));

//         else{
//             for(int i = 0; i<3; i++){
//                 validity = (i == 0) ? days[ind] : ((i == 1) ? days[ind]+6 : days[ind]+29);
//                 ans = min(ans, costs[i] + solve(ind+1,days,validity,costs));
//             }
//         }
        
//         return ans; 
//     }
    
    int solve(int ind, vector<int>& days, int validity , vector<int>& costs, vector<vector<int>> &dp){
        
        if(ind >= days.size()) return 0;
        
        if(dp[ind][validity] != -1) return dp[ind][validity];
        
        int ans = INT_MAX;
        // cout <<"At ind = " << ind << endl;
        
        if(days[ind] <= validity)
            ans = min(ans, solve(ind+1, days, validity, costs, dp));

        else{
            for(int i = 0; i<3; i++){
                validity = (i == 0) ? days[ind] : ((i == 1) ? days[ind]+6 : days[ind]+29);
                ans = min(ans, costs[i] + solve(ind+1,days,validity,costs, dp));
            }
        }
        
        return dp[ind][validity] = ans; 
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<vector<int>> dp(366,vector<int>(400,-1));
        
        return solve(0,days,0,costs,dp);
    }
};