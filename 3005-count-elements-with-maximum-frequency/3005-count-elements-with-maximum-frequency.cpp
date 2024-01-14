class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        int maxi = INT_MIN;
        vector<int> freq(101,0);
        for(auto i : nums) freq[i]++;
        for(auto i : freq){
            if(i > maxi){
                ans = 0;
                maxi = max(i, maxi);
                ans += i;
            }
            else if(i == maxi) ans += i;

        }
        return ans;
    }
};