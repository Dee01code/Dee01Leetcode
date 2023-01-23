class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(n>1 && trust.empty()) return -1;
        
        unordered_map<int, vector<int>> m;
        unordered_set<int> s;
        int sum = (n*(n+1))/2;
        for(auto i : trust){
            m[i[0]].push_back(i[1]);
            s.insert(i[0]);
        }
        
        sum -= accumulate(s.begin(),s.end(),0);
        if(sum==0) return -1;
        
        for(auto i : m){
            vector<int> v = i.second;
            if(find(v.begin(),v.end(),sum) != v.end()){
                continue;
            }
            return -1;
        }
        return sum;
    }
};