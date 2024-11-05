//https://oj.vnoi.info/problem/icpc24_mt_k
/*
	www.youtube.com/YugiHackerChannel
	linktr.ee/YugiHacker
*/
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 102
#define bit(mask,i) ((mask>>i)&1)

using namespace std;
int n;
long long dist[15][maxn][maxn];
vector <pair<int, int>> nest;
long long dp[1 << 15], c[1 << 15];
int a[maxn][maxn];
int m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
long long d[maxn][maxn];
using T = tuple <long long, int, int>;
void dijkstra(pair <int, int> p, int id) {
    memset(d, 60, sizeof d);
    d[p.first][p.second] = 0;
    priority_queue <T, vector<T>, greater<T>> q;
    q.push({0, p.first, p.second});
    while (q.size()) {
        auto [du, x, y] = q.top();
        //cout << du << ' ' << x  << ' ' << y, el;
        q.pop();
        if (d[x][y] != du) continue;
        f0 (i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                long long nxt_d = du + a[nx][ny];
                if (nxt_d < d[nx][ny]) {
                    q.push({nxt_d, nx, ny});
                    //cout << nxt_d << ' ' << nx << ' ' << ny, el;
                    d[nx][ny] = nxt_d;
                }
            }
        }
    }
    f0 (i, n) f0 (j, n) dist[id][i][j] = d[i][j];
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    f0 (i, n) f0 (j, n) {
        string s; cin >> s;
        if (s == "*")
        {
            a[i][j] = 0;
            nest.push_back({i, j});
        }
        else a[i][j] = stoi(s);
    }
    //f0 (i, n) {f0 (j, n) cout << a[i][j] << ' '; el;}
    m = nest.size();
    //f0 (i, n) {f0 (j, n) cout << dist[0][i][j] << ' '; el;}
    f0 (i, m) dijkstra(nest[i], i);
    //f0 (i, n) {f0 (j, n) cout << dist[0][i][j] << ' '; el;}
    memset(c, 60, sizeof c);
    f0 (i, n) f0 (j, n) if (a[i][j] != 0) {
        vector <long long> f(1 << 15);
        f1 (mask, (1 << m) - 1) {
            int x = 31 -  __builtin_clz(mask & -mask);
            f[mask] = f[mask ^ (mask & -mask)] + dist[x][i][j];
            c[mask] = min(c[mask], f[mask]);
        }
    }
    //return 0;
    memset(dp, 60, sizeof dp);
    f1 (mask, (1 << m) - 1) {
        if (__builtin_popcount(mask) == 1) dp[mask] = 0;
        for (int sub=mask; sub; sub = (sub - 1) & mask) {
            //cout << bitset<3>(mask) << ' ' << bitset<3>(sub); el;
            if (sub != mask) {
                dp[mask] = min(dp[mask], dp[sub] + dp[mask ^ sub] + c[mask]);
            }
        }
        //cout << bitset <4> (mask) << ' ' << dp[mask], el;
    }
    cout << dp[(1 << m) - 1];
}
