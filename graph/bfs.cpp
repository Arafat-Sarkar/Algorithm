#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vistied[N];
int dis[N];
vector<int> adj[N];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vistied[src]=true;
    dis[src] = 0;
    while(!q.empty())
    {
        int perent = q.front();
        q.pop();
        cout<<perent<<endl;
        for(int i=0; i<adj[perent].size();i++)
        {
            int child = adj[perent][i];
            
            if(vistied[child]==false)
            {
                q.push(child);
                dis[child]= dis[perent]+1;
                vistied[child]=true;

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
    adj[a].push_back(b);
    adj[b].push_back(a);

   }
   bfs(1); 
   for(int i=1; i<=n; i++)
   {
     cout<< "Node "<<i <<": "<<dis[i]<<endl;
   }
    return 0;
}