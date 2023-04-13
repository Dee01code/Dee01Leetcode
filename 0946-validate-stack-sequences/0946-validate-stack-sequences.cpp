class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        
        stack<int> s;
        
        int i = 0;
        int j = 0;
        int n = pu.size();
        
    
        
        while(i<n && j<n){
            cout << " Outer loop & Pushing "<< pu[i]<<endl;
            s.push(pu[i++]);
            while(!s.empty() && j<n && s.top() == po[j]){
                cout << s.top() << " ";
                s.pop();
                cout << "stack size = "<<s.size() << endl;
                j++;
            } 
            
        }
        // cout << endl << s.size();
        // while(!s.empty()){
        //     cout << s.top() << " ";
        //     s.pop();
        // }
        if(s.empty()) return 1;
        return 0;
    }
};