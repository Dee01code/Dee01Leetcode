class Solution {
public:
    void dfs(int i,vector<int>adj[],set<int> &st,set<int> &ans){
        st.insert(i);
        for(auto x:adj[i]){
            if(ans.find(x)!=ans.end()){
                int num=*ans.lower_bound(x);
                ans.erase(num);
            }
            else if(st.find(x)==st.end()){
                st.insert(x);
                dfs(x,adj,st,ans);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int>st;
        vector<int>adj[n+1];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
        }
        set<int>ans;
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end()){
                ans.insert(i);
                dfs(i,adj,st,ans);
            }
        }
        for(auto x:ans){
            cout<<x<<" ";
        }cout<<endl;
        vector<int>res;
        for(auto x:ans){
            res.push_back(x);
        }return res;
    }
};