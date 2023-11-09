class Solution {
public:
    const int mod = 1e9+7;
    
    int sum(int n) {
        long long mul1 = n % mod; // Use long long to prevent overflow during multiplication
        long long mul2 = (n + 1) % mod;
        long long ans = (mul1 * mul2) % mod;
        return static_cast<int>(ans / 2); // Convert back to int after division
    }

    int countHomogenous(string s) {
        int i = 0;
        int n = s.size();
        int ans = 0;
        while(i<n){
            int j = i+1;
            while(j<n && s[i]==s[j]) j++;
            int cnt = j-i;
            cout << s[i] << " = " << cnt << endl;
            ans = (ans + sum(cnt))%mod;
            i = j;
        }
        return ans;
        
    }
};