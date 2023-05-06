class Solution {
public:
    int maxVowels(string s, int k) {
        int vow = 0;
        int ans = INT_MIN;
        int i = 0, j = 0;
        while(j<k){
        
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') vow++;
            j++;

        }
        ans = max(ans,vow);
        while(j < s.size()){

            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                vow++;
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                vow--;
            
            i++;
            j++;

            ans = max(ans,vow);
        }
        return ans;
    }
};