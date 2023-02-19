class Solution
{
    public:
        int minMaxDifference(int num)
        {

            string s = to_string(num);
            char max_dig = -1;
            if (s[0] == '9')
            {
                int i = 0;

                while (i < s.size())
                {
                    if (s[i] != '9')
                    {
                        max_dig = i;
                        break;
                    }
                    i++;
                }

                string maxi = s;
                string mini = s;

                if (max_dig == -1)
                {
                    return num;
                }

                char tomax = s[max_dig];
                char tomin = s[0];
                for (int i = 0; i < s.size(); i++)
                {

                    if (maxi[i] == tomax)
                    {
                        maxi[i] = '9';
                    }
                }

                int maxnum = stoi(maxi);

                for (int i = 0; i < s.size(); i++)
                {

                    if (mini[i] == tomin)
                    {
                        mini[i] = '0';
                    }
                }

                int minnum = stoi(mini);

                return maxnum - minnum;
            }
            else
            {

                string maxi = s;
                string mini = s;

                char tomax = s[0];
                char tomin = s[0];
                for (int i = 0; i < s.size(); i++)
                {

                    if (maxi[i] == tomax)
                    {
                        maxi[i] = '9';
                    }
                }

                int maxnum = stoi(maxi);

                for (int i = 0; i < s.size(); i++)
                {

                    if (mini[i] == tomin)
                    {
                        mini[i] = '0';
                    }
                }

                int minnum = stoi(mini);

               	// cout << maxnum << " "<< minnum;
                return maxnum - minnum;
            }
            return -1;
        }
};