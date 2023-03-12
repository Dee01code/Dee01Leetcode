class Solution {
public:
    int maxScore(vector<int>& nums) {
        long long ans = 0;
        
        map<int,int> m;
        int cnt = 0;
        
        for(auto i : nums){
            if(i>0){
                ans+=i;
                cnt++;
            }
            else m[i]++;
        }
        
        for(auto i = m.rbegin(); i != m.rend(); i++){
            int val = i->first;
            int freq = i->second;
            while(freq--){
                ans += val;
                if(ans<=0) return cnt;
                cnt++;
    
            }
        }
        return cnt;
        
    }
};