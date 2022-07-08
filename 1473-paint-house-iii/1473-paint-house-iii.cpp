class Solution {
public:
    vector<int>arr;
    vector<vector<int>>cost;
    int dp[101][21][101];
    int mincost(int idx, int j, int k)
    {
        if (idx == arr.size())
        {
            if (k == 1)
            {
                return 0;
            }
            else
            {
                return 1e8;
            }
        }
        if (k <= 0)
        {
            return 1e8;
        }
        if (dp[idx][j][k] != -1)
        {
            return dp[idx][j][k];
        }
        int ans = 1e8;


        if (arr[idx] != 0)
        {
            ans = min(ans, mincost(idx + 1, arr[idx], ((j == arr[idx]) || (j == 0)) ? k : k - 1));
        }
        else
        {
            for (int i = 1; i <= cost[0].size(); i++)
            {
                ans = min(ans, mincost(idx + 1, i , ((j == i) || (j == 0) ? k : k - 1)) + cost[idx][i - 1]);
            }
        }

        return dp[idx][j][k] = ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& c, int m, int n, int target) {
        arr = houses;
        cost = c;
        memset(dp, -1, sizeof(dp));
        int x = mincost(0, 0, target);
        if (x == 1e8) return -1;
        return x;
    }
};