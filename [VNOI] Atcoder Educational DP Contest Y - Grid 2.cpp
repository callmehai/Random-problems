#pragma GCC optimize ("O3")

//#include <bits/stdc++.h>

#include <iostream>     // Input/output stream objects
#include <fstream>      // File stream objects
#include <sstream>      // String stream objects
#include <iomanip>      // Input/output manipulators
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>        // Date and time functions
#include <cstdlib>      // General purpose functions
#include <cstring>      // C-style string functions
#include <cctype>       // Character classification functions
#include <cassert>      // Assert function for debugging
#include <exception>
#include <functional>
#include <iterator>
#include <limits>
#include <locale>       // Localization and internationalization
#include <numeric>
#include <random>
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

ll rand_num(ll a,ll b) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}

int mod=1e9+7; // MODDDDDDDDDDDDD

template <typename T> void minimize(T &a, T b){ if(a>b)  a=b; }
template <typename T> void maximize(T &a, T b){ if(a<b)  a=b; }
template <typename T> void add(T &a, T b){ a+=b; if(a>=mod) a-=mod; }
template <typename T> T gcd(T a, T b)
{
    while(a!=0&&b!=0)
    {
        if(a>b) a%=b;
        else b%=a;
    }
    return a+b;
}
vector<pair<int,int>> queen  = {{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
vector<pair<int,int>> knight = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
vector<pair<int,int>> bishop = {{-1,-1},{-1,1},{1,-1},{1,1}};
vector<pair<int,int>> rook   = {{-1,0},{0,-1},{0,1},{1,0}};

void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}
// =========> <3 VietHai1709 <3  <=========
ull mulmod(ull a,ull b,ull mod) //  a * b % mod
{
    ull base=a;
    ull ans=0;
    for (; b > 0; b >>= 1, (base*=2)%=mod)
       if (b & 1) (ans += base) %= mod ;
    
   return ans;
}
ull powmod(ull b, ull e, ull mod) { // a ^ b % mod
    ull ans = 1;
    for (; e ; e >>= 1, b = mulmod(b, b, mod))
        if (e & 1) ans = mulmod (ans, b, mod) ;
    return ans;
}
const int N=2e5;
ll gt[N+5],igt[N+5];
ll ckn(int n,int k){
    return gt[n]*igt[k]%mod*igt[n-k]%mod;
}
ll f(pii x, pii v){
    return ckn((v.fi-x.fi)+(v.se-x.se), (v.fi-x.fi) );
}
void Minnnnnnn()
{
    gt[0]=1;
    for(int i=1;i<=N;i++) gt[i]=(gt[i-1]*i)%mod;
    igt[N]=powmod(gt[N], mod-2, mod);
    for(int i=N-1;i>=0;i--) igt[i]=(igt[i+1]*(i+1))%mod;
    
    ll n,m,k;
    cin>>n>>m>>k;
    vt<pii> a(k);
    for(auto &[x,y]:a) cin>>x>>y;
    a.pb({n,m});
    k++;
    sort(all(a));
    vt<ll> dp(k+5,0);

    for(int i=0;i<k;i++){
        dp[i]=f({1,1},a[i]);
        for(int j=0;j<i;j++)
            if(a[j].fi<=a[i].fi && a[j].se<=a[i].se){
            ll k =dp[j];
            ll p =f(a[j],a[i]);
            dp[i]-=(k*p%mod);
            (dp[i]+=mod)%=mod;
        }
    }
//    for(int i=0;i<k;i++){
//        cout<<a[i].fi<<' '<<a[i].se<<' '<<dp[i]<<'\n';
//    }
    cout<<dp[k-1];
}
int main(){
    FPTU;// read_file();
    int Test_case=1;
    //cin>>Test_case;
    while(Test_case--)
    {
        Minnnnnnn();
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}


/*
******************************
*             _|             *
*           _|_|_|           *
*     _|_|_|_|_|_|_|_|_|     *
*       _|_|_|_|_|_|_|       *
*         _|_|_|_|_|         *
*       _|_|_|  _|_|_|       *
*     _|_|_|      _|_|_|     *
******************************
*
*     (\_/)
*     ( •_•)
*     / > > Vietnam
*
*     (\_/)
*     (^_^)
*     />o<\
*
*/
