class Solution {
public:
    const int mod = 1e9+7;
    int dp[5][5][5002];
    vector<vector<char>> mat;
    // 2,1 
    // 2,-1
    // -2,1
    // -2,-1
    // 1,2
    // 1,-2
    // -1,2
    // -1,-2
    int dxy[9] = {2,1,2,-1,-2,1,-2,-1,2};
    
    void fillmat(){
        mat.resize(4,vector<char>(3,'0'));
        char cnt = '1';
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mat[i][j] = cnt++;
            }
        }
        
    }
    
    bool boundCheck(int r, int c){
        if(r < 0 || r > 3 || c < 0 || c > 2 || (r == 3 && (c == 0 || c == 2))) return 0;
        return 1;
    }
    
    int cnt(int curR, int curC, int n){
        
        if(n==0){
            // cout << temp << endl;
            return 1;
        }
        
        auto& it = dp[curR][curC][n];
        
        if(it != -1) return it;
        
        int ans = 0;
        
        for(int i = 0; i<8; i++){
            
            int newR = curR + dxy[i];
            int newC = curC + dxy[i+1];
            
            if(boundCheck(newR, newC)){
                // temp.push_back(mat[newR][newC]);
                ans = (ans+cnt(newR, newC, n-1))%mod;
                // temp.pop_back();
            }
        }
        
        return it = ans%mod;
    }
    
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        fillmat();
        
        int ans = 0;
        
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                string temp = "";
                temp += mat[i][j];
                ans = (ans + cnt(i,j,n-1))%mod;
            }
        }
        ans = (ans + cnt(3,1,n-1))%mod;
        return ans;
        // for(auto i : mat) 
        //     for(auto j : i)
        //         cout << j << " ";
        //     cout << endl;
        // return 0;
    }
};