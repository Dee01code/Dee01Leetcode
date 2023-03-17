//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int findPlatformOptimized(int arr[], int dep[], int n)
    {
        int count = 0, maxPlatforms = 0;
        // Find the maximum departure time
        int maxDepartureTime = dep[0];
        for(int i = 1; i < n; i++) {
            maxDepartureTime = max(maxDepartureTime, dep[i]);
        }
         
        // Create a vector to store the count of trains at each time
        vector<int> v(maxDepartureTime+2, 0);
         
        // Increment the count at the arrival time and decrement at the departure time
        for(int i = 0; i < n; i++) {
            v[arr[i]]++;
            v[dep[i]+1]--;
        }
         
        // Iterate over the vector and keep track of the maximum sum seen so far
        for(int i = 0; i <= maxDepartureTime+1; i++) {
            count += v[i];
            maxPlatforms = max(maxPlatforms, count);
        }
         
        return maxPlatforms;
    }
    
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	return findPlatformOptimized(arr, dep, n);
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends