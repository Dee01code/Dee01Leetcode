class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b){
        //    return a[0]<b[0]; 
        // });
        
        vector<int> v(1e6+2,0);
        for(auto i : intervals){
            v[i[0]]++;
            v[i[1]+1]--;
        }
        
        int ans = INT_MIN;
        
        for(int i=1; i<1e6+2; i++){
            v[i] += v[i-1];
            ans = max(ans,v[i]);
        }
        return ans;
        
    }
};