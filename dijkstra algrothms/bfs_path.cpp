#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> g[N];
int dis[N];
int par[N];
bool vis[N];

void bfs( int s)
{
    queue<int>q;
    q.push(s);
    dis[s]= 0;
    par[s] =-1;
    vis[s]=true;
    while(!q.empty())
    {
        int perent = q.front();
        q.pop();
        for(int child : g[perent])
        {
            if(!vis[child])
            {
                q.push(child);
                par[child] = perent;
                dis[child]= dis[perent]+1;
                vis[child]=true;
            }

        }
    }
}
int main()
{
   int n,e;
   cin>>n>>e;
   while(e--)
   {
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
      
    } 
    bfs(1);
    // for(int i=1; i<=n;i++)
    // {
    //     cout<<"Node "<<i<<": "<<par[i]<<endl;
    // }
    int d;
    cin>>d;
    if(vis[d])
    {
        vector<int>path;
        int x = d;
        while(x!= -1)
        {
           path.push_back(x);
            x= x[par];

        }
        reverse(path.begin(),path.end());
        for(int val : path)
        {
            cout<<val<<endl;
        }
    }
    else 
    {
        cout<<"Path Nai"<<endl;
    }
    return 0;
}