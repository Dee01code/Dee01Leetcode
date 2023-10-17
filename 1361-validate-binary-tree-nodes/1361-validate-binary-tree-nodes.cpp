class Solution {
public:
    
    int component;
    vector<int> parent;
    
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    bool join(int par, int child){
        
        if(findParent(child) != child) return false;
        
        if(findParent(par) == child) return false;
            
        parent[child] = par;
        component -= 1;
        
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        
        // Using DSU
            
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
        
        component = n;
        
        for(int i = 0; i<n; i++){
            
            int lc = left[i];
            int rc = right[i];
            
            if(lc != -1 && join(i,lc) == 0) return 0;
            if(rc != -1 && join(i,rc) == 0) return 0;  
        }
        
        if(component != 1) return 0;
        return 1;
        
//         // 1. node can have only single parent
//         // 2. only one root i.e. More than 1 component will not be acceptable
//         // 3. node visited count at last should be equal to n.
        
//         unordered_map<int,int> CtoP;
//         unordered_map<int,vector<int>> adj;
        
//         for(int i = 0; i<n; i++){
//             int lc = left[i];
//             int rc = right[i];
            
//             if(lc != -1){
                
//                 //using 1st cond
//                 cout << "Lc" << endl;
//                 if(CtoP.count(lc)) return false;
                
//                 adj[i].push_back(lc);
//                 CtoP[lc] = i;
//             }
//             if(rc != -1){
            
//                 //using 1st cond
//                 cout << "Lc" << endl;
//                 if(CtoP.count(rc)) return false;
                
//                 adj[i].push_back(rc);
//                 CtoP[rc] = i;
//             }
//         }
        
//         int root = -1;
//         for(int i = 0; i<n; i++){
//             if(CtoP.count(i) == 0){
                
//                 //using 3rd condition
//                 cout << "Root" << endl;
//                 if(root != -1) return false;
                
//                 root = i;
//             }
//         }
        
//         if(root == -1) return false;
        
//         queue<int> q;
//         vector<int> marked(n,0);
//         q.push(root);
//         int cnt = 0;
        
//         while(!q.empty()){
            
//             int len = q.size();
//             int node = q.front();
//             q.pop();
            
//             while(len--){
//                 if(!marked[node]){
//                     for(auto i : adj[node]) q.push(i);
//                     marked[node] = 1;
//                     cnt++;
//                 }
//             }
//         }
        
//         cout << "End" << endl;
//         if(cnt != n) return false;
//         return true;
        
    }
};