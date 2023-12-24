class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0;
        int ans2 = 0;
        for (int i = 0; i < s.size() - 1; i += 2) {
            if (s[i] == '1') {
                ans1++;
            } else {
			   ans2++;
			}
            if (s[i + 1] == '0') {
                ans1++;
            } else {
			  ans2++;
			}
        }
        
        if (s.size() % 2) {
            if (s.back() == '1') {
                ans1++;
            } else {
                ans2++;
            }
        }
        
        return min(ans1, ans2);
    }
};