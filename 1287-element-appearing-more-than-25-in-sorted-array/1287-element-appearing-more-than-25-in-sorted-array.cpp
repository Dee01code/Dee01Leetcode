class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int per25 = n/4;
        
        int i = 0;
        while(i < n){
            int j = i+1;
            int cnt = 1;
            while(j < n && arr[i] == arr[j++]) cnt++;
            if(cnt > per25) return arr[i];
            i++;
        }
        return 0;
        
    }
};