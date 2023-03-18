class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;
        long long score = 0;
        unordered_map<int,bool> m;
        
        vector<int> temp;
        for(int i = 0; i<n; i++){
            if(i == 0){
                p.push({nums[i],i,-1,i+1});
            }
            else if(i == n-1){
                p.push({nums[i],i,i-1,-1});
            }
            else{
                p.push({nums[i],i,i-1,i+1});
            }
        }
        
        while(!p.empty()){
            vector<int> v = p.top();
            p.pop();
            
            int ele = v[0];
            int ind = v[1];
            int left = v[2];
            int right = v[3];
            
            if(!(m.count(ind))){
                score += ele;
                if(left != -1) m[left] = 1;
                if(right != -1) m[right] = 1;
            }
        }
        
        return score;
        
    }
};