class Solution {
public:
    
    int reverse(int n){
        int reverse=0;
        while(n!=0)    
        {    
            int rem=n%10;      
            reverse=reverse*10+rem;    
            n/=10;    
        }
        return reverse;
        
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> copied;
        for(auto i:nums){
            copied.insert(i);
        }
        
        for(int i=0; i<n; i++){
            copied.insert(reverse(nums[i]));
        }
        return copied.size();
        
        
    }
};