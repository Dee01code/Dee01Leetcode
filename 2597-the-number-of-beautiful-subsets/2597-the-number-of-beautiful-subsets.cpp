class Solution {
public:
    
    void subsets(vector<int>& A, int& res,unordered_map<int,int> &m, int ind, int k)
    {
        if(ind == A.size()) res++;
        
        else{
        
            if(m[A[ind]-k] == 0 && m[A[ind]+k] == 0)  { 
                m[A[ind]]++;
                subsets(A,res,m,ind+1,k);
                m[A[ind]]--;
            }
            
            subsets(A,res,m,ind+1,k);
        }
    }

    
    int beautifulSubsets(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        int res=0;
        unordered_map<int,int> m;
        subsets(nums, res, m, 0, k);
        return res-1;
    }
};
