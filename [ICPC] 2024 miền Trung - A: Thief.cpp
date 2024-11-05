//https://oj.vnoi.info/problem/icpc24_mt_a
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
ll dp[100001][2];
void Minnnnnnn()
{
    ll n,W,h;
    cin>>n>>W>>h;
    vt<pii> a(n);
    for(auto &[x,y]:a) cin>>x>>y;
    int total_c=0;
    memset(dp,60,sizeof(dp));
    dp[0][0]=0;
    dp[0][1]=0;
    for(auto &[w,c]:a){
        for(int i=total_c;i>=0;i--) {
            minimize( dp[i+c][0],dp[i][0]+w);
            
            minimize( dp[i+c][1],dp[i][1]+w);
            
            if(w<=h)
                minimize(dp[i+c][1],dp[i][0]);

            
        }
        total_c+=c;
    }
    for(int i=total_c;i>=0;i--){
        if(dp[i][1]<=W){
            cout<<i;
            return;
        }
    }
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
