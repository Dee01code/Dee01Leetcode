//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxi = 0;
    int dp[51][51];
    int solve(int i, int j, vector<vector<int>>& mat){
        
        if(i >= mat.size() || j >= mat[0].size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = 1 + solve(i,j+1,mat);
        int diagonal = 1 + solve(i+1,j+1,mat);
        int down = 1 + solve(i+1,j,mat);
        
        if(mat[i][j]){
            int ans = min(right, min(diagonal,down));
            maxi = max(maxi,ans);
            return dp[i][j] = ans;
            
        }
        else return dp[i][j] = 0;
    }

    int maxSquare(int n, int m, vector<vector<int>> mat){
        memset(dp,-1,sizeof(dp));
        solve(0,0, mat);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends