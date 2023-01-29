class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v(101,0);
        
        for(auto i : logs){
            int birth = i[0];
            int death = i[1];
            
            v[birth-1950] += 1;
            v[death-1950] -= 1;
        }
        
        int sum = 0;
        pair<int,int> ans = {0,0};
        for(int i=0; i<101; i++){
            sum += v[i];
            if(ans.first<sum){
                ans = {sum,i+1950};
            }
        }
        return ans.second;
    }
};