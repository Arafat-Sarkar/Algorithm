#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<pair<int,int>>g[N];
int dis[N];
void dijkstra( int src)
{
    queue<int>q;
    q.push(src);
    dis[src] = 0;
    while(!q.empty())
    {
        int perent = q.front();
        q.pop();
        for(int i=0; i<g[perent].size(); i++)
        {
            pair<int, int> child = g[perent][i];
            int childNode = child.first;
            int edgecost = child.second;
            if(dis[perent]+edgecost <dis[childNode])
            {
                dis[childNode] = dis[perent]+edgecost;
                q.push(childNode);
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

   
   for(int i=1; i<=n;i++)
   {
     dis[i]= INT_MAX;
   }
    dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<": "<<dis[i]<<endl;
    }
    return 0;
}