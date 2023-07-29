class Solution {
public:
    map<pair<int, int>, double> map;
    double soupServings(int n) {
        if (n >= 4800) return 1;
        return f(n, n);
    }
    double f(int a, int b){
        if(a<=0 && b>0)return 1.0;
        if(a<=0 && b <=0) return 0.5;
        if(a>0 && b<= 0)return 0;
        if(map.find({a, b}) != map.end())return map[{a,b}];
        map[{a, b}] = 0.25*(f(a-100,b) + f(a-75,b-25) + f(a-50,b-50) + f(a-25, b-75));
        return map[{a, b}];
    }
};