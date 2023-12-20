class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices), end(prices));
        int tot = prices[0]+prices[1];
        return (money-tot >= 0) ? money-tot : money; 
    }
};