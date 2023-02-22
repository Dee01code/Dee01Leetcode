//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& a1, vector<int>& a2)
    {
        int n = a1.size(), m = a2.size();
        int i = 0, j = 0;
        vector<int> ans;
        
        while(i < n && j<m){
            
            if(a1[i] <= a2[j]){
                ans.push_back(a1[i]);
                i++;
            }
            
            else if(a1[i] > a2[j]) {
                ans.push_back(a2[j]);
                j++;
            }
            
        }
        
        while(i<n){
            ans.push_back(a1[i++]);
        }
        while(j<m){
            ans.push_back(a2[j++]);
        }
        
        int len = ans.size();
        
        if(len%2 == 1){
            return ans[len/2];
        }
        int mid = len/2;
        
        double res = (ans[mid]+ans[mid-1])/2.0;
        return res;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends