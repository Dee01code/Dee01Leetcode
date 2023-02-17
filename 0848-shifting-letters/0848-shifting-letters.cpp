class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        
        int n = s.size();
        vector<long long int> line(n,0);
        
        for(int i=0; i < shifts.size(); i++){
            
            line[0] += shifts[i];
            if(i+1 < n)
                line[i+1] -= shifts[i]; 
            
        }
        
        for(int i = 1; i<n; i++){
            line[i] += line[i-1];
        }
        for(int i = 0; i<n; i++){
            s[i] = 'a' + ((s[i]-'a' + line[i])%26);
        }
        return s;
        
    }
};