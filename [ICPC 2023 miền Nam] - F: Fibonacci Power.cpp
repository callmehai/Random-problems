
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
#define bitcount(n) __builtin_popcount(n)
#define bitcountll(n) __builtin_popcountll(n);
#define db(x) cerr << #x << " = " << (x) << '\n';
#define el cout<<'\n';
random_device rd;
mt19937 mt(rd());
ll rand_num(ll a,ll b) {

    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}

const int mod=998244353; // MODDDDDDDDDDDDD 998244353, 1e9+7

template<typename T>void minimize(T &a, T b){ if(a>b)  a=b; }
template<typename T>void maximize(T &a, T b){ if(a<b)  a=b; }
template<typename T>void add(T &a, T b){ a+=b; if(a>=mod) a-=mod; }
template<typename T>void sub(T &a, T b){ a-=b; if(a<0) a+=mod; }
template<typename T> T gcd(T a, T b)
{
    if(a<b) swap(a,b);
    while(a){
        b%=a;
        swap(a,b);
    }
    return b;
}

void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}

// =========> <3 VietHai1709 <3  <=========

void build_test()
{
    char x[]="out000.txt";
    int num_test=39;

    for(int ii=31;ii<=num_test;ii++)
    {
        string s=to_string(ii);
        int c=5;
        int u=(int)s.size()-1;
        while(u>=0)
        {
            x[c--]=s[u--];
        }
        freopen(x, "w", stdout);

        cerr<<"Done test "<<x<<"  ||  "<<TIME << " s.\n";;

    }
}

struct ModInt {
    int value;
    
    ModInt(ll x=0){
        if(-mod < x && x < 2*mod){
            value=(int)x;
            if(value >= mod) value-=mod;
            if(value < 0) value+=mod;
        }
        else{
            value=x%mod;
            if(value < 0) value+=mod;
        }
    }
    
    void operator += (const ModInt &x){
        add(value,x.value);
    }
    
    ModInt operator + (const ModInt &x) const{
        ModInt res=*this;
        res+=x;
        return res;
    }
    
    void operator -= (const ModInt &x){
        sub(value,x.value);
    }
    
    ModInt operator - (const ModInt &x) const{
        ModInt res=*this;
        res-=x;
        return res;
    }
    
    void operator *= (const ModInt &x){
        value= 1ll * value * x.value % mod;
    }
    
    ModInt operator * (const ModInt &x) const{
        ModInt res=*this;
        res*=x;
        return res;
    }
    ModInt operator ^ (ll k) const{
        ModInt res(1), exp=*this;
        while(k){
            if(k&1) res*=exp;
            exp*=exp;
            k>>=1;
        }
        return res;
    }
    
    ModInt inverse() const;
    
    void operator /= (ModInt &x){
        *this *= x.inverse();
    }
    
    ModInt operator / (ModInt &x) const{
        ModInt res=*this;
        res /= x;
        return res;
    }
    
};

const int N = 1000100;

ModInt gt[N],igt[N],inv[N];

void prepare(){
    gt[0]=1;
    
    for(int i=1;i<N;i++) gt[i] = gt[i-1] * i;
    
    igt[N-1] = gt[N-1] ^ (mod-2);
    
    for(int i=N-1;i>=1;i--) igt[i-1] = igt[i] * i;
    
    for(int i=1;i<N;i++) inv[i]= gt[i-1] * igt[i];
}

ModInt ModInt::inverse() const{
    assert(value!=0);
    
    return( 1 <= value && value < N) ? inv[value] : *this ^ (mod-2);
    
}

ModInt ckn(int k,int n){
    return k>n ? ModInt(0) : gt[n] * igt[k] * igt[n-k];
}

struct Complex{
    ModInt a,b; // a + b*sqrt(5)
    
    Complex(const ModInt &_a = 0, const ModInt &_b = 0) {
        a = _a; b = _b;
    }
    
    void operator += (const Complex &c) {
        a += c.a; b += c.b;
    }
    Complex operator + (const Complex &c) const{
        Complex res = *this;
        res += c;
        return res;
    }
 
    void operator -= (const Complex &c) {
        a -= c.a; b -= c.b;
    }
    Complex operator - (const Complex &c) const{
        Complex res = *this;
        res -= c;
        return res;
    }
 
    // (a,b*i) * (c.a,c.b*i)
    // = a*c.a + i^2*b*c.b, a*c.b*i + b*c.a*i
    // = (a*c.a + i^2*b*c.b, (a*c.b + b*c.a) * i)
    Complex operator * (const Complex &c) const{
        return Complex(a * c.a + b * c.b * 5 , a * c.b + b * c.a);
    }
    
    // (a+bi)*(a-bi) = a*a - b*b*i^2
    // => 1 / (a+bi) = (a-bi) / (a*a - b*b*i^2)
    //               = (a-bi) * _inv
    //               = Complex(a*_inv, (ModInt(0)-b)*_inv)
    Complex inverse() const{
        ModInt invModul = (a * a - b * b * 5).inverse();
        return Complex(a * invModul, (ModInt(0) - b) * invModul);
    }
 
    Complex operator / (const Complex &c) const{
        return *this * c.inverse();
    }
 
    Complex operator ^ (ll k) const {
        Complex res(1, 0), mul = *this;
        while (k > 0) {
            if (k & 1) res = res * mul;
            mul = mul * mul;
            k >>= 1;
        }
        return res;
    }
};

// F[n]   = 1/sqrt(5) * [ (1+sqrt(5))^n - (1-sqrt(5))^n ]
// F[n]   = tmp * [ a^n - b^n ]
// F[n]^k = tmp^k * ( a^n - b^n )^k
//        = tmp^k * sum( (-1)^i * C(i,k) * a^n^(k-i) * b^n^i )
//        = tmp^k * sum( (-1)^i * C(i,k) * [ a^(k-i) * b^i ] ^ n )
//         (const) (for)      (const)      (const)   (const)
//        = tmp^k * sum( coeff[i] * (pwa[k-i]*pwb[i]) ^ n)
//        = tmp^k * sum( coeff[i] *  X[i] ^ n)

// S =  F[1]^k + ... + F[n]^k
//   =  tmp^k * sum( coeff[i] *  (X[i]^1 + ... + X[k]^n) )
//     (const)  (for) (const)           (for)

// optimize:
//      S     = X[i]^1 + X[i]^2 + ... + X[i]^n
//   X[i]*S   = X[i]^2 + X[i]^3 + ... + X[i]^(n+)
// (X[i]-1)*S = X[i]^(n-1) - X[i]
//  =>  S     = (X[i]^(n-1) - X[i] ) / (X[i]-1)
// * if(X[i] == 1) => S = n

// => calc S in O(k*log(n))

Complex coeff[N],    base[N],   pwA[N],   pwB[N];
//  C(i,k), (-1)^i*(pwA[k-i]*pwB[i]),  (1+sqrt(5))^i,  (1-sqrt(5))^i

Complex geometricSum(const Complex &x, ll n) {
    // x^1 + x^2 + ... + x^n
    
    if (x.a.value == 1 && x.b.value == 0)
        return Complex(ModInt(n), ModInt(0));
    
    return ((x ^ (n + 1)) - x ) / (x - Complex(1, 0));
}

void solve(ll n,int k)
{
    Complex tmp = Complex(0,1).inverse(); // 1 / sqrt(5)
    tmp = tmp ^ k;
    
    Complex a = Complex(1, 1) / Complex(2,0); // (1+sqrt(5)) / 2
    Complex b = Complex(1,-1) / Complex(2,0); // (1-sqrt(5)) / 2
    
    pwA[0] = pwB[0] = Complex(1,0);
    
    for(int i=1;i<N;i++){
        pwA[i] = pwA[i-1] * a;
        pwB[i] = pwB[i-1] + b;
    }
    
    for(int i=0;i<=k;i++){
        base[i] = pwA[k-i]*pwB[i];
        coeff[i] = Complex(ckn(i,k),0);
        if(i&1) coeff[i] = Complex(-1,0) * coeff[i]; // *(-1)^i
    }
    
    Complex res(0,0);
    // res = 1/sqrt(5)^k * sum(coeff[i] * (base[i]^1+...+base[i]^n))
    // res =    tmp      * sum(coeff[i] *  geometricSum(base[i],n) )
    
    for(int i=0;i<=k;i++) res += coeff[i]*geometricSum(base[i], n);
    res = res * tmp;
    
    assert(res.b.value==0);
    cout<<res.a.value;
    
}
int main(){
    FPTU;

//    build_test();
    
//    read_file();
    
    prepare();
    
    ll n; int k;
    cin>>n>>k;
    solve(n,k);
    
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
//https://oj.vnoi.info/problem/icpc23_mn_f
