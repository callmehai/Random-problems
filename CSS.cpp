#include <bits/stdc++.h>

using namespace std;
const int N=1e6;
int min_prime[N+1],a[N+1];
vector<int> b[N+1];
int t,n;
void sang(int n)
{
    for(int i=1;i<=n;i++) min_prime[i]=i;
    for(int i=2;i*i<=n;i++) if(min_prime[i]==i)
    {
        for(int j=i*i;j<=n;j+=i) if(i<min_prime[j])
            min_prime[j]=i;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sang(N);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) 
        {
            //a[i]=510510;
            cin>>a[i];
            if(a[i]<0) a[i]*=-1;
        }
        a[0]=0;
        for(int i=1;i<=n;i++) if(!b[i].empty()) b[i].clear();
        for(int i=1;i<=n;i++)
        {
            int x=a[i];
            while(x>1)
            {
                int p=min_prime[x];
                if(a[i-1]%p==0) // Reduce the number of elements in vector b
                    b[p].push_back(i); 
                while(min_prime[x]==p)
                    x/=p;
            }
        }
        int ans=0;
        for(int p=2;p<=N;p++) if(min_prime[p]==p)
        {
            int cnt=1;
            ans=max(ans,cnt);
            for(int i=1;i<(int)b[p].size();i++)
            {
                if(b[p][i]==b[p][i-1]+1) cnt++;
                else cnt=1;
                ans=max(ans,cnt);
            }
        }

         cout<<ans<<'\n';
    }
    return 0;
}
// Time elapsed: 0.504891 s with n=1000000 and a[i]=510510.
