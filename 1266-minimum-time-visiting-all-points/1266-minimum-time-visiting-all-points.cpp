class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(auto i = 1; i<points.size(); i++){
            
            int x2 = points[i][0];
            int y2 = points[i][1];
            int x1 = points[i-1][0];
            int y1 = points[i-1][1];
            
            res += (abs(x2-x1) >= abs(y2-y1)) ? abs(x2-x1) : abs(y2-y1);
        }
        return res;
    }
};