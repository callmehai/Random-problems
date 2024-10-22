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

bool cmp(pair<pii,int> &x, pair<pii,int> &y){
    return (x.fi.se-x.fi.fi) < (y.fi.se-y.fi.fi);
}
ll dp[3003][3003][2];
void Minnnnnnn()
{
    int n;
    cin>>n;
    vt<pair<pii,int>> a(n);
    for(auto &[x,y]:a){
        cin>>x.fi>>x.se>>y;
    }
    sort(all(a),cmp);
    memset(dp,inf,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=0;i<n;i++)
        for(int nc=0;nc<=i;nc++)
            for(int na=0;na<=1;na++){
                // pick a
                minimize(dp[i+1][nc][1],dp[i][nc][na]+a[i].fi.fi);
                // pick c
                minimize(dp[i+1][nc+1][na],dp[i][nc][na]+a[i].se - nc);
                // pick b
                if(na==0)
                    minimize(dp[i+1][nc][na],dp[i][nc][na]+a[i].fi.se - (i-nc));
                
            }
    ll res=ooo;
    for(int nc=0;nc<=n;nc++)
        for(int na=0;na<2;na++)
            minimize(res,dp[n][nc][na]);
    cout<<res;
}
int main(){
    FPTU; //read_file();
    int Test_case=1;
//    cin>>Test_case;
    while(Test_case--)
    {
//        cout<<"Case #"<<_<<": ";
        Minnnnnnn();
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
