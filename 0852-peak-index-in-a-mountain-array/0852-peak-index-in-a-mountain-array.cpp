class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int s = 0;
        int e = arr.size()-1;
        while(s<e){
            
            int mid = s+(e-s)/2;
            
            if(mid+1 < arr.size() && mid-1 >=0 && arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) return mid;
            
            if(arr[mid] < arr[mid+1]) s = mid+1;
            if(arr[mid] > arr[mid+1]) e = mid-1;
            
            
        }
        return s;
        
        
    }
};