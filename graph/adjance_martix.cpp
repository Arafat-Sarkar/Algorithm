#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    int adj[n+1][n+1];
    for(int i=0; i<=n;i++)
    {
        for(int j= 0; j<=n;j++)
        {
            adj[i][j]=0;
            if(i==j)
            adj[i][j]=1;

        }
    }
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a][b]=1; //eita hocche 1 ebong 2 modde 1 dichi edge ache deikha
        adj[b][a]=1;
    }
     for(int i=0; i<=n;i++)
    {
        for(int j= 0; j<=n;j++)
        {
            cout<<adj[i][j]<<" ";

        }
        cout<<endl;
    }
    return 0;
}