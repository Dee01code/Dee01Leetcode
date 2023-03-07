class Solution {
public:
    
    long long trips(vector<int>& time, long long k){
        long long ans = 0;
        for(long long i : time){ 
            ans += k/i;
        }
        return ans;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long  low = 1;
        long long  high = 1e14;
        while(low < high){
            
            long long  mid = low + (high - low)/2;
            long long tripnum = trips(time,mid);
            if(tripnum >= totalTrips) high = mid;
            else low = mid+1;
        }
        return low;
        
    }
};