//https://oj.vnoi.info/problem/icpc24_mt_j

/*
	www.youtube.com/YugiHackerChannel
	linktr.ee/YugiHacker
*/
//2024-11-04-13.37.05
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 100005
using namespace std;
int n, q, p[20][maxn], h[maxn];
vector <int> a[maxn];
void dfs(int u) {
    for (int v:a[u]) if (v != p[0][u]) {
        p[0][v] = u;
        h[v] = h[u] + 1;
        for (int i=1; i<20; i++) p[i][v] = p[i-1][p[i-1][v]];
        dfs(v);
    }
}
int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i=19; i>=0; i--) if ((h[u] - h[v] >> i) & 1) u = p[i][u];
    if (u == v) return u;
    for (int i=19; i>=0; i--) if (p[i][u] != p[i][v]) u = p[i][u], v = p[i][v];
    return p[0][u];
}
int dist (int u, int v) {
    return h[u] + h[v] - 2 * h[lca(u, v)];
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    f1 (i, n-1) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (dist(x, y) + dist(y, z) == dist(x, z)) cout << "YES";
        else cout << "NO";
        el;
    }
}
