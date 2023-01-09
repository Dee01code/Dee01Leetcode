class Solution
{
    public:
        bool detectCapitalUse(string word)
        {
            int n = word.length();
            if (n == 1) return 1;

            int i = 1;
            if (97 <= word[0] && word[0] <= 122)
            {
                while (i < n)
                {
                    if (65 <= word[i] && word[i] <= 90) return false;
                    i++;
                }
                return true;
            }
            else
            {
                i = 2;
                if (65 <= word[1] && word[1] <= 90)
                {
                    while (i < n)
                    {
                        if (97 <= word[i] && word[i] <= 122) return false;
                        i++;
                    }
                    return true;
                }
                else
                {
                    while (i < n)
                    {
                        if (65 <= word[i] && word[i] <= 90) return false;
                        i++;
                    }
                    return true;
                }
            }
        }
};