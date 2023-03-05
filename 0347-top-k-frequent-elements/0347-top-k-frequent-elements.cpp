class Solution {
public:
    
    static bool comp(pair<int,int>& a, pair<int,int>& b){
        return a.first > b.first;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<pair<int,int>> v;
        vector<int> ans;
        
        unordered_map<int,int> m;
        for(auto i : nums) m[i]++;
        
        for(auto i : m){
            v.push_back({i.second,i.first});
        }
        
        nth_element(v.begin(),v.begin()+k-1, v.end(), comp);
        
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        
        return ans;
    }
};