class Solution {
public:
    vector<int> vec;
     int find(int x){
         if(vec[x]==x) return x;
         return vec[x]=find(vec[x]);
     }
     void Union(int x,int y){
         x=find(x);
         y=find(y);
         if(x<y){
             vec[y]=x;
         }
         else{
             vec[x]=y;
         }
     }

    string smallestEquivalentString(string s1, string s2, string bas) {
    for(int i=0;i<26;i++){
        vec.push_back(i);
    }
    for(int i=0;i<s1.size();i++){
        int a=s1[i]-'a';
        int b=s2[i]-'a';
        Union(a,b);
    }
     string ans="";
     for(auto x:bas){
         int a=x-'a';
         a=find(a);
         char c=a+'a';
         ans+=c;
     }
     return ans;
    }
};