class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i]-1;
            for(int j = i+1; j<nums.size(); j++){
                int b = nums[j]-1;
                int pro = a*b;
                ans = pro > ans ? pro : ans;
            }
        }
        return ans;
    }
};