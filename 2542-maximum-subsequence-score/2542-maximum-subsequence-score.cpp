typedef pair<int, int> pi;
class Solution
{
    public:
        long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
        {

            priority_queue<int, vector < int>, greater<int>> pq;

            int n = nums1.size();

            vector<pi> v;
            for (int i = 0; i < n; i++)
            {
                v.push_back({ nums2[i],
                    nums1[i] });
            }

            sort(v.rbegin(), v.rend());

            long long ans = 0;
            long long sum = 0;
            for (int i = 0; i < k; i++)
            {
                sum += v[i].second;
                pq.push(v[i].second);
            }
            ans = sum *v[k - 1].first;

            for (int i = k; i < n; i++)
            {

                sum -= pq.top();
                pq.pop();

                pq.push(v[i].second);
                sum += v[i].second;
                ans = max(sum *v[i].first, ans);
            }
            return ans;
        }
};