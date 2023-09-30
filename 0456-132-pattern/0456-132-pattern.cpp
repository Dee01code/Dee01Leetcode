class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>>st;
        int cur_min = nums[0];
        st.push({nums[0], cur_min});

        for (int k = 1; k < nums.size(); ++k) {
            while (!st.empty() && st.top().first <= nums[k]) st.pop();
            if (!st.empty() && nums[k] > st.top().second) return true;
            st.push({nums[k], cur_min});
            cur_min = min(cur_min, nums[k]);
        }
        return false;
    }
};