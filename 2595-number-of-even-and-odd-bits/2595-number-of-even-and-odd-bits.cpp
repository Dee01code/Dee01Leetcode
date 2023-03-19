class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even =0;
        int odd= 0;
        bool ck = 0;
        string s = "";
        while(n){
            int t = n&1;
            n = n>>1;
            s += to_string(t);
        }
        
        for(int i=0; i<s.size(); i++){
            if(i%2 == 0 && s[i] == '1') even++;
            if(i%2 == 1 && s[i] == '1') odd++;
        }
        return {even,odd};
    }
};