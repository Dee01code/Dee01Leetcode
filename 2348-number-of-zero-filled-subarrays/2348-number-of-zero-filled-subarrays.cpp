class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        long long ans = 0;
        while(i<n){
            if(nums[i]==0){
                int j=i;
                while(j<n && nums[j] == 0) j++;
                long long num = j-i;
                cout << num << endl;
                ans += (num * (num+1))/2;
                i = j+1;
            }
            else i++;
        }
        return ans;
    }
};