class Solution {
public:
// Declaring the global variables so that we don't have to initialize them //everytime.
    int ans=0,maxi=0;
// Creating an unordered map to store the list of employees that a manager is head of.
unordered_map<int,vector<int>> map;

int solve(int manager, vector<int> &informTime){
        maxi=max(ans,maxi);
        for(auto employee:map[manager]){
            ans+=informTime[manager];
            solve(employee,informTime);
            //backtracking when we haven't reached end.
			ans-=informTime[manager];
        }
        return maxi;
}
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    for(int i=0;i<n;i++){
    int val=manager[i];
        map[val].push_back(i);
    }
        return solve(headID,informTime);
    }
};