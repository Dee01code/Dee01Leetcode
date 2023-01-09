class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas = 0;
        int totcost = 0;
        int curgas=0;
        int stpt = 0;
        for(int i=0; i<gas.size();i++){
            totgas += gas[i];
            totcost += cost[i];
            curgas += gas[i]-cost[i];
            if(curgas<0){
                stpt = i+1;
                curgas = 0;
            }
        }
        return (totgas<totcost)?-1:stpt;
    }
};