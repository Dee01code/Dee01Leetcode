class Solution {
public:
    int countTime(string time) {
        
        int res = 1;
        if(time[4] == '?') res *= 10;
        if(time[3] == '?') res *= 6;
        if(time[1] =='?' && time[0] == '?') res*=24;
        if(time[1] =='?' && time[0] != '?'){
            if(time[0] == '0' || time[0] == '1') res*=10;
            else res*=4;
        }
        if(time[1] !='?' && time[0] == '?'){
            if(time[1] < '4') res*=3;
            else res*=2;
        }
        return res;
    }
};