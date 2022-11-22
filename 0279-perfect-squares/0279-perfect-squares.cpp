class Solution {
public:
    
    // using lagrange's four square thrm. 
    
    bool ckSquare(int n){
        int k = (int)sqrt(n);
        if(k*k == n) return 1;
        return 0;
    }
    
    int numSquares(int n) {
        
        while(n%4==0) n/=4;
        
        if(n%8==7) return 4;
        if(ckSquare(n)) return 1;
        
        for(int i=1; i*i<=n; i++){
            if(ckSquare(n-i*i)) return 2;
        }
        return 3;
    }
};