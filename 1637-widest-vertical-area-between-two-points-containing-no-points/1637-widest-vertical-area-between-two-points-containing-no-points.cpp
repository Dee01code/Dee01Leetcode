class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& pts) {
        
        int n = pts.size();
        
        sort(begin(pts), end(pts));
        
        int ans = INT_MIN;
        
        for(int i = 1; i < n; i++){
            ans = max(abs(pts[i][0]-pts[i-1][0]),ans);
        }
        return ans;
    }
};