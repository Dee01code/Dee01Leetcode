class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        for(int i = 0; i<32; i++){
            int cnt1 = 0;
            for(auto num : nums){
                cnt1 += (num >> i) & 1;
            }
            cnt1 %= 3;
            ans |= (cnt1 << i);
        }
        return ans;
    }
};