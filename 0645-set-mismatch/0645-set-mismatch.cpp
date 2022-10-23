class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int len = nums.size();
        int real_sum = (len*(len+1))/2;
        
        int dup;
        unordered_map<int,bool> m;
        for(auto i: nums){
            if(m.find(i) != m.end()){
                dup = i;    
                break;
            }
            m[i] = 1;
        }
        int actual_sum = 0;
        for(auto i: nums) actual_sum += i;
        // cout << dup << actual_sum;
        return {dup,real_sum-(actual_sum-dup)};
    }
};