class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int maxpro = 0;
        int mini = INT_MAX;
        
        for(int i = 0; i<prices.size(); i++){
            
            mini = min(prices[i],mini);
            maxpro = max(maxpro, prices[i]-mini);
            
        }
        return maxpro;
    }
};