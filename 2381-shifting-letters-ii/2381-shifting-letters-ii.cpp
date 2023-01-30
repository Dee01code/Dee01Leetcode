class Solution {
public:
    string shiftingLetters(string g, vector<vector<int>>& s) {
        
        int n = g.size(); 
        vector<long> line(n+1,0);
        
        for(auto i : s){
            int st = i[0];
            int end = i[1];
            int dir = i[2];
            
            if(dir){
                line[st] += 1;
                line[end+1] -= 1;
            }
            else{
                line[st] -= 1;
                line[end+1] += 1;
            }
        }
        
        for(int i = 1; i<n; i++) line[i] += line[i-1];
        
        for(int i = 0; i<n; i++){
            int shift = (g[i]-'a' + line[i])%26;
            shift = (shift+26)%26;
            g[i] = 'a'+shift;
        }
        return g;
    }
};
