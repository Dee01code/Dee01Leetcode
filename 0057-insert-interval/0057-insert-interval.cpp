class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& nin) {
        
        vector<vector<int>> temp;
        int i = 0;
        while(i<in.size()){
            if(in[i][0] >= nin[0]) break;
            temp.push_back(in[i]);
            i++;
        }
        
        temp.push_back(nin);
        
        while(i<in.size()){
            temp.push_back(in[i]);
            i++;
        }
        
        vector<vector<int>> ans;
        ans.push_back(temp[0]);
        for(int i=1; i<temp.size();i++){
            int lastend = ans.back()[1];
            int newst = temp[i][0];
            int newend = temp[i][1];
            if(lastend >= newst) ans.back()[1] = max(lastend,newend);
            else ans.push_back(temp[i]);
        }
        return ans;
        
    }
};