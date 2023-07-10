//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge){
    vector<int> cnt(n,0);
    for(int i=0; i<n; i++){
        if(edge[i] != -1)
            cnt[edge[i]] += i;
    }
    int ans = -1;
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(maxi <= cnt[i]){
            maxi = cnt[i];
            ans = i;
        }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends