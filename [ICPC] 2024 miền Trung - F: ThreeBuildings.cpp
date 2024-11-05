//https://oj.vnoi.info/problem/icpc24_mt_f
/*
	www.youtube.com/YugiHackerChannel
	linktr.ee/YugiHacker
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn
using namespace std;
struct edge
{
    int u, v, c, f;
    edge(int u, int v, int c, int f) : u(u), v(v), c(c), f(f) {}
};
struct Flow
{
    const int inf = 1e9;
    int n, s, t;
    vector <vector<int>> a;
    vector <edge> e;
    vector <int> d, cur;

    Flow(int n, int s, int t) : n(n), s(s), t(t)
    {
        a.resize(n+1);
        d.resize(n+1);
        cur.resize(n+1);
    }

    void AddEdge(int u, int v, int c)
    {
        a[u].push_back(e.size());
        e.push_back(edge(u, v, c, 0));
        a[v].push_back(e.size());
        e.push_back(edge(v, u, 0, 0));
    }

    bool bfs()
    {
        queue <int> q;
        fill(d.begin(), d.end(), -1);
        d[s] = 1;
        q.push(s);
        while (q.size())
        {
            int u = q.front(); q.pop();
            for (int id : a[u])
            {
                int v = e[id].v;
                if (d[v] == -1 && e[id].f < e[id].c)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] >= 0;
    }
    int dfs(int u, int f)
    {
        if (f == 0) return 0;
        if (u == t) return f;
        for (;cur[u] < a[u].size(); cur[u]++)
        {
            int id = a[u][cur[u]], v = e[id].v;
            if (d[v] != d[u] + 1) continue;
            int delta = dfs(v, min(f, e[id].c - e[id].f));
            if (delta)
            {
                e[id].f += delta;
                e[id^1].f -= delta;
                return delta;
            }
        }
        return 0;
    }
    long long MaxFlow()
    {
        long long f = 0;
        while (bfs())
        {
            fill(cur.begin(), cur.end(), 0);
            int delta;
            while (delta = dfs(s, 1e9))
                f += delta;
        }
        return f;
    }
};
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        Flow G(n+5, 1, n+5);
        for (int i=1; i<=n; i++) G.AddEdge(1, i+1, 1);
        vector <int> c(3);
        f0 (i, 3)
        {
            cin >> c[i];
            G.AddEdge(i + n + 2, n + 5, c[i]);
        }
        f0 (i, 3) {
            int k; cin >> k;
            while (k--) {
                int x; cin >> x; ++x;
                G.AddEdge(x, i + n + 2, 1);
            }
        }
        //for (int i=0; i<G.e.size(); i+=2) cout << G.e[i].u << ' ' << G.e[i].v << ' ' << G.e[i].c, el;
        cout << G.MaxFlow(); el;
    }
}
