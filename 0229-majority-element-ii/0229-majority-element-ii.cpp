class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int unqInd = 0;
        int i = 0;
        int n = nums.size();
        int reqFreq = n/3;
        while(i<n){
            int k = i+1;
            int cnt = 1;
            while(k < n && nums[i] == nums[k]){
                cnt++;
                k++;
            }
            // cout << nums[i] << " = " << cnt << endl;
            if(cnt > reqFreq){
                // cout << "For = " << nums[i] << endl;
                nums[unqInd++] = nums[i];
            }
            i = k;
        }
        nums.resize(unqInd);
        return nums;
    }
};