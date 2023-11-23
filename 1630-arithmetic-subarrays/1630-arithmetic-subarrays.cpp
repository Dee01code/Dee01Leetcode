class Solution {
    public:

        vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
            vector<bool> result(l.size());
            for (int i = 0; i < l.size(); i++) {
                vector<int> sequence(nums.begin() + l[i], nums.begin() + r[i] + 1);
                result[i] = helper(sequence);
            }
            return result;
        }
    
    private:
        bool helper(vector<int>& s) {
            sort(s.begin(), s.end());
            for (int i = 0; (i + 1) < s.size(); i++) {
                if ((s[i + 1] - s[i]) != (s[1] - s[0])) return false;
            }
            return true;
        }
};


// class Solution {
// public:
    
//     long sumAL(int a, int d, int n){
//         return (n*((2*a)+(n-1)*d))/2;  
//     }
    
//     vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
//         int n = nums.size();
//         int m = l.size();
        
//         vector<int> preSum(n,0), mini(n), maxi(n);
//         vector<bool> ans(m,0);
        
//         preSum[0] = nums[0];
//         // mini[0] = nums[0];
//         // maxi[0] = nums[0];
//         for(int i = 1; i<n; i++){ 
//             preSum[i] = preSum[i-1]+nums[i];
//             // mini[i] = min(mini[i-1],nums[i]);
//             // maxi[i] = max(maxi[i-1], nums[i]);
//         }
        
// //         for(auto i : preSum) cout << i << " ";
// //         cout << endl;
        
// //         for(auto i : mini) cout << i << " ";
// //         cout << endl;
        
// //         for(auto i : maxi) cout << i << " ";
// //         cout << endl;
        
//         for(int i = 0; i<m; i++){
//             int st = l[i];
//             int end = r[i];
//             int mini = nums[st], maxi = nums[st];
            
//             for(int i = st; i<=end; i++){
//                 if(nums[i] < mini){
//                     maxi = mini;
//                     mini = min(mini, nums[i]);
//                 }
//             }
            
//             int diff = maxi-mini;
            
//             int sum = preSum[end];
//             if(st > 0) sum -= preSum[st-1];
            
//             if(sum == sumAL(mini, diff, end-st+1)) ans[i] = 1;
//             else ans[i] = 0;
//         }
        
//         return ans;
        
//     }
// };