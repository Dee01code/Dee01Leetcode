class Solution {
public:
    
    int kadane(vector<int> a){
      
          int sum = 0;
          int ans = INT_MIN;
          for(auto i : a){
              sum += i;
              ans = max(ans,sum);
              if(sum < 0){
                  sum = 0;
              }
          }
          return ans;
      
    }
    int maxSubArray(vector<int>& nums) {
        
        return kadane(nums);
        
    }
};