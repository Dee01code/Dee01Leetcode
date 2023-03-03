class Solution {
public:
    int strStr(string h, string needle) {
        
        int len = needle.size();
        
        if(len > h.size()) return -1;
            
        for(int i=0; i <= h.size()-len; i++){
            
            string temp = h.substr(i,len);
            if(temp == needle) return i;
            
        }
        return -1;
    }
};