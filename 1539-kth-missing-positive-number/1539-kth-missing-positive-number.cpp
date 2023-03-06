class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int s = 0;
        int end = arr.size();
        
        while(s < end){
            int mid = s + (end-s)/2;
            int last = arr[mid];
            int miss = last - (mid+1);
            if(k <= miss) end = mid;
            else s = mid+1;
            
        }
        return s+k;
    }
};