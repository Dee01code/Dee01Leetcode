class Solution {
    

static bool comp(vector<int> &a, vector<int> &b) {
        if(a[1] < b[1]) return 1;
        if(a[1] == b[1]) return a[0] < b[0];
        return 0;
}

    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),comp);
        int cnt = 0;
        int prev = INT_MIN;
        for(auto i : pairs){
            int a = i[0];
            int b = i[1];
            if(prev < a){
                prev = b;
                cnt++;
            }
        }
        return cnt;
        
    }
};