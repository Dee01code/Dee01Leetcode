class Solution {
public:
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    
    
    vector<int>blue[n];
    vector<int>red[n];
    
    for(auto it:redEdges)
    {
        red[it[0]].push_back(it[1]);
    }
    
       
    for(auto it:blueEdges)
    {
        blue[it[0]].push_back(it[1]);
    }
    
    vector<pair<int,int>>res(n,{INT_MAX,INT_MAX});//minimum dist to reach node through blue color,red color
    
    res[0]={0,0};
    
    queue<pair<int,int>>q;
    
    q.push({0,-1});//for red
    q.push({0,1});//for blue
    
    int currdist=0;
    
    while(!q.empty())
    {
        
        int size=q.size();
        
       for(int i=0;i<size;i++)
       {
           
            auto it=q.front();
            q.pop();
            
            int node=it.first;
        
            int edge=it.second;
           
           if(edge==1)// if edge is blue traverse adj list of blue edges
           {
               
               for(auto x:blue[node])
               {
                   
                   if(res[x].second>currdist+1)
                   {
                       
                       res[x].second=currdist+1;
                       
                       q.push({x,-1});
                   }
               }
           }
           
           
           else// edge is red so traversing adj list of red edges
           {
               
                for(auto x:red[node])
               {
                   
                   if(res[x].first>currdist+1)
                   {
                       
                       res[x].first=currdist+1;
                       
                       q.push({x,1});
                   }
               }
               
               
           }
        
       }
        currdist++;
    }
    
    vector<int>ans(n,0);
    for(int i=0;i<n;i++)
    {
        
        int mini=min(res[i].first,res[i].second);
        
        if(mini==INT_MAX)
        {
            ans[i]=-1;
        }
        
        
        else
        {
            ans[i]=mini;
        }
    }
    
    return ans;
}
};