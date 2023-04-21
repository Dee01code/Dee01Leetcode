//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    
	    int ans = -1;
	    int cnt = m;
	    for(auto i = 0; i<n; i++){
	        int s = 0;
	        int e = m-1;
	        int ind = INT_MAX; 
	        while(s<=e){
	            int mid = (s+e)/2;
	            if(arr[i][mid] == 1){ 
	                ind = mid;
	                e = mid-1;
	            }
	            else s = mid+1; 
	        }
	       // cout << "No of 1 in row = " << i+1 << " is " << m-ind << endl;
	        if(ind < cnt){
	            cnt = ind;
	            ans = i;
	        }
	       // cout << ans << endl;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends