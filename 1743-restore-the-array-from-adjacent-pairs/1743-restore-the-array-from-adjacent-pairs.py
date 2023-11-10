class Solution:
    def restoreArray(self, ap: List[List[int]]) -> List[int]:
        
        ans = list()
        mp = dict()
        
        for i in ap:
            one, two = i[0], i[1]
            mp.setdefault(one,[]).append(two)
            mp.setdefault(two,[]).append(one) 
            
        
        st, prev = 0, 0
        # print(mp)
        for k,v in mp.items():
            if len(v) == 1:
                st = k 
                break 
        
        ans.append(st)
        prev = st 
        st = mp[st][0] 
        
        while len(mp[st]) != 1:
            ans.append(st)
            tot = sum(mp[st])
            nxt = tot-prev 
            prev = st 
            st = nxt 
        
        ans.append(st)
        return ans
            
        