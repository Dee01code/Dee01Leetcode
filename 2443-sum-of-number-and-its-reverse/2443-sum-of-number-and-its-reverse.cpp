class Solution {
public:
    
    int reverse(int n){
        int reverse=0;
        while(n!=0)    
        {    
            int rem=n%10;      
            reverse=reverse*10+rem;    
            n/=10;    
        }
        return reverse;
        
    }
    
    bool sumOfNumberAndReverse(int num) {
        
        for(int i=0; i<=num; i++){
            if(i + reverse(i) == num) return 1;
        }
        return 0;
        
    }
};