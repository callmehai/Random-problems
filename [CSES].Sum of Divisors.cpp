//13-12-2019 <3
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cassert>
#include <list>
#include <tuple>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstdio>
#include <random>
using namespace std;
 
// ************ Setting up  ************
#define FPTU ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define BUG(x) {cerr << #x << " = " << x << endl;}
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ll long long
#define ull unsigned long long
#define usi unsigned int
#define pll pair<ll,ll>
#define plp pair<ll,pll>
#define ppl pair<pll,ll>
#define ppp pair<pii,pii>
#define oo 1000111000
#define ooo 1000111000111000111
#define inf 4557430888798830399
#define fi first
#define se second
#define pri_qu priority_queue
#define vt vector
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define bitmin(n) __builtin_ctzll(n)
#define bitmax(n) 31-__builtin_clz(n)
#define bitmaxll(n) 63-__builtin_clz(n)
 
#define db(x) cerr << #x << " = " << (x) << '\n';
void build_test();
random_device rd;
mt19937 mt(rd());
ll rand_num(ll a,ll b)
{
    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}
template <typename T> void minimize(T &a, T b){ if(a>b)  a=b; }
template <typename T> void maximize(T &a, T b){ if(a<b)  a=b; }
template <typename T> void  minimod(T &a, T b){ if(a>=b) a-=b;}
template <typename T> T gcd(T a, T b)
{
    while(a!=0&&b!=0)
    {
        if(a>b) a%=b;
        else b%=a;
    }
    return a+b;
}
vt<pii> wasd={{-1,0}, {0,-1}, {0,1}, {1,0}};
vt<pii> WASD={{-1,0}, {0,-1}, {0,1}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
vt<pii> knight={{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
vt<string> step ={"U", "L", "R", "D", "LU", "RU", "LD", "RD"};
pri_qu<pii,vector<pii>,greater<pii>> pq;
void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}
// =========> <3 VietHai1709 <3  <=======
ll mod=1e9+7;
ll poww(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%mod;
    ll x=poww(a,b/2);
    if(b&1) return x*x%mod*a%mod;
    return x*x%mod;
}
ll inv_mod(ll a)
{
    return poww(a,mod-2);
}
ll inv_2;
ll sum(ll l,ll r)
{
    return (l+r)%mod*((r-l+1)%mod)%mod*inv_2%mod;
}
void Missing_Min()
{
    ll n;
    cin>>n;
    inv_2=inv_mod(2);
    ll i=1,nxt=-1;
    ll ans=0;
    while(nxt<=n)
    {
        ll q=n/i;
        nxt=n/q+1;
        ans+=(sum(i,nxt-1)*(q%mod)%mod);
        if(ans>=mod) ans-=mod;
        i=nxt;
    }
    cout<<ans;
}
int main(){
    FPTU; //read_file();
 
    int Test_case=1;
    //cin>>Test_case;
    while(Test_case--)
    {
        Missing_Min();
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
