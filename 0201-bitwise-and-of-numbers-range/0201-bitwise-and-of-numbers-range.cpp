class Solution
{
    public:

        int msbPos(int x)
        {
            int count = -1;
            while (x)
            {
                x >>= 1;
                count++;
            }
            return count;
        }

    int rangeBitwiseAnd(int left, int right)
    {

        int res = 0;
        while (left && right)
        {

            int msbL = msbPos(left);
            int msbR = msbPos(right);

            if (msbL != msbR) break;

            long long toAdd = 1 << msbL;
            res += toAdd;

            left -= toAdd;
            right -= toAdd;
        }
        return res;
    }
};