class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {

            int i = 0;
            int j = 0;
            int cnt = 0;
            while (i < nums.size())
            {
                nums[cnt] = nums[i];
                j = i + 1;
                while (j<nums.size() && nums[i] == nums[j]) j++;
                i = j;
                cnt++;
            }
            return cnt;
        }
};