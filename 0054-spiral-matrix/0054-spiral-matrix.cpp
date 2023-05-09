class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
     
        int row = m.size();
        int col = m[0].size();
        
        vector<int> ans;
        
        int stR = 0;
        int endR = row-1;
        int stC = 0;
        int endC = col-1;
        
        int i;
        
        while(stR<=endR && stC <= endC){
            i = stC;
            while(stR<=endR && stC <= endC && i<=endC){
                ans.push_back(m[stR][i++]);
            }
            stR++;
            
            i = stR;
            while(stR<=endR && stC <= endC && i<=endR){
                ans.push_back(m[i++][endC]);
            }
            endC--; 
            
            i=endC;
            while(stR<=endR && stC <= endC && i>=stC){
                ans.push_back(m[endR][i--]);  
            }
            endR--;
            
            i=endR;
            while(stR<=endR && stC <= endC && i>=stR){
                ans.push_back(m[i--][stC]); 
            }
            stC++;
            
        }
        return ans;
    }
};