class Solution:
    def strStr(self, given: str, need: str) -> int:
        
        if len(given) < len(need):
            return -1
        
        ind = 0 
        winL = len(need)
        win = str()
        
        for i in range(winL):
            win += given[i] 
        
        if need == win:
            return ind
        
        for i in range(winL,len(given)):
            ind += 1 
            win = win[1:] + given[i]
            if win == need:
                return ind
        return -1