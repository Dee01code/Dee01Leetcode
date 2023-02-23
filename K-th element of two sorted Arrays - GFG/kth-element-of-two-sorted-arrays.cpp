//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int a1[], int a2[], int n, int m, int k)
    {
   
        int i = 0, j = 0;
        vector<int> ans;
        int ind = 0;
        while(i < n && j<m){
            
            if(a1[i] <= a2[j]){
                
                ans.push_back(a1[i]);
                i++;
                ind++;
            }
            
            else if(a1[i] > a2[j]) {
                ans.push_back(a2[j]);
                j++;ind++;
            }
            if(ind == k) return ans.back();
        }
        
        while(i<n){
            if(ind == k) return ans.back();
            ans.push_back(a1[i++]);
            ind++;
        }
        while(j<m){
            if(ind == k) return ans.back();
            ans.push_back(a2[j++]);
            ind++;
        }
        return ans.back();
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends