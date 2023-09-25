#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
class Edge
{
public:
    long long int u;
    long long int v;
    long long int w;
    Edge(long long int u, long long int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<Edge> v;
    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    long long int dis[n + 1];
    for (long long int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    int s;
    cin>>s;
    dis[s] = 0;
    for (long long int i = 1; i <= n - 1; i++)
    {
        for (long long int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            long long int a = ed.u;
            long long int b = ed.v;
            long long int w = ed.w;
            if ( dis[a] != INF && dis [a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
    bool cycle = false;
    for (long long int j = 0; j < v.size(); j++)
    {
        Edge ed = v[j];
        long long int a = ed.u;
        long long int b = ed.v;
        long long int w = ed.w;
        if ( dis[a] != INF && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
            dis[b] = dis[a] + w;
        }
    }
    long long int q;
    cin >> q;
    while (q--)
    {
        long long int d;
        cin >> d;
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else
        {
            if (dis[d] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[d] << endl;
            }
        }
    }

    return 0;
}