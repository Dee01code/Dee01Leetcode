class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue pq(nums.begin(), nums.begin()+k, greater<int>());
        for(int i = k; i<nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};