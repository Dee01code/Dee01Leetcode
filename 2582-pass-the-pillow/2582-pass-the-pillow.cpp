class Solution {
public:
    int passThePillow(int n, int time) {
        
        int cycle = time%(n*2-2);
        
        if(cycle < n) return cycle+1;
        return (n-1-cycle%n);
        
    }
};