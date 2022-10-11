class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int place1 = INT_MAX, place2 = INT_MAX;
        
        for(auto i: nums){
            if(i <= place1) place1 = i;
            else if(i <= place2) place2 = i;
            else return 1;
        }
        return 0;
        
    }
};