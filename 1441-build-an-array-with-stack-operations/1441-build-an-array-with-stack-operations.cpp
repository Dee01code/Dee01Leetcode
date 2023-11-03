class Solution {
public:
    const vector<string> v = {"Push","Pop"};
    
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int ptr = 1;
        for(auto i : target){
            int cnt = 0;
            while(i != ptr){
                ans.emplace_back(v[0]);
                ptr++, cnt++;
            }
            while(cnt--) ans.emplace_back(v[1]);
            ans.emplace_back(v[0]), ptr++;
        }
        return ans;
    }
};