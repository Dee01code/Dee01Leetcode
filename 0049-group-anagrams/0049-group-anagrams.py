class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        n = len(strs)
        maps = dict()
        for i in range(n):
            temp = ''.join(sorted(strs[i]))
            maps[temp] = [] 
        for i in range(n):
            temp = ''.join(sorted(strs[i]))
            maps[temp].append(strs[i])
        ans = []
        return list(maps.values())
            
        