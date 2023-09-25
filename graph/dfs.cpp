#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>g[N];
bool vis[N];
void dfs( int src)
{
    vis[src]= true;
    cout<<src<<endl;
    
    for(int i=0; i<g[src].size();i++)
    {
        int child = g[src][i];
        if(vis[child]==false)
        {
            dfs(child);
          
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
   dfs(1);
    return 0;
}