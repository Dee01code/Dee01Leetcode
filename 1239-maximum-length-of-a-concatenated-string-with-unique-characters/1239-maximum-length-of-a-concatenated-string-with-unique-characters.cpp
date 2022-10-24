class Solution {
public:
    int maxlen = 0;
    void backtrack(vector<int>& maskArr, vector<int>& sizeArr, int mask, int len, int pos) {
      if (pos == maskArr.size()) {
        maxlen = max(len, maxlen);
        return;
      }
      backtrack(maskArr, sizeArr, mask, len, pos + 1);
      if ((mask & maskArr[pos]) == 0) {
        backtrack(maskArr, sizeArr, mask | maskArr[pos], len + sizeArr[pos], pos + 1);
      }
    }

    int maxLength(vector<string>& arr) {
        vector<int> maskArr;
        vector<int> sizeArr;
        int i;
        for (i = 0; i < arr.size(); i++) {
            string s = arr[i];
            int mask = 0;
            for (char c : s) {
                if (mask & (1 << (c - 'a'))){
                    mask = -1;
                    break;
                }
                mask |= (1 << (c - 'a'));
            }
            if (mask == -1)
                continue;
            maskArr.push_back(mask);
            sizeArr.push_back(s.size());
        }
        backtrack(maskArr, sizeArr, 0, 0, 0);
        return maxlen;
    }
};