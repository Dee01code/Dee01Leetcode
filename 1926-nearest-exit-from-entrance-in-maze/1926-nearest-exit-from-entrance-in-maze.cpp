class Solution
{
    public:
        int nearestExit(vector<vector < char>> &maze, vector< int > &entrance)
        {
            queue<vector < int>> q;
            q.push({ entrance[0],
                entrance[1] });
            int c = 0, m = maze.size(), n = maze[0].size();
            while (!q.empty())
            {
                int size = q.size();
                while (size--)
                {
                    auto k = q.front();
                    q.pop();
                    if (maze[k[0]][k[1]] == '+')	// If obstacle is encountered or current cell is visited
                        continue;
                    if (k != entrance && (k[0] == 0 | k[1] == 0 || k[0] == m - 1 || k[1] == n - 1))	//If reached the exit and entry not equal to exit          
                        return c;

                   	//Check in all 4 directions
                    if (k[0] + 1 < m && maze[k[0] + 1][k[1]] == '.')
                        q.push({ k[0] + 1,
                            k[1] });
                    if (k[0] - 1 >= 0 && maze[k[0] - 1][k[1]] == '.')
                        q.push({ k[0] - 1,
                            k[1] });
                    if (k[1] + 1 < n && maze[k[0]][k[1] + 1] == '.')
                        q.push({ k[0],
                            k[1] + 1 });
                    if (k[1] - 1 >= 0 && maze[k[0]][k[1] - 1] == '.')
                        q.push({ k[0],
                            k[1] - 1 });
                    maze[k[0]][k[1]] = '+';	//Mark current cell as visited
                }
                c++;
            }
            return -1;
        }
};