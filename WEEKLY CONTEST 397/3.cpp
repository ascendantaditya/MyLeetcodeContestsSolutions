//Maximum Difference Score in a Grid
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,INT_MIN));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for(int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i < m - 1)
                  dp[i][j] = max(dp[i][j],dp[i + 1][j]);
                if (j < n - 1)
                  dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                dp[i][j] = max(dp[i][j],grid[i][j]);
            }
        }
        int Max = INT_MIN;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ( i < m - 1)
                   Max = max(Max,dp[i + 1][j] - grid[i][j]);
                if ( j < n - 1)
                   Max = max(Max,dp[i][ j + 1] - grid[i][j]);
            }
        }
        return Max;
    }
};
