class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int> m;
        for(auto i: words){
            m[i]++;
        }
        
        int len = 0;
        bool centre = 0;

        for(int i=0; i<words.size(); i++){
            string ulti = words[i];
            reverse(ulti.begin(),ulti.end());
            string seedhi = words[i];
            if(seedhi == ulti && m[ulti]>1){
                len += 2;
                m[ulti] -= 2;
            }
            else if(seedhi == ulti && m[ulti] == 1){
                centre = 1;
            }
            else if(m[seedhi]>0 && m[ulti]>0){
                len += 2;
                m[seedhi]--;
                m[ulti]--;
            }
        }
        
        return (centre) ? len*2+2 : len*2; 
        
    }
};