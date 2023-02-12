class Solution
{
    public:
        long long findTheArrayConcVal(vector<int> &nums)
        {

            vector<string> v;
            long long ans = 0;
            for (auto i: nums)
            {
                v.push_back(to_string(i));
            }

            while (v.size() > 1)
            {

                string sum = v.front() + v.back();
                ans += stoi(sum);
                v.erase(v.begin());
                v.erase(v.end() - 1);
            }

            if (v.size() == 1)
            {
                string last = v.front();
                ans += stoi(last);
            }
            return ans;
        }
};