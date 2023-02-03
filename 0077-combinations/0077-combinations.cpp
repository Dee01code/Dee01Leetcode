class Solution {
public:
    
    void solve(vector<int> ip, vector<int> op, vector<vector<int>> &ans, int k){
        if(k==0){
            ans.push_back(op);
            return;
        }
        
        int ind = ip.size()-k;
        for(int i=0; i<= ind; i++){
            vector<int> op1 = op;
            op1.push_back(ip[i]); 
            vector<int> ip1 = ip;
            ip1.erase(ip1.begin(),ip1.begin()+i+1);
            solve(ip1, op1, ans, k-1);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> s;
        for(int i = 1; i<=n; i++){
            s.push_back(i);
        }
        
        vector<vector<int>> ans;
        vector<int> op;
        
        solve(s,op,ans,k);
        return ans;
    }
};