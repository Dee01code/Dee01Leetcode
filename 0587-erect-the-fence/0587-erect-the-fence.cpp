bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

// lt stands for Left turn and rt stands for a Right turn
// Used vectors of size 2 to store the points (x,y)
// left turn means the middle point of three sorted points is below the line joining 1st and 3rd point(draw urself to get better picture) 
// Viceversa goes for right turn

struct Hull {
    bool lt(vector<int> &a, vector<int> &b, vector<int> &c) {
        return (a[0] * (b[1] - c[1])) + (b[0] * (c[1] - a[1])) + (c[0] * (a[1] - b[1])) > 0;
    }

    bool rt(vector<int> &a, vector<int> &b, vector<int> &c) {
        return (a[0] * (b[1] - c[1])) + (b[0] * (c[1] - a[1])) + (c[0] * (a[1] - b[1])) < 0;
    }

    void convexHull(vector<vector<int>> &points) {
        deque<vector<int>> up, down;
        vector<int> &st = points[0], &en = points.back();
        up.push_back(st), down.push_back(st);

        for (int i = 1; i < points.size(); i++) {
            vector<int> &p = points[i];
            if (!lt(st, p, en)) {
                while (up.size() > 1 and lt(up[up.size() - 2], up.back(), p))
                    up.pop_back();
                up.push_back(p);
            }
            if (!rt(st, p, en)) {
                while (down.size() > 1 and rt(down[down.size() - 2], down.back(), p))
                    down.pop_back();
                down.push_back(p);
            }
        }

        points.clear();
        for (vector<int> &p : up)
            points.push_back(p);
        for (vector<int> &p : down)
            points.push_back(p);

        sort(points.begin(), points.end(), cmp);
        points.resize(unique(points.begin(), points.end()) - points.begin());
    }
};

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), cmp);
        Hull h;
        h.convexHull(points);
        return points;
    }
};