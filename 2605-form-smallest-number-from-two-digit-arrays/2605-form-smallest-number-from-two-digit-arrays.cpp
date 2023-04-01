class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(),nums2.end());
        
        for(auto i : nums1){
            if(count(nums2.begin(), nums2.end(), i)) return i;
        }
        
        // if(nums1[0] == nums2[0]) return nums1[0];
        int a = nums1[0];
        int b = nums2[0];
        return (a<b) ? a*10 + b : b*10 + a;
    }
};