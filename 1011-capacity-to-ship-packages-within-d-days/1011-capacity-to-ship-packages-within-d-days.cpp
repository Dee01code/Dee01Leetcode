class Solution {		
public:
    
    int daysgo(vector<int>& wt, int w){
        int ans = 1, sum =0;
        for(auto i : wt){
            // if(sum + i > w){
            //     ans++;
            //     sum = i;
            // }
            // else if(sum + i == w){
            //     ans++;
            //     sum = 0;
            // }
            // else sum += i;
            if(sum + i > w){
                ans++;
                sum = 0;
            }
            sum += i;
        }
        return ans;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        
        while(low < high){
            
            int mid = low + (high-low)/2;
            if(daysgo(weights,mid) <= days) high = mid;
            else low = mid+1;
            
        }
        return low;
        
    }
};