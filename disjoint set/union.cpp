#include<bits/stdc++.h>
using namespace std;
int perent[1000];
void dsu_set(int n)
{
    for(int i=1;1<=n;i++)
    {
        perent[i]=-1;
    }
}
int dsu_find(int node)
{
    while(perent[node] != -1)
    {
        node = perent[node];
    }
    return node;
}
void dsu_union(int a,int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if(leaderA != leaderB)
    {
        perent[leaderB]= leaderA;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        dsu_union(a,b);
    }
    return 0;
}