//https://oj.vnoi.info/problem/icpc24_mt_m

#pragma GCC optimize ("O3")

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


void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}


// =========> <3 VietHai1709 <3  <=========
const int N=401;
const int M=1e5+5;
bool mark[N][M];
int dis[N][N];
struct DSU {
    int pa[N];
    DSU() {
        memset(pa,-1,sizeof(pa));
    }
    void init(int n){
        memset(pa,-1, (n+1)*sizeof(int));
    }
    int root(int u) {
        return pa[u] < 0 ? u : pa[u] = root(pa[u]);
    }
    bool share(int u,int v){
        return root(u) == root(v);
    }
    bool merge(int u, int v) {
        u = root(u); v = root(v);
        if (u == v) return 0;
        if(pa[u] > pa[v]) swap(u,v);
        pa[u]+=pa[v]; 
        pa[v]=u;
        return 1;
    }
};
int n,m,q,d;
DSU MyDSU;
DSU DistDSU[M];

vt<int> vec;
vt<pii> canh[M];
bool check(){

    int sz = (int)vec.size();
    for(int i=1;i<=n;i++) if(MyDSU.root(i)==i)
    {
//        cout<<"ROOT: "<<i;el;
        memset(mark[i],0,sz*sizeof(int));
    }
//    cout<<"VEC: "; for(int x:vec) cout<<x<<' ';el;
    for(int x=0;x<sz;x++){
        for(pii &u: canh[vec[x]]){
            mark[MyDSU.root(u.fi)][x]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(MyDSU.root(i)==i){
            bool ok=1;
            for(int x=0;x<sz;x++) if(!mark[i][x]){
                ok=0;
                break;
            }
            if(ok) return 1;
            
        }
    }
        
    return 0;
}
void Minnnnnnn()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) memset(dis[i],-1, (n+1)*sizeof(int));
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        if(dis[u][v]==-1){
            dis[u][v]=c;
            dis[v][u]=c;
        }
        else{
            minimize(dis[u][v],c);
            minimize(dis[v][u],c);
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
    
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++) cout<<dis[i][j]<<' '; el;
//    }
//    el;
    
    vt<int> arr;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) if(dis[i][j]!=-1)
            arr.pb(dis[i][j]);
    sort(all(arr));
    arr.resize(unique(all(arr)) - arr.begin());
    d=(int)arr.size();
//    for(int x:arr) cout<<x<<' ';el;
   
    
    for(int i=0;i<d;i++) {
        canh[i].clear();
        DistDSU[i].init(n);
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) if(dis[i][j]!=-1){
            int x = (int)(lower_bound(all(arr), dis[i][j]) - arr.begin());
            if(DistDSU[x].merge(i, j)){
                canh[x].pb({i,j});
            }

        }
    
    while(q--){
        int c;
        cin>>c;
        vec.clear();
        MyDSU.init(n);
        bool ok=1;
        for(int i=1;i<=c;i++){
            int x;
            cin>>x;
            if(!ok) continue;
            
            int id = (int)(lower_bound(all(arr), x) - arr.begin());

            if(id>=d) ok=0;
            
            if(!ok) continue;
            
            vec.pb(id);
            
            for(auto &[u,v] :canh[id])
            {
                if(MyDSU.merge(u, v)){
//                    cout<<"add: "<<u<<' '<<v<<' '<<id;el;
                }
                else{
//                    cout<<"not add: "<<u<<' '<<v<<' '<<id;el;
                }
            }
        }
        if(!ok) cout<<"No ";
        else if(check()) cout<<"Yes ";
        else cout<<"No ";
//        el;
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
