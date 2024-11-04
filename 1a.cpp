//#pragma GCC optimize ("O3")

//#include <bits/stdc++.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <exception>
#include <functional>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <random>
#include <stdexcept>
#include <typeinfo>
#include <utility>
#include <tuple>
#include <cstdio>
#include <bitset>

using namespace std;

// ************ Define ************
#define FPTU ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define BUG(x) {cerr << #x << " = " << x << endl;}
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ll  long long
#define ull unsigned long long
#define usi unsigned int
#define pll pair<ll,ll>
#define plp pair<ll,pll>
#define ppl pair<pll,ll>
#define ppp pair<pii,pii>
#define oo 1000111000
#define ooo 1000111000111000111
#define inf 0x3f //4557430888798830399
#define fi first
#define se second
#define vt vector
#define pb push_back
#define all(arr) arr.begin(),arr.end()
#define bit(n, i) (((n) >> (i)) & 1)
#define db(x) cerr << #x << " = " << (x) << '\n';
#define el cout<<'\n';

int mod=1e9+7; // MODDDDDDDDDDDDD

template<typename T>void minimize(T &a, T b){ if(a>b)  a=b; }
template<typename T>void maximize(T &a, T b){ if(a<b)  a=b; }
template<typename T>void add(T &a, T b){ a+=b; if(a>=mod) a-=mod; }
template<typename T> T gcd(T a, T b)
{
    if(a<b) swap(a,b);
    while(a){
        b%=a;
        swap(a,b);
    }
    return b;
}
vector<pair<int,int>> queen  = {{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
vector<pair<int,int>> knight = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
vector<pair<int,int>> bishop = {{-1,-1},{-1,1},{1,-1},{1,1}};
vector<pair<int,int>> rook   = {{-1,0},{0,-1},{0,1},{1,0}};
ll rand_num(ll a,ll b) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}

void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}


// =========> <3 VietHai1709 <3  <=========
struct DSU {
    int n;
    int cnt;
    vector<int> pa;
    vt<vt<pii>> edge;
    vt<int> vis;
    DSU(int _n) {
        n = _n;
        cnt=n;
        pa.resize(n+1,-1);
        edge.resize(n+1);
        vis.resize(n+1,0);
    }
    int root(int u) {
        return pa[u] < 0 ? u : pa[u] = root(pa[u]);
    }
    int group_count(){
        return cnt;
    }
    int count(int u){
        return -pa[root(u)];
    }
    bool share(int u,int v){
        return root(u) == root(v);
    }
    bool merge(int u, int v,int x) {
        u = root(u); v = root(v);
        if (u == v) return 0;
        if(pa[u] > pa[v]) swap(u,v);
        pa[u]+=pa[v]; pa[v]=u;
        cnt--;
        edge[u].pb({v,x});
        edge[v].pb({u,x});
        return 1;
    }
    bool check(set<int> vec){
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            cout<<"ke["<<i<<"]: ";
            for(auto [x,c]:edge[i]) cout<<x<<' ';el;
        }
        for(int i=1;i<=n;i++) if(!vis[i])
        {
            vis[i]=1;
            queue<int> qu;
            qu.push(i);
            set<int> s;
            cout<<"BFS: ";
            while(!qu.empty()){
                int u =qu.front(); qu.pop();
                cout<<u<<' ';
                for(auto &[v,c]:edge[u]) if(!vis[v]){
                    vis[v]=1;
                    s.insert(c);
                    qu.push(v);
                }
            }
            el;
            cout<<"s: ";
            for(auto x:s) cout<<x<<' ';el;
            cout<<"vec: ";
            for(auto x:vec) cout<<x<<' ';el;
            if(s==vec) return 1;
        }
        return 0;
    }
};
void Minnnnnnn()
{
    int n,m,q;
    cin>>n>>m>>q;
    vt<vt<int>> dis(n+1,vt<int>(n+1,-1));
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        if(dis[u][v]==-1){
            dis[u][v]=c;
            dis[v][u]=c;
        }
        else{
            minimize(dis[u][v],c);
            minimize(dis[u][v],c);
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++) if(dis[i][k]!=-1)
            for(int j=1;j<=n;j++) if(i!=j && dis[k][j]!=-1)
            {
                if(dis[i][j]==-1){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
                else
                minimize(dis[i][j],dis[i][k]+dis[k][j]);
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<dis[i][j]<<' '; el;
    }
    vt<int> arr;
    arr.pb(0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(dis[i][j]!=-1)
            arr.pb(dis[i][j]);
    sort(all(arr));
    int d=0;
    map<int,int> mp;
    for(int i=1;i<arr.size();i++) if(arr[i]!=arr[i-1]){
        mp[arr[i]]=++d;
    }
    vt<vt<pii>> canh(d+1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) if(dis[i][j]!=dis[0][0])
            canh[mp[dis[i][j]]].pb({i,j});
    while(q--){
        int c;
        cin>>c;
        DSU myDSU(n);
        set<int> s;
        for(int i=1;i<=c;i++){
            int x;
            cin>>x;
            s.insert(x);
            for(auto &[u,v] :canh[x]) 
            {
                
                int ok= myDSU.merge(u, v, x);
                if(ok) {
                    cout<<"add: "<<u<<' '<<v<<' '<<x;el;
                }
                else{
                    cout<<"not add: "<<u<<' '<<v<<' '<<x;el;

                }
            }
        }
        if(myDSU.check(s)) cout<<"Yes ";
        else cout<<"No ";
        el;
        
    }
    el;
}


int main(){
    FPTU;

    read_file();
    
    int Test_case=1;
    cin>>Test_case;
    
    for(int _=1;_<=Test_case;_++)
    {
//        cout<<"Case #"<<_<<": ";
        Minnnnnnn();
//        el;
    }
    
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
