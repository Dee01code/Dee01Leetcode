class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
    
        int n = nums.size();
        if(n==1) return 0;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        temp = nums;
        int i = 0, j=0, cnt = 0;
        while(i<n && j<n){
            
            while(i<n && j<n && nums[i] >= temp[j]){
                j++;
            }
            
            while(j < n && i<n && nums[i] < temp[j]){
                cnt++;
                i++;
                j++;
            }
            
        }
        return cnt;
    }
};