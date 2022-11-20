class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1;
        
        stack<int> st;
        for(int i = 0; i < s.size(); i++)
        {            
            char c = s[i];
            if(c >= '0' && c <= '9')
            {
                int num = 0;
                while(i < s.size() && s[i]>='0' && s[i]<= '9')
                    num = num * 10 + (s[i++] - '0');
                res += sign * num;
                i--;
            }
            else if(c =='+') sign = 1;
            else if(c =='-') sign = -1;
            else if(c =='(')
            { 
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if(c ==')')
            {
                res *= st.top(); 
                st.pop();
                res += st.top(); 
                st.pop();
            }
        }
        return res;
    }
};