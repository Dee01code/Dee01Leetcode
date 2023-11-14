class Solution:
    def findHighAccessEmployees(self, acc: List[List[str]]) -> List[str]:
        
        mp = defaultdict(list) 
        
        for i in acc:
            mp[i[0]].append(int(i[1]))
        
        ans = set()
        
        for k,v in mp.items():
            if len(v)<3:
                continue
            else:
                v.sort()
                print(k,v)
                for i in range(2,len(v)):
                    
                    a = v[i-2]
                    b = v[i-1]
                    c = v[i]
                    
                    if c-a < 100:
                        ans.add(k)
        return list(ans)
        