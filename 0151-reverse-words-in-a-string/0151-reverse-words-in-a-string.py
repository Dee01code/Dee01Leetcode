class Solution:
    def reverseWords(self, s: str) -> str:
        ans = []
        temp = ""
        for i in s:
            if i == " ":
                if(temp != ""):
                    ans.append(temp)
                temp = ""
            else:    
                temp += i      
        if(temp != ""):
            ans.append(temp)
        s = " ".join(ans[::-1])
        return s