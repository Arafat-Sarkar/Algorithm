#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector< pair<int, int>>adj[N];
int n,m;
long long int INF = 1e18;
bool visited[N];
long long int d[N];

void dijkstra(int src)
{
  for (int i=1; i<=n;i++)
  {
    d[i]= INF;
  }
  d[src]= 0;
  priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int,int>>> pq;
  pq.push({d[src], src}); //mane node and wegheted ta dilam
  
  while(!pq.empty())
  {
   pair<int,int> f = pq.top();
   pq.pop();
   int selectnode= f.second;
   if (visited[selectnode]) continue;
   visited[selectnode] = true;
   for (auto child : adj[selectnode])
   {
     int edagecost  = child.first;
     int node = child.second;
      if( d[selectnode]+ edagecost< d[node])
      {
        d[node]= d[selectnode]+ edagecost;
        pq.push({d[node], node});
      }
   }
  }

}

int main()
{
   
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
     int u,v,w;
     cin>>u>>v>>w;
     adj[u].push_back({w,v});
     adj[v].push_back({w,u});
   }
   int src= 1;
   dijkstra(src);
   for(int i=1; i<=n; i++)
   {
    cout<<d[i]<<" ";
   }
    return 0;
}