class Solution {

#define vvi vector<vector<int>>
#define vi vector<int>

public:
    int maxSumSubmatrix(vector<vector<int>>& grid, int k)
    {
        int     C = grid[0].size();
        int     R = grid.size();
        int     i, j, ii, jj, tmp, r;
        vvi     dp(R + 1, vi(C, 0));

        /*  
        *   step 1: make a dp grid of (r + 1) x c
        *   set to 'cascading' prefix sum
        */

        i = -1;
        while (++i < R)
        {
            j = -1;
            while (++j < C)
                dp[i + 1][j] = dp[i][j] + grid[i][j];
        }
        vvip(dp, R + 1, C); // printer

        /*  
        *   step 2: traversing/squeezing in from top-left to bottom-right
        *   find sum that equals k
        *   if not found, let res = max(res, sum)
        */

        r = -2147483648;
        i = -1;
        while (++i < R)
        {
            ii = i;
            while (++ii < R + 1)
            {
                j = -1;
                while (++j < C)
                {
                    tmp = 0;
                    jj = j - 1;
                    while (++jj < C)
                    {
                        tmp += dp[ii][jj] - dp[i][jj];
                        if (tmp == k)
                            return k;
                        if (tmp < k && r < tmp)
                            r = tmp;
                    }
                }
            }
        }
        return r;
    }

    void    vvip(vvi dp, int r, int c)
    {
        int     i = -1, j;

        while (++i < r)
        {
            j = -1;
            while (++j < c)
                cout << dp[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
};

/*
[[1,0,1],[0,-2,3],[2,6,-6]]
2
[[1,0,1],[0,-2,3],[-10,-12,-1]]
2
*/