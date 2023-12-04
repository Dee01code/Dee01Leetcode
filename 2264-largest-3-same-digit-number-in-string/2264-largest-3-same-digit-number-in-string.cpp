class Solution {
public:
    int sint(string s){
        int ans = 0;
        for(auto i : s){
            ans += i-'0';
            ans *= 10;
        }
        return ans;
    }
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i = 2; i<num.size(); i++){
            if(num[i-2] == num[i] && num[i-1] == num[i]){
                if(ans.size()==0) ans = num.substr(i-2,3);
                else{
                    string temp = num.substr(i-2,3);
                    int res = sint(ans);
                    int comp = sint(temp);
                    if(comp > res) ans = temp;
                }
            }
        }
        return ans;
    }
};