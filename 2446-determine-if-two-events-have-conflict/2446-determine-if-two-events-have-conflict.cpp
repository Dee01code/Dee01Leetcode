class Solution
{
    public:

        int time(string s)
        {
            int ans = 0;
            for (int i = 0; i < 5; i++)
            {
                if (i == 2) continue;
                ans = ans *10 + (s[i] - '0');
            }
            return ans;
        }

    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        int st1 = time(event1[0]);
        int st2 = time(event2[0]);
        int end1 = time(event1[1]);
        int end2 = time(event2[1]);

        if ((st1 >= st2 && st1 <= end2) || (st2 >= st1 && st2 <= end1) || (end1 >= st2 && end1 <= end2) || (end2 >= st1 && end2 <= end1))
        {
            return true;
        }
        return false;
    }
};