#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005
#define INF 1e18

typedef struct Edge{
    int to, rev;
    long long cap;
}Edge;

vector<Edge> G[MAXN];
int d[MAXN], iter[MAXN];

void add_edge(int from, int to, long long cap) 
{
    G[from].push_back((Edge) { to, (int)G[to].size(), cap });
    G[to].push_back((Edge) { from, (int)G[from].size() - 1, 0 });
}

void bfs(int s) 
{
    memset(d, -1, sizeof(d));
    queue<int> que;
    d[s] = 0;
    que.push(s);
    while (!que.empty()) 
    {
        int v = que.front(); que.pop();
        for (size_t i = 0; i < G[v].size(); ++i) 
        {
            Edge& e = G[v][i];
            if (e.cap > 0 && d[e.to] < 0) 
            {
                d[e.to] = d[v] + 1;
                que.push(e.to);
            }
        }
    }
}

long long dfs(int v, int t, long long lim) 
{
    if (v == t) return lim;
    for (int& i = iter[v]; i < (int)G[v].size(); ++i) 
    {
        Edge& e = G[v][i];
        if (e.cap > 0 && d[v] < d[e.to]) 
        {
            long long flow = dfs(e.to, t, min(lim, e.cap));
            if (flow > 0) 
            {
                e.cap -= flow;
                G[e.to][e.rev].cap += flow;
                return flow;
            }
        }
    }
    return 0;
}

long long max_flow(int s, int t) 
{
    long long flow = 0;
    while (true) 
    {
        bfs(s);
        if (d[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
        que.push(make_pair(0, s));
        while (!que.empty()) 
        {
            pair<int, int> p = que.top(); que.pop();
            int v = p.second;
            if (d[v] < p.first) continue;
            for (size_t i = 0; i < G[v].size(); ++i) 
            {
                Edge& e = G[v][i];
                if (e.cap > 0 && d[e.to] < 0) 
                {
                    d[e.to] = d[v] + 1;
                    que.push(make_pair(d[e.to], e.to));
                }
            }
        }

        long long f;
        while ((f = dfs(s, t, INF)) > 0) 
        {
            flow += f;
        }
    }
}

int main() 
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    long long mf = max_flow(s, t);
    cout << mf << endl;
    return 0;
}