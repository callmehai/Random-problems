//#pragma GCC optimize ("O3")

//#include <bits/stdc++.h>

#include <iostream>     // Input/output stream objects
#include <fstream>      // File stream objects
#include <sstream>      // String stream objects
#include <iomanip>      // Input/output manipulators
#include <string>       // String class and functions
#include <vector>       // Dynamic array
#include <list>         // Doubly linked list
#include <set>          // Set container
#include <map>          // Map container
#include <queue>        // Queue container
#include <stack>        // Stack container
#include <algorithm>    // Algorithms on sequences (e.g., sort, find)
#include <cmath>        // Mathematical functions
#include <ctime>        // Date and time functions
#include <cstdlib>      // General purpose functions (e.g., memory management)
#include <cstring>      // C-style string functions
#include <cctype>       // Character classification functions
#include <cassert>      // Assert function for debugging
#include <exception>    // Standard exceptions
#include <functional>   // Function objects
#include <iterator>     // Iterator classes
#include <limits>       // Numeric limits
#include <locale>       // Localization and internationalization
#include <numeric>      // Numeric operations (e.g., accumulate)
#include <random>       // Random number generators
#include <stdexcept>    // Standard exception classes
#include <typeinfo>     // Runtime type information
#include <utility>      // Utility components (e.g., std::pair)
#include <tuple>
#include <cstdio>
#include <bitset>

using namespace std;

// ************ Setting up  ************
#define FPTU ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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
#define oo 0x3f3f3f3f
#define ooo 0x3f3f3f3f3f3f3f3f
#define inf 0x3f //4557430888798830399
#define fi first
#define se second
#define vt vector
#define pb push_back
#define all(arr) arr.begin(),arr.end()
#define bit(n, i) (((n) >> (i)) & 1)
#define db(x) cerr << #x << " = " << (x) << '\n';
#define el cout<<'\n';
template <typename T> void minimize(T &a, T b){ if(a>b)  a=b; }
template <typename T> void maximize(T &a, T b){ if(a<b)  a=b; }
ll rand_num(ll a,ll b) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}

int mod=1e9+7; // MODDDDDDDDDDDDD

template <typename T> T gcd(T a, T b)
{
    while(a!=0&&b!=0)
    {
        if(a>b) a%=b;
        else b%=a;
    }
    return a+b;
}


void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}
// =========> <3 VietHai1709 <3  <=========
const int N=2e5;
const int M=20;
int pa[M+1][N+5];
int h[N+5];
int cnt[N+5];
int pre[N+5];
vt<pii> ke[N+5];

void dfs(int u,int p){
    for(auto &[v,_]:ke[u]) if(v!=p){
        h[v]=h[u]+1;
        pa[0][v]=u;
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(h[u]<h[v]) swap(u,v);
    for(int k=M;k>=0;k--){
        if(h[pa[k][u]]>=h[v]) u=pa[k][u];
    }
    if(u==v) return u;
    for(int k=M;k>=0;k--){
        if(pa[k][u]!=pa[k][v]){
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
void calc(int u,int edge){
    for(auto &[v,id]:ke[u]) if(v!=pa[0][u]){
        calc(v,id);
        pre[u]+=pre[v];
    }
    if(edge!=-1) cnt[edge]=pre[u];
}
void Minnnnnnn()
{
    int n;
    cin>>n;
    vt<int> a(n+1),b(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v>>a[i]>>b[i];
        ke[u].pb({v,i});
        ke[v].pb({u,i});
    }
    pa[0][1]=1;
    h[1]=0;
    dfs(1,0);
    for(int k=1;k<=M;k++)
        for(int i=1;i<=n;i++)
            pa[k][i]=pa[k-1][pa[k-1][i]];
    for(int i=1;i<n;i++){
        int l=lca(i,i+1);
//        cout<<i<<' '<<i+1<<' '<<l<<'\n';
        pre[i]++;
        pre[i+1]++;
        pre[l]-=2;
    }
//    for(int i=1;i<=n;i++) cout<<pre[i]<<' '; el;
    calc(1,-1);
//    for(int i=1;i<n;i++) cout<<cnt[i]<<' ';el;
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=min(1ll*a[i]*cnt[i],1ll*b[i]);
    }
    cout<<ans;
}
int main(){
    FPTU; //read_file();
    int Test_case=1;
//    cin>>Test_case;
//    sang();
    while(Test_case--)
    {
//        cout<<"Case #"<<_<<": ";
        Minnnnnnn();
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
