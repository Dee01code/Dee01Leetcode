class Solution {
public:
    int ans=INT_MAX,k;
    void func(vector<int>&cookies,vector<int> &ppl,int index){
        if(index==cookies.size()){
            ans=min(ans,*max_element(begin(ppl),end(ppl)));
            return;
        }
        for(int i=0;i<k;i++){
            ppl[i]+=cookies[index];
            func(cookies,ppl,index+1);
            ppl[i]-=cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        this->k=k;
        vector<int>ppl(k,0);
        func(cookies,ppl,0);
        return ans;
    }
};