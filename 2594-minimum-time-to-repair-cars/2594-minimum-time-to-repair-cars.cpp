class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long high = 1e14;
        long long low = 1;
        while(low < high){
            long long mid = low + (high-low)/2;
            long long count = 0;
            for(auto i : ranks){
                count += pow(mid/i,0.5);
            }
            if(count >= cars) high = mid;
            else low = mid+1;
        }
        return low;
    }
};