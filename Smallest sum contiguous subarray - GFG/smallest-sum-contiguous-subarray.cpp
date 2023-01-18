//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  int kadane(vector<int> a){
      
      int sum = 0;
      int ans = INT_MIN;
      for(auto i : a){
          sum += i;
          ans = max(ans,sum);
          if(sum < 0){
              sum = 0;
          }
      }
      return ans;
      
  }
  int smallestSumSubarray(vector<int>& a){
      
    for(int i = 0; i<a.size(); i++){
        a[i] = -a[i];
    }
      return -kadane(a);
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends