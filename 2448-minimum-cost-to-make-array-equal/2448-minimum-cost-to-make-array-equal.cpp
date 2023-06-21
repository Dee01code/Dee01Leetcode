class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
    	int n = nums.size();
    	vector<pair<int, int>>arr(n);
    	for(int i = 0; i < n; i++)
    		arr[i] = {nums[i], cost[i]};
    	sort(arr.begin(), arr.end());

    	vector<long long>pre(n);
    	pre[0] = 0;
    	long long base = arr[0].second;
    	for(int i = 1; i < n; i++) {
    		pre[i] = pre[i - 1] + base * (arr[i].first - arr[i - 1].first);
    		base += arr[i].second;
  
    	}
    	
    	vector<long long>post(n);
    	post[n - 1] = 0;
    	base = arr[n - 1].second;
    	for(int i = n - 2; i >= 0; i--) {
    		post[i] = post[i + 1] + base * (arr[i + 1].first - arr[i].first);
    		base += arr[i].second;

    	}
    	
    	long long ans = post[0];
    	for(int i = 0; i < n; i++)
    		ans = min(ans, pre[i] + post[i]);
    	return ans;
    }
};