class Solution {
public:
    int totalMoney(int n) {
        int st = 1;
        int cur = st;
        int res = 0;
        for(int i = 1; i <= n; i++){
            res += cur++;
            if(cur == st+7){
                st++;
                cur = st;
            }
        }
        return res;
    }
};