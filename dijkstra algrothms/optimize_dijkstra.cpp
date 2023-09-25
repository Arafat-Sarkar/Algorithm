#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
int dis[N];
bool vis[N];
vector<pair<int,int>>g[N];
void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty())
    {
        pair<int,int> perent = pq.top();
        pq.pop();
        int perentNode = perent.second;
        if(vis[perentNode])
        {
            continue;
        }
        vis[perentNode]=true;
        int perentCost = perent.first;
        for( pair child : g[perentNode])
        {
            
            int childNode = child.first;
            int childCost = child.second;
            if(perentCost + childCost<dis[childNode])
            {
                dis[childNode] = perentCost + childCost;
                pq.push({dis[childNode],childNode});
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
    int a,b,w;
    cin>>a>>b>>w;
    g[a].push_back({b,w});
    g[b].push_back({a,w});

   } 
   
  
   for(int i =1; i<=n; i++)
   {
     dis[i]= INT_MAX;
   }
    dijkstra(1);
   for(int i=1; i<=n; i++)
   {
     cout<<"Node "<<i<<": "<<dis[i]<<endl;
   }
    return 0;
}