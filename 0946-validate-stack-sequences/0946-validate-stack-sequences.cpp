class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {

        stack<int> s;
        int i = 0, j = 0;
        int n = pu.size();
        
        while(i<n && j<n){
            s.push(pu[i++]);
            while(!s.empty() && j<n && s.top() == po[j]){
                cout << s.top() << " ";
                s.pop();
                j++;
            } 
        }
        
        if(s.empty()) return 1;
        return 0;
    }
};