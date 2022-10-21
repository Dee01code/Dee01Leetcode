class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k)
        {

            map<int, int> mp;
            mp[nums[0]] = 0;
            for (int i = 1; i < nums.size(); i++)
            {
                if (mp.find(nums[i]) != mp.end() && abs(i - mp[nums[i]]) <= k) return 1;
                else mp[nums[i]] = i;
            }
            return 0;
        }
};