#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int solve(int n, int s, int v[], int w[])
{
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (w[n - 1] <= s)
    {
        int ch1 = solve(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int ch2 = solve(n - 1, s, v, w);
        return dp[n][s] = max(ch1, ch2);
    }
    else
    {
        return dp[n][s] = solve(n - 1, s, v, w);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int v[n], w[n];
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << solve(n, s, v, w) << endl;
    }
    return 0;
}