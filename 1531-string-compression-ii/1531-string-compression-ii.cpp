class Solution {
public:
    int calc(int n) {
        if(n < 2) {
            return 0;
        }
        if(n >= 2 && n < 10) {
            return 1;
        }
        if(n >= 10 && n < 100) {
            return 2;
        }
        return 3;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int dp[n + 1][k + 1];
        if(n == k) {
            return 0;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j] = 1 << 20;
            }
        }
        
        for(int j = 0; j <= k; j++) {
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                if(j > 1) {
                    dp[i][j] = dp[i - 1][j - 1]; // removing current character itself
                }
                int count = 0;
                int del = 0;
                for(int p = i; p > 0; p--) {
                    if(s[i - 1] == s[p - 1]) {
                        count++;
                    } else {
                        del++; // removing a different character in between to club same characters
                    }
                    if(del > j) {
                        break;
                    }
                    // matching done till index (p - 1) with (i - 1)
                    dp[i][j] = min(dp[i][j], dp[p - 1][j - del] + 1 + calc(count));
                }
            }
        }
        
        return dp[n][k];
    }
};