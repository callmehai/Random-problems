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
int a[33333];
struct SegmentTree{
    
    vt<multiset<int>> A;
    int n;
    
    SegmentTree(int _){
        n=_;
        A.resize(n<<2);
    }
   
    void up(int id,int l,int r,int u,int old,int cur)
    {
        if(l==r){
            A[id].erase(A[id].find(old));
            A[id].insert(cur);
            return;
        }
        int mid=(l+r)>>1;
        A[id].erase(A[id].find(old));
        A[id].insert(cur);
        if(u<=mid) up(id*2,l,mid,u,old,cur);
        else up(id*2+1,mid+1,r,u,old,cur);
    }
    int get(int id,int l,int r,int u,int v,int k)
    {
        if(l>v||r<u) return 0;
        if(l>=u && r<=v)
        {
//            cout<<l<<' '<<r<<": ";
//            for(auto &x:A[id]) cout<<x<<' ';el;
            int d=0;
            for(auto &x:A[id]) if(x>k) d++;
            return d;
        }
        int mid=(l+r)/2;
        return get(id*2,l,mid,u,v,k)+get(id*2+1,mid+1,r,u,v,k);


    }
    void build(int id,int l,int r){
        if(l==r){
            A[id].insert(a[l]);
            return;
        }
        int mid=(l+r)>>1;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        A[id]=A[id*2];
        A[id].insert(A[id*2+1].begin(),A[id*2+1].end());
    }
};
void Minnnnnnn()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    SegmentTree myTree(n);
    myTree.build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        if(k==1){
            int l,r,x;
            cin>>l>>r>>x;
            cout<<myTree.get(1, 1, n, l, r, k);el;
        }
        else{
            int i,x;
            cin>>i>>x;
            myTree.up(1, 1, n, i, a[i], x);
            a[i]=x;
        }
    }
}
int main(){
    FPTU; read_file();
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
