#include <bits/stdc++.h>
using namespace std;
bool subset_sum(int n, int ar[], int s)
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }
    if (ar[n - 1] <= s)
    {
        bool op1 = subset_sum(n - 1, ar, s - ar[n - 1]);
        bool op2 = subset_sum(n - 1, ar, s);
        return op1 || op2;
    }
    else
    {
        return subset_sum(n - 1, ar, s);
    }
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int s;
    cin >> s;
    if (subset_sum(n, ar, s))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}