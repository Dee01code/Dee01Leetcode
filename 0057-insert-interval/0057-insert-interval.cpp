// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newInterval) {
         
//         vector<<vector<int>>> ans;
        
//         int newst = newInterval[0];
//         int newend = newInterval[1];
        
//         for(int i = 0; i<in.size(); i++){
            
//             int st = in[i][0];
//             int end = in[i][1];
            
//             if(newst < st && newend < st){
                
//             }
            
//             else if(newst < st && newend <= end){
                
//             }
            
//             else if(newst >= st && newend <= end){
                
//             }
//             else if(newst >= st && newst <= end && newend > end){
                
//             }
            
//         }
        
        
//     }
// };
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        int n = intervals.size(), i = 0;
        // push all the intervals till non overlapping interval
        while(i < n && newInterval[0] > intervals[i][1])
        {
            v.push_back(intervals[i]);
            i++;
        }
        // merging all the overlapping intervals
        while(i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        v.push_back(newInterval);
        // psuh all the remaining intervals after merging 
        while(i < n)
        {
            v.push_back(intervals[i]);
            i++;
        }
        return v;
    }
};