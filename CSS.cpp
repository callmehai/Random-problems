#include <bits/stdc++.h>

using namespace std;

const int N=1e6;
int min_prime[N+1],a[N+1],A[N+1];
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
void resetB()
{
    for(int i=0;i<=N;i++) if(!b[i].empty()) b[i].clear();
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sang(N);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) 
        {
            a[i]=0;
            cin>>a[i];
            if(a[i]<0) a[i]*=-1;
            A[n-i+1]=a[i];
        }
        
        a[0]=0;
        A[0]=0;
        if(a[1]==0)
        {
            for(int i=2;i<=n;i++) if(a[i]>1)
            {
                a[0]=a[i];
            }
            if(a[0]==0) a[0]=2;
        }
        if(A[1]==0)
        {
            for(int i=2;i<=n;i++) if(A[i]>1)
            {
                A[0]=A[i];
            }
            if(A[0]==0) A[0]=2;
        }
        // *********
        resetB();
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=a[i];
            if(x==0) 
            {
                x=a[i-1];
                a[i]=a[i-1];
            }
            while(x>1)
            {
                int p=min_prime[x];
                b[p].push_back(i);
                while(min_prime[x]==p)
                    x/=p;
            }
        }
        for(int p=2;p<=N;p++) if(!b[p].empty())
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
        // *********
        resetB();
        for(int i=1;i<=n;i++)
        {
            int x=A[i];
            if(x==0)
            {
                x=A[i-1];
                A[i]=A[i-1];
            }
            while(x>1)
            {
                int p=min_prime[x];
                b[p].push_back(i);
                while(min_prime[x]==p)
                    x/=p;
            }
        }
        for(int p=2;p<=N;p++) if(!b[p].empty())
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
// Time elapsed: 0.882361s for n=1000000 and a[i]=0 or 510510 randomly
