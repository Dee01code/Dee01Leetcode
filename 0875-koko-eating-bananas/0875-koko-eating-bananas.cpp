class Solution {
public:
    
    int timetake(vector<int>& p, double k){
        int ans = 0;
        for(double i : p){
            ans += ceil(i/k);
        }
        return ans;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {

        
        int low = 1;
        int high = 1e9;
        
        while(low < high){
            int mid = low + (high-low)/2;
            if(timetake(piles,mid) > h) low = mid+1;
            else high = mid;
        }
        return low; 
    }
};