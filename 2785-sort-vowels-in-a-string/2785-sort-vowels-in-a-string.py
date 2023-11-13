class Solution:
    def sortVowels(self, s: str) -> str:
        inp = list(s)
        vowels = []
        
        for i in inp:
            if i.lower() in ['a','e','i','o','u']:
                vowels.append(i) 
        
        vowels.sort()
        
        for i in range(len(inp)):
            if inp[i].lower() in ['a','e','i','o','u']:
                inp[i] = vowels[0]
                vowels.pop(0) 
                
        return ''.join(inp)
        