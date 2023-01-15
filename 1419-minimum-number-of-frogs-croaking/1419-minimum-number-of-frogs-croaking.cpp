class Solution
{
    public:
        int minNumberOfFrogs(string frog)
        {

            unordered_map<char, int> m;
            for (auto i: frog)
            {
                
                if(i == 'c'){
                    m[i]++;
                }
                else if(i=='r'){
                    
                    if(m['c']>m['r']) m[i]++;
                    else return -1;
                    
                }
                else if(i == 'o'){
                    
                    if(m['c']>m['o'] && m['r']>m['o']) m[i]++;
                    else return -1;
                    
                }
                else if(i == 'a'){
                    
                    if(m['c']>m['a'] && m['r']>m['a'] && m['o'] > m['a']) m[i]++;
                    else return -1;
                    
                }
                else{
                    
                    if(m['c']>m['k'] && m['r']>m['k'] && m['o'] > m['k'] && m['a'] > m['k']) m[i]++;
                    else return -1;
                    
                } 
            }   

            int cnt = m['c'];
            if (!(m['c'] == cnt && m['r'] == cnt && m['a'] == cnt && m['o'] == cnt && m['k'] == cnt)) return -1;

            vector<int> v(1e5 + 1, 0);
            for (int i = 0; i < frog.size(); i++)
            {
                if (frog[i] == 'c') v[i]++;
                if (frog[i] == 'k') v[i]--;
            }

            int ans = INT_MIN;
            for (int i = 1; i < 1e5 + 1; i++)
            {
                v[i] += v[i - 1];
                ans = max(ans, v[i]);
            }

            return ans;
        }
};