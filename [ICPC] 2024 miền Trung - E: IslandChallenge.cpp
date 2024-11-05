//https://oj.vnoi.info/problem/icpc24_mt_e
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
const int N=101;
char a[N][N];
int dp[1<<15][15];
int dist[15][N*N];
vt<pii> pos;
int n,m,k;
int dis[15][15];
#define node pair<int,pii>
int O(int i,int j){
    return (i-1)*m+j;
}
bool valid(int i,int j){
    return (i>0 && j>0 && i<=n && j<=m && a[i][j]!='#');
}
void calc(int s){
    priority_queue<node,vt<node>,greater<node>> pq;
    pq.push({0,pos[s]});
    dist[s][O(pos[s].fi,pos[s].se)]=0;
    while(!pq.empty()){
        auto [w,_] =pq.top(); pq.pop();
        int x=_.fi;
        int y=_.se;
        if(w> dist[s][O(x,y)]) continue;
        
        for(auto &[i,j]:rook){
            int u=x+i;
            int v=y+j;
            if(valid(u,v)){
                int P=O(u,v);
                if ( dist[s][P]==-1 || dist[s][P]>w+1){
                    dist[s][P]=w+1;
                    pq.push({w+1,{u,v}});
                }
            }
        }
    }
}
void Minnnnnnn()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            cin>>a[i][j];
            if(a[i][j]=='S') pos.pb({i,j});
        }
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<k;i++) calc(i);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            int P=O(pos[j].fi,pos[j].se);
            dis[i][j]=dist[i][P];
        }
    }
    for(int i=0;i<k;i++){
        dp[1<<i][i]=dist[i][1];
    }
//    for(int i=0;i<k;i++)
//    {
//        for(int j=0;j<k;j++) cout<<dis[i][j]<<' ';
//        el;
//    }
    for(int mask=1;mask<(1<<k);mask++){
        for(int i=0;i<k;i++) if(bit(mask,i) && dp[mask][i]!=-1){
//            cout<<mask<<' '<<i<<' '<<dp[mask][i]; el;
            for(int j=0;j<k;j++) if(!bit(mask,j) && dis[i][j]>0){
                if(dp[mask|(1<<j)][j]==-1) 
                    dp[mask|(1<<j)][j]=dp[mask][i]+dis[i][j];
                else
                    minimize(dp[mask|(1<<j)][j],dp[mask][i]+dis[i][j]);
            }
        }
    }
    int ans=oo;
    int tmp=(1<<k)-1;
    for(int i=0;i<k;i++) if(dp[tmp][i]!=-1) minimize(ans,dp[tmp][i]);
    if(ans==oo) ans=-1;
    cout<<ans;
}


int main(){
    FPTU;


    int Test_case=1;
//    cin>>Test_case;
    
    for(int _=1;_<=Test_case;_++)
    {
//        cout<<"Case #"<<_<<": ";
        Minnnnnnn();
//        el;
    }
    
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
