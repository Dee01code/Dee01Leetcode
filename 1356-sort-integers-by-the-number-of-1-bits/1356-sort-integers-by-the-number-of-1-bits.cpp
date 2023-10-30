class Solution {
public:
    
    static int count1s(int a){
        int cnt=0;
        while(a){
            a = a&(a-1);
            cnt++;
        }
        return cnt;
    }
    
    static bool comp(int a, int b){
        int p = count1s(a);
        int q = count1s(b);
        if(p==q) return(a<=b);
        return (p<q);    
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};