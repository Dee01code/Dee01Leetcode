class Solution {
    #define ll long long
public:
    int minimizeArrayValue(vector<int>& v) {
        int n=v.size();
        ll i=0,j=10000000000;
        ll ans=j;
        while(i<=j){
            ll m=(i+j)/2;
            ll ex=0;
            for(int i=n-1;i>=0;i--){
              if(v[i]>m){
                  ex += v[i]-m;
              }
              else {
                  ll need=m-v[i];
                  ex -= min(ex,need);
              }
            }
            if(ex){
                i=m+1;
            }
            else {
                ans=m;
                j=m-1;
            }
        }
        return ans;
    }
};