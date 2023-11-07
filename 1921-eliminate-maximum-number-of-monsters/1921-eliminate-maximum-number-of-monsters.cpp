class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int>  counts(n+1,0); 
        for(int i=0; i<n; i++){
            int ind = ceil(dist[i]*1.0/speed[i]);
            if(ind >n-1) ind = n; 
            counts[ind]++;
        }
        int curr = 0;
        for(int i=1; i<=n; i++){
            curr += counts[i]; 
            if(curr>i) return i; 
        }
        return n;
    }
};