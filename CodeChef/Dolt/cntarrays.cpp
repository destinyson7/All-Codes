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
ll mod=1e9+7,arr[200010],size,factneginv[200010],factsinv[200010];
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
ll findarb(ll x,ll y)
{
    if(x==0)
    {
        return 0;
    }
    ll res=1;
    while(y>0)
    {
        if(y&1)
        {
            res=(res*x)%mod;
        }
        y=y>>1;
        x=(x*x)%mod;
    }
    return res; 
}
int main(void)
{
    fastio
    ll ans,sq,T,N,M,K,i,j,a,b,c,d,up,down;
    factsinv[0]=factneginv[0]=1;
    a=mod;
    for(i=1;i<200005;i++)
    {
        a--;
        factneginv[i]=modinv(a,mod-2,mod);

        factsinv[i]=modinv(i,mod-2,mod);
        // if(i<=20)
        // {
        //     cout << i << " " << factneginv[i] << " " << factsinv[i] << endl; 
        // }
    }
    cin>>T;
    while(T--)
    {
        cin>>N>>M>>K;
        ans=0;
        sq=N+M+2;
        if(K<=sq)
        {
            for(i=0;i<K;i++)
            {
                a=findarb(i+1,N);
                b=findarb(i,N);
                c=findarb(i+1,M);
                d=findarb(i,M);
                a-=b;
                c-=d;
                if(a<0)
                {
                    a+=mod;
                }
                if(c<0)
                {
                    c+=mod;
                }
                ans+=((a*c)%mod);
                if(ans>=mod)
                {
                    ans%=mod;
                }
            }
        }
        else
        {
            size=0;
            for(i=0;i<sq;i++)
            {
                a=findarb(i+1,N);
                b=findarb(i,N);
                c=findarb(i+1,M);
                d=findarb(i,M);
                a-=b;
                c-=d;
                if(a<0)
                {
                    a+=mod;
                }
                if(c<0)
                {
                    c+=mod;
                }
                ans+=((a*c)%mod);
                if(ans>=mod)
                {
                    ans%=mod;
                }
                arr[size++]=ans;
            }
            up=1;
            for(i=1;i<=size;i++)
            {
                up*=(K-i);
                if(up>=mod)
                {
                    up%=mod;
                }

                // cout << i << " " << up << endl;
            }
            down=1;
            for(i=1;i<size;i++)
            {
                // cout << i << " " << factneginv[i] << endl;
                down*=factneginv[i];
                if(down>=mod)
                {
                    down%=mod;
                }
            }
            ans=0;
            for(i=0;i<size;i++)
            {
                a=(arr[i]*up)%mod;
                a*=modinv(K-i-1,mod-2,mod);
                a%=mod;
                a*=down;
                if(a>=mod)
                {
                    a%=mod;
                }

                // cout << i+1 << " " << a << endl;
                ans+=a;
                if(ans>=mod)
                {
                    ans%=mod;
                }
                down*=(mod+i+1-size);
                down%=mod;
                down*=factsinv[i+1];
                if(down>=mod)
                {
                    down%=mod;
                }
            }
        }
        cout<<ans%mod<<"\n";
    }
    return 0;
}