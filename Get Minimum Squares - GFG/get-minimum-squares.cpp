//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	
	int dp[10001];
	
	int solve(int n){
	    if(n < 0) return INT_MAX;
	    if(n == 0) return 0;
	    
	    if(dp[n] != -1) return dp[n];
	    
	    int ans = INT_MAX;
	    for(int i = 1; i*i <= n; i++){
	        int temp = 1 + solve(n-i*i);
	        if(temp != INT_MAX)
	            ans = min(ans,temp);
	    }
	    return dp[n] = ans;
	}
	
	int solveTab(int n){
	   // int dp[n+1] = {INT_MAX};
	   vector<int> dp(n+1,INT_MAX);
	    
	    dp[0] = 0;
	    
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j*j <= i; j++){
	            if(i- j*j >= 0)
	                dp[i] = min(dp[i], 1 + dp[i - j*j]);
	        }
	    }
	    return dp[n];
	    
	}
	
	int MinSquares(int n)
	{
	    memset(dp , -1, sizeof(dp));
	    return solveTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends