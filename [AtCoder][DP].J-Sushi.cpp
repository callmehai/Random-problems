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
#define ll   long long
#define ull unsigned long long
#define usi unsigned int
#define pii pair<int,int>
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
ll mod = 1e9+7; //MODDDDDDDDDDDDD
 
void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}
 
 
// =========> <3 VietHai1709 <3  <=======
 
random_device rd;
mt19937 mt(rd());
ll rand_num(ll a,ll b)
{
    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}
void build_test()
{
    char x[]="out000.txt";
    int num_test=10;
    for(int ii=1;ii<=num_test;ii++)
    {
        string s=to_string(ii);
        int c=5;
        int u=(int)s.size()-1;
        while(u>=0)
        {
            x[c--]=s[u--];
        }
        freopen(x, "w", stdout);
        
        ll n=rand_num(20,100);
        ll m=rand_num(100000,1000000);
        set<ll> ss;
        for(int i=1;i<=n;i++) ss.insert(rand_num(1,1000000));
        n=ss.size();
        cout<<n<<' '<<m;el;
        for(auto &i:ss) cout<<i<<' ';
    }
}
double dp[301][301][301];
int n;
long double dq(int x,int y,int z){
    if(x<0 || y<0 || z<0) return 0;
    if(dp[x][y][z]>-1) return dp[x][y][z];
    
    long double res = n + x*dq(x-1,y,z) + y*dq(x+1,y-1,z) + z*dq(x,y+1,z-1);
    res/=(x+y+z);
    
    dp[x][y][z]=res;
    return res;
}
void solve()
{
    cin>>n;
    vt<int> cnt(4,0);
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        cnt[x]++;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    cout<<fixed<<setprecision(10)<<dq(cnt[1],cnt[2],cnt[3]);
}
int main(){
    
    FPTU;
//    build_test();return 0;
    // read_file();
    solve();
    cerr<<"Time: "<<TIME<<'s'<<'\n';
}
