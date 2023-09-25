#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool vis[N];
vector<int> cmd;
void dfs( int s)
{
    vis[s]=true;
    cmd.push_back(s);
    for(int child : v[s])
    {
        if(!vis[child])
        {
            vis[child]=true;

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
      v[a].push_back(b);
      v[b].push_back(a);
     
   } 
   int cnt = 0;
   for(int i=1; i<=n;i++)
   {
      if ( !vis[i])
      {
        cnt ++;
        dfs(i);
        for(int val : cmd)
        {
            cout<<val<<" ";
        }
        cout<<endl;
        cmd.clear();
      }
   }
   cout<<cnt<<endl;
    return 0;
}