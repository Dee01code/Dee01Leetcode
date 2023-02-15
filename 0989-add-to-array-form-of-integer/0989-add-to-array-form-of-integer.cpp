class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) 
    {
        int n = nums.size()-1;
        while(k > 0 and n >= 0)
        {
            nums[n] += k;
            k = nums[n]/10;
            nums[n] = nums[n]%10;
            n--;
        }

        while(k > 0)
        {
            nums.insert(nums.begin(),k%10);
            k = k/10;
        }

        return nums;
    }
};