class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       
        if(s1.size() > s2.size()) return false;
        
        vector<int> v(26,0);
        for(auto i : s1){
            v[i-'a']++;
        }
        // for(auto i:v){
        //     cout << i;
        // }
        // cout << endl;
        
        
        int winSize = s1.size();
        
        vector<int> window(26,0);
        for(int i = 0; i < winSize; i++){
            window[s2[i]-'a']++;
            if(v == window) return true;
        }
        
        for(int i=1; i <= s2.size()-winSize; i++){
            window[s2[i-1]-'a']--;
            window[s2[i+winSize-1]-'a']++;
            if(v == window) return true;
            
            // for(auto i : window){
            //     cout << i ;
            // }
            // cout << endl;
        }
        return false;
    }
};