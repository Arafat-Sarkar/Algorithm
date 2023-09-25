#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
vector<pi>path = {{-1,0}, {1 ,0},{0,-1},{0,1}};
const int N = 1005;
bool vis [N][N];
int dis[N][N];
char ar[N][N];
int n,m;
bool valid ( int ci, int cj)
{
    if ( ci>=0 && ci<n && cj>=0 && cj<m && ar[ci][cj]=='.') return true;
    else 
     return false ;
}
void bfs(int si, int sj)
{
    queue<pi>q;
    q.push({si,sj});
    dis[si][sj] =0;
    vis[si][sj]= true;
    while(!q.empty())
    {
        pi perent = q.front();
        q.pop();
        int pI = perent.first;
        int pj = perent.second;
        for(int i=0;i<4; i++)
        {
            pi  p = path[i];
            int ci = pI+p.first;
            int cj = pj+p.second;
            if( valid(ci, cj) && ! vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push( {ci,cj});
                dis[ci][cj] = dis[pI][pj] +1;
            }

        
        
        
        }
    }

}
int main()
{
    
    cin>>n>>m;
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];

        }
    }
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);

   int dj,di;
   cin>>di>>dj;
   if(vis[di][dj])
   {
      cout<<"YES"<<endl;

   }
   else
   {
      cout<<"NO"<<endl;

   }

    return 0;
}