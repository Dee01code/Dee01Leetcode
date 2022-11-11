class Solution {
public:
    int minPartitions(string n) {
        int len = n.size();
        int maxi = 0;
        for(auto i : n){
            int dig = i-'0';
            maxi = (dig > maxi) ? dig : maxi;
        }
        return maxi;
    }
};