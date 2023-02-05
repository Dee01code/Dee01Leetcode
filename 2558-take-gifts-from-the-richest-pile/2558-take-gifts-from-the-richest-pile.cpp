class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> p;
        for(auto i : gifts){
            p.push(i);
        }
        long long ans= 0;
        while(k--){
            int ans = sqrt(p.top());
            p.pop();
            p.push(ans);
        }
        
        while(!p.empty()){
            cout << p.top() << " ";
            ans += p.top();
            p.pop();
        }
        return ans;
    }
};