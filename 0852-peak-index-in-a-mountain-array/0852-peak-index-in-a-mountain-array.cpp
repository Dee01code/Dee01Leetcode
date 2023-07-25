class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int s = 0;
        int end = arr.size()-1;
        
        while(s < end){
            int mid = s - (s-end)/2;
            if(arr[mid] < arr[mid+1]) s = mid+1;
            else end = mid;
        }
        
        return s;
        
    }
};