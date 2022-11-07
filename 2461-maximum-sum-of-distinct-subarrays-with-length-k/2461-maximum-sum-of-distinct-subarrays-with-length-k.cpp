class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        
        unordered_map<int, int> m;
        long long sum = 0;
        long long ans = 0;
        
        int i = 0;
        
        while(i < k && i<arr.size()){
            m[arr[i]]++;
            sum += arr[i];
            i++;
        }
        
        if(m.size()==k) ans = sum;
        
        while(i < arr.size()){
            m[arr[i]]++;
            m[arr[i-k]]--;
            
            if(m[arr[i-k]] == 0) m.erase(arr[i-k]);
            
            sum += arr[i];
            sum -= arr[i-k];
            if(m.size() == k) ans = max(ans,sum);
            i++;
        }
        
        return ans;
    }
};