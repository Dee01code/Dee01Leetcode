class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<char,int> m;
        int n = A.size();
        vector<int> ans(n,0);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            
            m[A[i]]++;
            m[B[i]]++;
            
            if(A[i] != B[i]){ 
                if(m[A[i]] == 2) cnt++;
                if(m[B[i]] == 2) cnt++;
            }
            else cnt++;
            
            ans[i] = cnt;
        }
        return ans;
    }
};