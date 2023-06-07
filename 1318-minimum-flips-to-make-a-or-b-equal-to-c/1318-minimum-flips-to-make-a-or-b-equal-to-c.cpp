class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a || b || c){
            int abit = a&1;
            a >>= 1;
            int bbit = b&1;
            b >>= 1;
            int cbit = c&1;
            c >>= 1;
            if(cbit == 1 && (abit == 0 && bbit == 0)) cnt++;
            if(cbit == 0){
                if(abit == 1) cnt++;
                if(bbit == 1) cnt++;
            }
            cout << abit << " || " << bbit << " = " << cbit << endl;
        }
        return cnt;
    }
};