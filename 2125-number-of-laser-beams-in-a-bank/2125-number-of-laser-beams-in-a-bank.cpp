class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n = bank.size();
        int m = bank[0].size();
        
        int prev = 0;
        int ans = 0;
        
        for(int r = 0; r < n; r++){
            
            int laser = 0;
            
            for(int c = 0; c < m; c++){
                if(bank[r][c] == '1') laser++;
            }
            // cout << "Laser in Row = "<< r << " = " << laser << " ";
            
            if(laser != 0) {
                if(prev != 0){
                    ans += laser*prev;
                    // cout << "Row = " << r << " = "  << laser*prev<< endl;
                }
                prev = laser;
            }
            
        }
        return ans;
        
    }
};