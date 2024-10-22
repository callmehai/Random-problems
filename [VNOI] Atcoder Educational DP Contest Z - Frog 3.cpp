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
struct line{
    ll a,b;
    line(ll x=0,ll y=ooo)
    {
        a=x; b=y;
    }
    ll get(ll x)
    {
        return a*x+b;
    }
};
struct ConvextHullTrick{
    int n;
    int flag;
    vt<line> Line;
    ConvextHullTrick(){
        n=0;
        flag=0;
        Line.clear();
    }
    bool bad(line u,line v,line w)
    {
        return (double)(u.b-w.b)/(w.a-u.a)<=(double)(u.b-v.b)/(v.a-u.a);
        //return (u.b-w.b)*(v.m-u.m)<=(u.b-v.b)*(w.m-u.m);
    }
    void add(line L)
    {
        while(n>=2 && bad(Line[n-2],Line[n-1],L))
        {
            Line.pop_back();
            n--;
        }
        Line.pb(L);
        n++;
    }
    ll query(ll x)
    {
        if(flag>n-1) flag=n-1;
        while(flag+1<n && Line[flag].get(x)>Line[flag+1].get(x)) flag++;
        return Line[flag].get(x);
    }
};

void Minnnnnnn()
{
    int n;
    cin>>n;
    ll C;
    cin>>C;
    vt<ll> h(n+1);
    for(int i=1;i<=n;i++) cin>>h[i];
    ConvextHullTrick myCHT;
    ll ans=0;
    myCHT.add(line(-2*h[1],ans+h[1]*h[1]));
    for(int i=2;i<=n;i++){
        ans=myCHT.query(h[i])+C+h[i]*h[i];
//        cout<<i<<' '<<ans<<'\n';
        if(i<n) myCHT.add(line(-2*h[i],ans+h[i]*h[i]));
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
