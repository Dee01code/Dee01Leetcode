#define p pair<int,int> 

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        if(k >= arr.size()) return *max_element(begin(arr),end(arr));
        
        unordered_map<int,int> mp;
        
        priority_queue<p, vector<p>, greater<>> pq;
        for(int i = 0; i<arr.size(); i++) pq.push({i,arr[i]});
        
        int ind = arr.size();
        
        while(1){
            p ind0 = pq.top(); pq.pop();
            p ind1 = pq.top(); pq.pop();
            
            int num0 = ind0.second; int num1 = ind1.second;
            int i0 = ind0.first; int i1 = ind1.first;
            
            if(num0 > num1){
                mp[num0]++;
                if(mp[num0] == k) return num0;
                pq.push({ind++,num1}); 
                pq.push(ind0);
            } 
            else{
                mp[num1]++;
                if(mp[num1] == k) return num1;
                pq.push({ind++,num0}); 
                pq.push(ind1);
            }
        }        
        return 0;
    }
};