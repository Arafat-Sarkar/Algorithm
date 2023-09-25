#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        long long int r = a * b;
        long long int r2 = (r%100);
        cout<<r2<<endl;
        
    }
    return 0;
}