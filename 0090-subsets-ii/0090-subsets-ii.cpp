class Solution {
private:
    void solve(int ind, vector<int> arr, vector<int> sub, vector<vector<int>> &ans){
        // if(ind==arr.size()){
        //     ans.push_back(sub);
        //     return;
        // }       
        ans.push_back(sub);

        for(int i = ind; i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            sub.push_back(arr[i]);
            solve(i+1,arr,sub,ans); 
            sub.pop_back();
            // solve(i+1,arr,sub,ans);    
        }
        return;
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        solve(0,nums,sub,ans);
        return ans;
    }
};