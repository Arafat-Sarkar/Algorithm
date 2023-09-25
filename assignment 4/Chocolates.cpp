#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;

        int ch[N];

        for (int i = 0; i < N; i++) 
        {
            cin >> ch[i];
        }

        int totalch = 0;

        for (int i = 0; i < N; i++) {
            totalch+= ch[i];
        }

        
        if (totalch % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }

        
        bool dp[N + 1][totalch / 2 + 1];
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= totalch / 2; j++) {
                dp[i][j] = false;
            }
        }

        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= totalch / 2; j++) {
                if (j >= ch[i - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - ch[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[N][totalch / 2]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}