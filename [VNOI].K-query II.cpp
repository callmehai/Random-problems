#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
//**Variable**//
int n;
int A[30006];
int VAL = 10000;
int sz;
int T[4*175][10001];
int idx[30006];
int t;
int q, x, y, k;
//**Struct**//

//**Function**//
void updateBIT(int block, int k, int val){
    for(int i = k; i>0; i-=i&-i){
        T[block][i]+=val;
    }
}
int getBIT(int block, int k){
    int ans = 0;
    for(int i = k; i<=VAL; i+=i&-i){
        ans += T[block][i];
    }
    return ans; 
}
void build(int id, int l, int r){
    if(l == r){
        return idx[l] = id, void();
    }
    int mid = (l + r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}
void update(int block, int pos, int val){
    updateBIT(idx[block],val,1);
    int id = idx[block];
    while(id/=2){
        updateBIT(id,val,1);
    }
}
void replace(int block, int pos, int val){
    int id = idx[block];
    updateBIT(idx[block],A[pos],-1);
    while(id/=2){
        updateBIT(id,A[pos],-1);
    }
    id = idx[block];
    A[pos] = val;
    updateBIT(idx[block],A[pos],1);
    while(id/=2){
        updateBIT(id,A[pos],1);
    }
}
int get(int id, int l, int r, int u, int v, int k){
    if(u > v || l > r || u > r || l > v)return 0;
    if( u <= l && r <= v)return getBIT(id,k);
    int mid = (l + r)/2;
    return get(id*2, l, mid, u, v, k) + get(id*2+1, mid+1, r, u, v, k);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    sz = sqrt(n);
    int m = n/sz;
    build(1,1,m);
    for(int i = 1; i<=n; i++){
        cin>>A[i];
        update(i/sz + 1 - (i%sz == 0), i,A[i]);
    }
    cin>>q;
    while(q--){
        cin>>t;
        if( t==0 ){
            cin>>x>>y;
            replace(x/sz + 1 - (x%sz == 0), x, y);
        }else{
            cin>>x>>y>>k;
            int L = x/sz + 1 - (x%sz == 0);
            int R = y/sz + 1 - (y%sz == 0);
            int ans = 0;
            if(L == R){
                for(int i = x; i<=y; i++){
                    ans += A[i] > k;
                }
                cout<<ans<<"\n";
                continue;
            }
            if(L+1 > R - 1 || k + 1 > VAL)ans = 0;
            else{
                ans = get(1,1,m,L+1,R-1,k + 1);
            }
            for (int i=x; i<=L*sz; i++) ans += (A[i] > k);
            for (int i=(R-1)*sz+1; i<=y; i++) ans += (A[i] > k);
            cout<<ans<<"\n";
        }
    }
    return 0;
}





