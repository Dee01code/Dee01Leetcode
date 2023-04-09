class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        unordered_map<int,vector<int>> m;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            m[nums[i]].push_back(i);
        }
        
        vector<long long> arr(n,0);
        
        for(auto ind : m){
            vector<int> temp = ind.second;
            int len = temp.size();
 
            if(len > 1){
                
                vector<long long int> prefix(len,0);
                prefix[0] = temp[0];
                
                for(int i = 1; i<len; i++){
                    prefix[i] = prefix[i-1] + temp[i];
                }
                
                long long int sum1 = 0;
                long long int sum2 = 0;
                for(int i = 0; i<len; i++){
                    sum1 = 0;
                    sum2 = 0;
                    int index = temp[i];
                    long long int presum = prefix[i]-index;
                    long long int postsum = prefix[len-1]-prefix[i]; 
                    int preLen = i;
                    int postLen = len - i - 1;
                    
                    long long int pre1 = index;
                    pre1 *= preLen;
                    long long int post2 =  index;
                    post2 *= postLen;
                        
                    if(preLen > 0) sum1 += pre1-presum; 
                    if(postLen > 0) sum2 += postsum - post2; 
                    
                    arr[index] += sum1; 
                    arr[index] += sum2;
                }
            }
            else arr[temp[0]] = 0;
            
        }
        return arr;
    }
};