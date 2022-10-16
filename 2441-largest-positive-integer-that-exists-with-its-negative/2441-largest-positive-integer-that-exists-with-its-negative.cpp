class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for(auto i : nums){
            m[i]++;
        }
        for(auto i: m){
            if(i.first >= 0) return -1;
            if(i.first < 0){
                if(m.find(abs(i.first)) != m.end()){
                    return abs(i.first);
                }
            }
        }
        return -1;
    }
};