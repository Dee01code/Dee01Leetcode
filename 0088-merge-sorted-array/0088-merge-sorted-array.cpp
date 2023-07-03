class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1;
        int k = n+m-1;
        while(i>=0){
            nums1[k--] = nums1[i--];
        }
        
        int j=0;
        i = ++k;
        k = 0;
        while(i < n+m && j<n){
            if(nums1[i] < nums2[j]) nums1[k++] = nums1[i++];
            else nums1[k++] = nums2[j++];
        }
        
        while(i < n+m) nums1[k++] = nums1[i++];
        while(j < n) nums1[k++] = nums2[j++];
        
        return;
    }
};