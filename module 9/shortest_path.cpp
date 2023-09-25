#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
int level [N];
int perent[N];
void bfs( int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]= 0;
    perent[s]=-1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        // cout<<"Visiting Node : "<<u<<endl;
        for(int v: adj[u])
        {
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            level[v] = level[u]+1;
            perent[v]=u;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int s,d;
    cin>>s>>d;
    bfs(s);
    cout<< "Distance"<< " "<<level[d]<<endl;
    vector<int>p;
    int current= d;
    while(current != -1)
    {
        p.push_back(current);
        current = perent[current];
    }
    reverse(p.begin(), p.end());
    cout<<"path ";
    for(int node : p)
    {
        cout<< node<<" ";
    }
    
    return 0;
}