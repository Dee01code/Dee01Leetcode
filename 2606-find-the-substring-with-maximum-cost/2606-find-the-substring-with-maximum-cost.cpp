class Solution {
public:
    int maximumCostSubstring(string s, string cs, vector<int>& vs) {
        unordered_map<char,int> m;
        int s1 = cs.size();
        int s2 = vs.size();
        for(int i = 0; i < s1; i++){
            m[cs[i]] = i;
        }
        
        int maxCost = INT_MIN;
        int i = 0;
        int temp = 0;
        while(i < s.size()){ 
            if(m.count(s[i])){
                int cost = vs[m[s[i]]];
                temp += cost;
                if(temp < 0) temp = 0 ;
            }
            else{
                temp += (s[i] - 'a') + 1;
            }
            maxCost = max(maxCost,temp);
            i++;
            cout << temp << " ";
        }
        return maxCost;
        
    }
};