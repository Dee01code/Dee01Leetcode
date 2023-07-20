class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        int num = 0;
        for(int i = 0; i<a.size(); i++){
            num = a[i];
            if(num > 0){
                s.push(num);
                num = 0;
            }
            else{
                if(s.empty()) {s.push(num); num = 0;}
                else if(s.top() < 0) {s.push(num); num = 0;}
                else{
                    while(!s.empty() && num < 0 && s.top() > 0){
                        if(abs(num) > s.top()){
                            s.pop();
                        }
                        else if(abs(num) == s.top()){
                            s.pop();
                            num = 0;
                        }
                        else{
                            num = 0;
                        }
                    }
                    if((s.empty() && num != 0) || (!s.empty() && s.top()<0 && num != 0)) s.push(num);
                }
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        if(ans.size()>1)
            reverse(ans.begin(),ans.end());
        return ans;
    }
};