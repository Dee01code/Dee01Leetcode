class Solution {
public:
    int garbageCollection(vector<string>& nums, vector<int>& travel) {
        
        int ans = 0;
        
        //Paper
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            // string& s = gar[i];
            int cnt = 0;
            for(auto& j : nums[i]){
                if(j == 'P') cnt++;
            }
            if(cnt != 0) ans += temp+cnt, temp = 0;
            if(i != nums.size()-1) temp += travel[i];
        }
        
        //Glass
        temp = 0;
        for(int i = 0; i < nums.size(); i++){
            // string& s = gar[i];
            int cnt = 0;
            for(auto& j : nums[i]){
                if(j == 'G') cnt++;
            }
            if(cnt != 0) ans += temp+cnt, temp = 0;
            if(i != nums.size()-1) temp += travel[i];
        }
        
        //Metal
        temp = 0;
        for(int i = 0; i < nums.size(); i++){
            // string& s = gar[i];
            int cnt = 0;
            for(auto& j : nums[i]){
                if(j == 'M') cnt++;
            }
            if(cnt != 0) ans += temp+cnt, temp = 0;
            if(i != nums.size()-1) temp += travel[i];
        }
        
        return ans;
        
    }
};