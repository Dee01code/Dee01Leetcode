class Solution {
public:
    vector<long long> minOperations(vector<int>& arr, vector<int>& query) {

        int n = arr.size();
        int m = query.size();
        cout << "Array size = " << n << " Query size = " << m << endl;
        vector<long long int> pre(n,0);

        sort(arr.begin(),arr.end());
        cout << "after sorting" << endl;
        pre[0] = arr[0];
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1]+arr[i];
            cout << "Prefix Sum at index " << i << endl;
        }
        cout << "prefix success" << endl; 
        vector<long long int> ans(m);
        int cnt = 0;
        for(auto i : query){
            long long int cost = 0; 
            if(arr.back() < i){
                cost = i;
                cost *= n;
                cost -= pre[n-1];
                // cost += i*n - pre[n-1];c
            }
            else{
                auto it = upper_bound(arr.begin(),arr.end(),i);
                int ind = it-arr.begin();
                cout << "index is "<< ind<< endl;
                
                if(ind==0){
                    cost = i;
                    cost *= n;
                    cost = pre[n-1]-cost;
                }
                else {
                long long precost = i;
                    precost *= ind;
                    precost -= pre[ind-1];

                long long    postcost = i;
                    postcost *= (n-ind);
                    postcost = pre[n-1] - pre[ind-1] - postcost;
                cost += precost;
                cost += postcost;}
            }
            cout << "Query at index = " << cnt << endl;
            ans[cnt++] = cost;
        }
        
        return ans;
    }
};