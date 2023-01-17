class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int flips = 0;
        int cnt1 = 0;
        
        for(auto i : s){
            if(i == '1') cnt1++;
            if(i=='0' && cnt1>0){
                flips++;
                cnt1--;
            }
        }
        return flips;
        
    }
};