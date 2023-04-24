class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        
        int n = s.size();
        priority_queue<int> p;
        for(auto i : s) p.push(i);
        while(p.size() > 1){
            int x = p.top();
            p.pop();
            int y = p.top();
            p.pop();
            if(x!=y){
                p.push(abs(x-y));
            }
        }
        if(p.size()==0) return 0;
        return p.top();
    }
};