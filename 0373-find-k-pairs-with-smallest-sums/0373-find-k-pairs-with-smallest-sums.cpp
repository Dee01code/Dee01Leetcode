class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto i : nums1) pq.push({i+nums2[0],0});
        
        vector<vector<int>> ans;
        
        while(k-- && !pq.empty()){
            int sum = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            ans.push_back({sum-nums2[ind],nums2[ind]});
            if(ind+1 < m){
                pq.push({sum-nums2[ind]+nums2[ind+1],ind+1});
            }
        }
        
        return ans;
    }
};
