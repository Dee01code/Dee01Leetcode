class Solution {
public:
    
    const int mod = 1e9+7;
    
    int rev(int n){
        int ans = 0;
        while(n){
            int dig = n%10;
            ans *= 10;
            ans += dig;
            n /= 10;
        }
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int,vector<int>> mp;
        // unordered_map<int,int> reverse;
        
        int ans = 0;
        
        for(int i = nums.size()-1; i>=0; i--) {
            int revNum = rev(nums[i]);
            int diff = nums[i]-revNum;
            
            if(mp.count(diff)){
                ans = (ans+mp[diff].size())%mod;
            }
            
            mp[diff].push_back(i);
            // reverse[nums[i]] = revNum;
            
            
        }
        
        return ans;
        
        
    }
};