#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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
ll arr[1003];
vector <pair <ll,ll> > v;
ll fun(ll left,ll right)
{
    ll i,mini=1e18;
    for(i=left;i<=right;i++)
    {
        mini=min(mini,(right-i+1)*arr[i]);
    }
    for(i=left;i<=right;i++)
    {
        if(mini==(right-i+1)*arr[i])
        {
            break;
        }
    }
    return i;
}
void cln(ll left,ll right,ll pos)
{
    ll i,val=arr[pos];
    for(i=pos;i<=right;i++)
    {
        arr[i]-=val;
    }
}
int main(void)
{
    fastio
    ll T,ans,x,N,mini,Z,i,j;
    pair <pair <ll,ll>,ll> p;
    cin>>T;
    while(T--)
    {
        cin>>N>>Z;
        for(i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+N);
        v.clear();
        v.push_back({0,N-1});
        ans=0;
        for(i=0;i<Z;i++)
        {
            mini=1e18;
            for(j=0;j<v.size();j++)
            {
                x=fun(v[j].first,v[j].second);
                if(mini>arr[x]*(v[j].second-x+1))
                {
                    mini=arr[x]*(v[j].second-x+1);
                    p={{v[j].first,v[j].second},x};
                }
            }
            ans+=mini;
            for(j=0;j<v.size();j++)
            {
                if(v[j]==p.first)
                {
                    break;
                }
            }
            for(x=j;x<v.size()-1;x++)
            {
                v[x]=v[x+1];
            }
            cln(p.first.first,p.first.second,p.second);
            if(p.first.first!=p.second && p.first.second!=p.second)
            {
                v[v.size()-1]={p.first.first,p.second-1};
                v.push_back({p.second+1,p.first.second});
            }
            else
            {
                if(p.first.first!=p.second)
                {
                    v[v.size()-1]={p.first.first,p.second-1};
                }
                else
                {
                    if(p.first.second!=p.second)
                    {
                        v[v.size()-1]={p.second+1,p.first.second};
                    }
                    else
                    {
                        v.erase(v.end()-1);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}