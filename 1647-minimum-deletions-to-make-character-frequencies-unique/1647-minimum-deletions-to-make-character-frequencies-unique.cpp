class Solution {
public:
    int minDeletions(string st) {
        unordered_map<char,int> mp;
        int maxi = INT_MIN;
        
        for(auto i : st){
            mp[i]++;
            maxi = (mp[i] > maxi) ? mp[i] : maxi; 
        }
        
        vector<int> cnt(maxi+2,0);
        for(auto i : mp){
            cnt[i.second]++;
        }
        
        stack<int> s;
        int ans = 0;
        for(int i = 1; i<cnt.size(); i++){
            if(cnt[i] == 1) continue;
            if(cnt[i] == 0) s.push(i);
            else{
                if(s.empty()){
                    ans += i*(cnt[i]-1);
                }
                else{
                    while(!s.empty() && cnt[i] != 1){
                        int prevEmpty = s.top();
                        ans += i-prevEmpty;
                        cnt[i]--;
                        s.pop();
                    }
                    if(cnt[i] != 1){
                        ans += i*(cnt[i]-1);
                    }
                }
            }
        }
        return ans;
    }
};