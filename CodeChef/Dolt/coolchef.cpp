#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mm map <ll,ll>
#define mv vector <ll>
#define mp pair <ll,ll>
#define ms set <ll>
#define mq queue <ll>
#define mdq deque <ll>
#define mst stack <ll>
#define mpq priority_queue <ll>
#define mmh priority_queue <ll, vector<ll>, greater<ll> >
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define flush cout.flush();
ll mod=1e9+7,*facts,*factsinv,*arr,*intercnt,**maini,**cnt;
ll modinv(ll x,ll y,ll m)
{
    if(y==0)
    {
        return 1;
    }
    ll p=modinv(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
int main(void)
{
    fastio
    ll i,j,a=1,N,sqN,Q,l1,l2,r1,r2;
    mm mapp;
    cin>>N>>Q;
    facts=(ll *)malloc((N+2)*sizeof(ll));
    factsinv=(ll *)malloc((N+2)*sizeof(ll));
    arr=(ll *)malloc((N+2)*sizeof(ll));
    intercnt=(ll *)malloc((N+2)*sizeof(ll));
    facts[0]=1;
    factsinv[0]=1;
    for(i=1;i<=N;i++)
    {
        a*=i;
        if(a>=mod)
        {
            a%=mod;
        }
        facts[i]=a;
        factsinv[i]=modinv(a,mod-2,mod);
    }
    a=1;
    sqN=sqrt(N);
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
        intercnt[i]=arr[i];
    }
    sort(intercnt,intercnt+N);
    mapp[intercnt[0]]=a++;
    for(i=1;i<N;i++)
    {
        if(intercnt[i]!=intercnt[i-1])
        {
            mapp[intercnt[i]]=a++;
        }
    }
    for(i=0;i<N;i++)
    {
        arr[i]=mapp[arr[i]];
        intercnt[i+1]=0;
    }
    for(i=N-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    maini=(ll **)malloc((sqN+2)*sizeof(ll *));
    cnt=(ll **)malloc((sqN+2)*sizeof(ll *));
    for(i=0;i<sqN+1;i++)
    {
        maini[i]=(ll *)malloc(((i+1)*sqN+2)*sizeof(ll));
        cnt[i]=(ll *)malloc((N+2)*sizeof(ll));
    }
    i=sqN;
    for(;i<=N;i+=sqN)
    {
        l1=(i/sqN)-1;
        for(j=1;j<=N;j++)
        {
            cnt[l1][j]=0;
        }
        a=1;
        for(j=i;j>0;j--)
        {
            cnt[l1][arr[j]]+=1;
            a*=cnt[l1][arr[j]];
            if(a>=mod)
            {
                a%=mod;
            }
            maini[l1][j]=a;
        }
    }
    a=0;
    while(Q--)
    {
        cin>>l1>>l2>>r1>>r2;
        l1=(l1*a+l2)%N;
        r1=(r1*a+r2)%N;
        if(l1>r1)
        {
            a=l1;
            l1=r1;
            r1=a;
        }
        l1++;
        r1++;
        l2=(r1/sqN)-1;
        if(l2==-1 || r1-l1+1<=sqN)
        {
            a=1;
            for(i=r1;i>=l1;i--)
            {
                intercnt[arr[i]]+=1;
                a*=intercnt[arr[i]];
                if(a>=mod)
                {
                    a%=mod;
                }
            }
            for(i=r1;i>=l1;i--)
            {
                intercnt[arr[i]]=0;
            }

            cout << Q << " " << "if if" << endl;
            a=facts[r1-l1+1]*modinv(a,mod-2,mod);
            a%=mod;
            cout<<a<<"\n";
        }
        else
        {
            l2=(l1/sqN);
            if(l1%sqN!=0)
            {
                l2++;
            }
            r2=(r1/sqN);
            a=maini[r2-1][l1];
            for(i=l2*sqN;i>=l1;i--)
            {
                intercnt[arr[i]]+=1;
            }
            for(i=r2*sqN+1;i<=r1;i++)
            {
                intercnt[arr[i]]+=1;
                j=intercnt[arr[i]]+cnt[r2-1][arr[i]];
                if(l2>0)
                {
                    j-=cnt[l2-1][arr[i]];
                }
                a*=factsinv[j-1];
                if(a>=mod)
                {
                    a%=mod;
                }
                a*=facts[j];
                if(a>=mod)
                {
                    a%=mod;
                }
            }
            for(i=l2*sqN;i>=l1;i--)
            {
                intercnt[arr[i]]=0;
            }
            for(i=r2*sqN+1;i<=r1;i++)
            {
                intercnt[arr[i]]=0;
            }
            a=facts[r1-l1+1]*modinv(a,mod-2,mod);
            a%=mod;
            cout<<a<<"\n";
        }
    }
    return 0;
}