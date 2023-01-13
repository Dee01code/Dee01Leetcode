//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    // void heapify(int arr[], int len, int i){
    //     int ind = i;
    //     int lnode = 2*ind+1;
    //     int rnode = 2*ind+2;
        
    //     if(lnode < len && arr[ind] < arr[lnode]){
    //         ind = lnode;
    //     }
    //     if(rnode < len && arr[ind] < arr[rnode]){
    //         ind = rnode;
    //     }
    //     if(ind != i){
    //         swap(arr[i],arr[ind]);
    //         heapify(arr,len,ind);
    //     }
    //     return;
    // }
    
    // void deleteHeap(int arr[], int n){
    //     swap(arr[0],arr[n-1]);
    //     int ind = 0;
    //     n--;
    //     while(ind < n-1){
    //         int lnode = 2*ind+1;
    //         int rnode = 2*ind+2;
    //         if(lnode < n && arr[ind] < arr[lnode]){
    //             swap(arr[ind],arr[lnode]);
    //             l=1;
    //         }
    //         if(rnode < n && arr[ind] < arr[rnode]){
    //             swap(arr[ind],arr[rnode]);
    //             r = 1;
    //         }
            
    //     }    
    //     // heapify(arr,n,0);
        
    // }
    
    // void insert(int arr[], int n){
        
    //     int ind = n-1;
    //     int pnode = (ind%2 == 0)? ind/2-1 : ind/2;
    //     while(ind>0 && arr[ind] > arr[pnode]){
    //         swap(arr[ind],arr[pnode]);
    //         ind = pnode;
    //         pnode = ind/2;
    //     }
    //     return;
    // }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> pq;
        for(int i = 0; i<k; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k; i<=r; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends