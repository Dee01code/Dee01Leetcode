class Solution:
    def numBusesToDestination(self, routes: List[List[int]], src: int, tar: int) -> int:
        if src == tar:
            return 0 
        
        mp = dict()
        
        for bus in range(len(routes)):
            for stop in routes[bus]:
                mp.setdefault(stop,[]).append(bus)
        
        queue = []
        visit = [0 for i in range(501)]
        
        for stBus in mp[src]:
            queue.append(stBus)
            visit[stBus] = 1 
        
        ans = 1
        
        while len(queue) != 0:
            cnt = len(queue)
            while cnt != 0:
                cnt -= 1
                
                bus = queue[0]
                queue.pop(0)
                
                for stop in routes[bus]:
                    
                    if stop == tar:
                        return ans 
                    
                    for busNo in mp[stop]:
                        if visit[busNo] == 0:
                            queue.append(busNo)
                            visit[busNo] = 1 
            ans += 1
                

        return -1
        
# if(src==tar) return 0;
        
#         unordered_map<int,vector<int>> mp;
        
#         for(int i = 0; i<routes.size(); i++){
#             for(auto & stop : routes[i]) mp[stop].push_back(i);
#         }
        
#         queue<int> q;
#         vector<int> visited(501,0);
        
#         for(auto & st : mp[src]){
#             visited[st] = 1;
#             q.push(st);
#         }
        
#         int ans = 1;
        
#         while(!q.empty()){
#             int len = q.size();
#             while(len--){
#                 int ind = q.front();
#                 q.pop();
#                 for(auto& cur : routes[ind]){
#                     if(cur == tar) return ans;
                    
#                     for(auto& stop : mp[cur]){
#                         if(!visited[stop]){
#                             visited[stop] = 1;
#                             q.push(stop);
#                         }
#                     }
                    
#                 }
#             }
#             ans++;
#         }
#         return -1;