class Solution {
public:
    int kthGrammar(int n, int k) {
        
        if(n == 1) return 0;
        
        int total = 1 << (n-1);
        int mid = total/2; 
        
        bool flip = (k <= mid) ? 0 : 1;
        cout << "n = " << n << " for k = " << k << " Flip = " << flip << endl; 
        return (flip) ? 1-kthGrammar(n-1,k-mid) : kthGrammar(n-1,k);
        
    }
};