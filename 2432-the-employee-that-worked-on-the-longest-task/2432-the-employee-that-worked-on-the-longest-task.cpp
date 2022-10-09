class Solution
{
    public:
        int hardestWorker(int n, vector<vector < int>> &logs)
        {
            int ansid = logs[0][0];
            int maxTime = logs[0][1];
            int size = logs.size();
           	// cout << maxTime << endl;
            for (int i = 1; i < size; i++)
            {
                int curtime = logs[i][1] - logs[i - 1][1];
                if (maxTime <= curtime)
                {
                    ansid = (maxTime == curtime && (ansid < logs[i][0])) ? ansid : logs[i][0];
                    maxTime = curtime;
                   	// cout << maxTime;
                }
            }
            return ansid;
        }
};