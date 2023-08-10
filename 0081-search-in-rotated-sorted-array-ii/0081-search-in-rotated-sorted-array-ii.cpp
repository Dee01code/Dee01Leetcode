class Solution {
public:
    int n;
    int findK(const vector<int>& x) {
        if (n==1) return 0;
        if (n==2) return (x[0]<x[1])?1:0;
        int l = 0, r = n, m;
        while (l < r) {
            while (l < r-1 && x[l] == x[l+1]) l++; // Skip duplicates
            m = (r+l) / 2;
            if (m == n-1 || x[m] > x[m+1]) return m;
            if (x[m] > x[l]) l = m;
            else r=m;    
        }
        return m;
    }

    bool search(vector<int>& nums, int target) {
        n=nums.size();
        int k=findK(nums);
    //    cout<<"k="<<k<<endl;
    //    cout<<nums[k]<<endl;
        if (nums[k]==target) return 1;
        auto it=nums.begin();
        if (target>=nums[0] || k==n-1)
            return binary_search(it,it+k+1,target);      
        else
            return binary_search(it+k+1,it+n,target);
    }      
};