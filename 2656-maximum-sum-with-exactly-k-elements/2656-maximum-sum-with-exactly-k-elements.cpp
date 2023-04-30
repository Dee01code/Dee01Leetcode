class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        int score = 0;
        priority_queue<int> p(nums.begin(),nums.end());
        while(k--){
            int m = p.top();
            p.pop();
            p.push(m+1);
            score += m;
        }
        return score;
        
    }
};