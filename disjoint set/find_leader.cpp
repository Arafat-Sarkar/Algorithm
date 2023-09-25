#include<bits/stdc++.h>
using namespace std;
int perent[8]={-1,-1, 1, 1, 6, 4, -1, -1};
int find(int n)
{
    while(perent[n]!=-1)
    {
        n= perent[n];
    }
    return n;
}
int main()
{
    cout<<find(2);
    return 0;
}