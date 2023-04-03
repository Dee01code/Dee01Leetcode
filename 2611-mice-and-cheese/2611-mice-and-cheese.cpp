class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        
        unordered_map<int,int> m;
        priority_queue<vector<int>> p; 
        int n = r1.size();
        for(int i = 0; i<n; i++){
            p.push({r1[i]-r2[i],i});
        }
        
        while(k--){
            vector<int> temp = p.top();
            p.pop();
            m[temp[1]]++;
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(m.count(i)){
                ans += r1[i];
            }
            else ans += r2[i];
        }
        return ans;
        // map<int,vector<int>> m;
        // for(int i = 0; i<r1.size(); i++){
        //     m[r1[i]].push_back(i);
        // }
        // int ans = 0;
        // vector<int> notUse;
        // while(k--){
        //     for(auto i = m.rbegin(); i != m.rend(); i++){
        //         vector<int> ind = i->second;
        //         int j = 0;
        //         while(k>0 && j < ind.size()){
        //             ans += i->first;
        //             k--;
        //             notUse.push_back(ind[j]); 
        //             j++;
        //         }
//         //     }
//         // }
//         int n = r1.size();
//         int totr2 = 0;
//         int ans = INT_MIN;
//         for(auto i : r2) totr2 += i;
//         cout << "TotSum in r2 "<<totr2 << endl;
//         int winSum1 = 0, winSum2 = 0;
//         int  i = 0;
//         while(i<k){
//             winSum1 += r1[i];
//             winSum2 += r2[i];
//             i++;
//         }
//         int temp = 0;
//         temp = totr2 - winSum2 + winSum1;
//         ans = max(ans,temp);
//         cout << "Window 1 sum = " << temp<<endl;
//         cout << i << endl;
//         for(; i < n; i++){
//             cout << "Number befor window = " <<r1[i-k];
//             cout << " Number after window = " <<r1[i];
//             winSum1 -= r1[i-k];
//             winSum1 += r1[i];
            
//             winSum2 -= r2[i-k];
//             winSum2 += r2[i];
            
//             temp = totr2 - winSum2 + winSum1;
//             ans = max(ans,temp);
//             cout << " winSum1 = " << winSum1 << endl;
//             cout << " winSum2 = " << winSum2 << endl;
            
//             cout << "Window sum = " << temp<<endl;
//         }
//         return ans;
    }
};