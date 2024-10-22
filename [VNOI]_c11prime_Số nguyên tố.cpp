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
bool isPrime(ll n)
{
    if (n < 2 || n == 4) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;

    for (int x = 5; 1LL * x * x <= n; x += 6)
        if (n % x == 0 || n % (x + 2) == 0)
            return false;
            
    return true;
}

ull mulmod(ull a,ull b,ull mod) // if a*b > 1e18
{
    ull base=a;
    ull ans=0;
    for (; b > 0; b >>= 1, (base*=2)%=mod)
       if (b & 1) (ans += base) %= mod ;
    
   return ans;
}
ull powmod(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e ; e >>= 1, b = mulmod(b, b, mod))
        if (e & 1) ans = mulmod (ans, b, mod) ;
    return ans;
}
bool MillerRabin (ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ull s = __builtin_ctzll(n-1);
    ull d = n >> s;
    for (ull a : A) { // ^
        ull p = powmod(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = mulmod(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}
ll pw(ll x, ll n)
{
    ll res = 1;
    for (; n > 0; n >>= 1)
    {
        if (n & 1)
        {
            if (res <= ooo / x)
                res *= x;
            else
                res = +ooo;
        }

        if (x <= ooo / x)
            x *= x;
        else
            x = +ooo;
    }

    return res;
}
ll log(ll q,ll n){
    ll p = pow(n, double(1.0) / q);
    while (pw(p, q) < n) ++p;
    while (pw(p, q) > n) --p;
    return p;
}
void Minnnnnnn()
{
    ll n;
    cin>>n;
    for (int q = 2; q <= 60; ++q)
        {
            ll p = log(q,n);
            if (pw(p, q) == n)
            {
                if (MillerRabin(p))
                {
                    cout << p << " " << q;
                    return;
                }
            }
        }

    cout << 0;
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
