class Solution
{
    public:
        bool isPrime(int n)
        {
           	// Corner cases
            if (n <= 1)
                return false;
           	//suppose n=7 that is prime and its pair are (1,7)
           	//so if a no. is prime then it can be check by numbers smaller than square root
           	// of the n
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                    return false;
            }
            return true;
        }

    int diagonalPrime(vector<vector < int>> &nums)
    {

        int row = nums.size();
        int col = nums[0].size();

        int prime = 0;

        for (int r = 0; r < row; r++)
        {
            int num1 = nums[r][r];
            int num2 = nums[r][row - r - 1];

            if (isPrime(num1)) prime = max(prime, num1);
            if (isPrime(num2)) prime = max(prime, num2);
        }
        return prime;
    }
};