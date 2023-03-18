class Solution {
public:
    int distMoney(int m, int c) {
        
        vector<int> child(c,1);
        if(m-c < 0) return -1;
        if(m-c == 0) return 0;
        int i=0;
        m -= c;
        while(m>0 && i<c){
            if(m>=7){
                child[i] += 7;
                i++;
                m-=7;

            }        
            else{
                child[i] += m;
                i++;
                m=0;
            }
            // cout << " Remaining money = " << m;
        }
        for(auto i : child){
            cout << i << " ";
        }
        if(m>0){
            return c-1;
        }
        int cnt = 0;
        for(int i = 0; i<c; i++){
            if(child[i] == 4){
                if(i==c-1){
                    return cnt-1;
                }
                else{
                    return cnt;
                }
            }
            if(child[i] == 8)cnt++;
            
        }
        cout << "hi";
        return cnt;
    }
};