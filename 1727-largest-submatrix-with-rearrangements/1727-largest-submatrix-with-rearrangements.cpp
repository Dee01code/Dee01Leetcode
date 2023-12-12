class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] != 0){
                    matrix[i][j] = matrix[i-1][j] + 1;
                }
                else{
                    matrix[i][j] = 0;
                }
            }
        }
        int maxArea = 0;
        for(int i = m-1; i >= 0; i--){
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            int area = 0;
            for(int j = 0; j < n; j++){
                area = (matrix[i][j] * (j+1));
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};