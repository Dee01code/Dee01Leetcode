class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& div) {
        int score = INT_MIN;
        int num = INT_MAX;
        
        for(auto i : div){
            int cnt = 0;
            for(auto j : nums){
                if(j%i == 0) cnt++;
            }
            cout << "Number divisible by " << i <<" is " << cnt<<endl;
            if(score == cnt){
                cout << "equality for " << i << endl;
                num = min(num,i);
            }
            if(score < cnt){
                score = cnt;
                cout << "Not equality for " << i << endl;
                num = i;
            }

        }
        return num;
    }
};