class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(auto i : s){
            if(i == '(' || i == '{' || i == '['){
                st.push(i);
            }
            else{
                if(st.empty()) return 0;
                char open = st.top();
                if( (open == '(' && i == ')') || (open == '{' && i == '}') || (open == '[' && i == ']') ) st.pop();
                else return 0;
            }
        }
        if(st.empty()) return 1;
        return 0;
    }
};