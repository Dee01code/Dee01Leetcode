#include <bits/stdc++.h>
typedef long long int ll;
ll mod = 1e9+7;


class Solution {
public:
    string tt;            //global defined target string
    int fq[1001][26];      //global defined frequency array
    
    ll solve(vector<vector<ll>> &dp,  int k1, int k2)
    {
        // Base Conditions
        if(k2 > k1)
        {
            return ll(0); 
        }
        if(k2 <0)
        {
            return ll(1);
        }
        
        // DP
        if(dp[k1][k2] != ll(-1))
        {
            return dp[k1][k2];
        }
        
        // Temporary ans for this recursion
        ll tans = ll(0);
        
        tans+=solve(dp, k1-1, k2); //skip k1 index
        tans%=mod;
        
        // include the character from the k1 index of words if it matches with the k2 index of target
        if(fq[k1][tt[k2]-'a'] > 0)
        {
            tans = (tans+  (ll(fq[k1][tt[k2]-'a'])*solve(dp, k1-1, k2-1))%mod)%mod;
        }
        
        // Update DP
        dp[k1][k2] = tans;
        return tans;
        
    }
    
    int numWays(vector<string>& words, string target) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        tt =target;
        
        if(target.length() > words[0].length()){
            return 0;
        }
        
        int nw = words.size();
        int wl = words[0].length();
        int tl = target.length();
        
        // Update frequency array
        for(int i = 0; i<wl; i++)
        {
            // Initialisation
            for(int k = 0; k<26; k++)
            {
                fq[i][k] = 0;
            }
            
            // Updating frequency
            for(int j = 0; j<nw; j++)
            {
                fq[i][words[j][i] - 'a']++;
            }
        }
        
        // Define DP vector
        vector<vector<ll>> dp(wl, vector<ll>(tl,ll(-1)));
        
        // Store long long int value in tans
        ll tans = solve(dp, wl-1, tl-1);
        
        // Convert ll to int
        int ans = int(tans%mod);
        
        return ans;
    }
};