#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int marks[n];

        for (int i = 0; i < n; i++)
        {
            cin >> marks[i];
        }

        bool dp[n + 1][1001];
        memset(dp, false, sizeof(dp));

        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 1000; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (j >= marks[i - 1])
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - marks[i - 1]];
                }
            }
        }

        if (dp[n][1000 - m])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}