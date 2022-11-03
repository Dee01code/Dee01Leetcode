class Solution
{
    public:
        int maxProduct(vector<int> &a)
        {
            int n = a.size();
            int prod = 1;
            int result = INT_MIN;

            for (int i = 0; i < n; i++)
            {
                prod = prod *a[i];
                result = max(prod, result);
                if (prod == 0)
                {
                    prod = 1;
                }
            }
            prod = 1;

            for (int i = n - 1; i >= 0; i--)
            {
                prod = prod *a[i];
                result = max(prod, result);
                if (prod == 0)
                {
                    prod = 1;
                }
            }
            return result;
        }
};