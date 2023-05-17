class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
//         int col = nums[0].size();
//         int row = nums.size();
//         int score = 0;
//         for(int i = 0; i<row; i++){
//             sort(nums[i].begin(),nums[i].end());    
//         }
        
      
//         for(int j = 0; j<col; j++){
            
//             int maxi = 0;
//             for(int i = 0; i<row; i++){
//                 int ele = nums[i][j];
//                 if(maxi < ele) maxi = ele;
//             }
//             score += maxi;
            
//         }
       
        // return score;
        
        int col = nums[0].size();
        int row = nums.size();
        int score = 0;
        for(int i = 0; i<row; i++){
            sort(nums[i].begin(),nums[i].end());    
        }
        
        int coln = col-1;
        for(int j = 0; j<col; j++){
            
            int maxi = INT_MIN;
            for(auto i : nums){
                int ele = i[coln];
                maxi = max(maxi,ele);
            }
            score += maxi;
            coln--;
        }
        return score;
        
//         int ans = 0;
//         int row = nums.size();
//         int col = nums[0].size();
//          for(int i = 0 ; i < row ; i++)
//          {
//             sort(nums[i].begin(),nums[i].end());
//          }
//         for(int i = 0 ; i < col ; i++)
//         {
//             int max = 0;
//             for(int j = 0 ; j < row ; j++)
//             {
//                 if(max < nums[j][i]) max = nums[j][i];
//             }
//             ans += max;
//         }
//         return ans;
        
    }
};