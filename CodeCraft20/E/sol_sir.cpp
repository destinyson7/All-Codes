#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const ll M=1e5+5;
ll dp[M][(1<<7)+1],skill[M][7];
ll pr[M][(1<<7)+1];
ll ind[M],a[M];
bool cmp(ll p,ll q)
{
    return a[p]>a[q];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,p,k;
    cin>>n>>p>>k;
    memset(dp,-1,sizeof(dp));
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    for(ll i=1;i<=n;i++)
        for(ll j=0;j<p;j++)
            cin>>skill[i][j];
    for(ll i=1;i<=n;i++)
        ind[i]=i;
    sort(ind+1,ind+n+1,cmp);    
    dp[0][0]=0;
    for(ll i=1;i<=n;i++)
    {
        ll x=ind[i];
        for(ll mask=0;mask<(1<<p);mask++)
        {
            ll ct=0;
            for(ll j=0;j<p;j++)
                if((mask&(1<<j)))
                    ct++;
            ll z=(i-1)-ct;
            if(z<k)
            {
                if(dp[i-1][mask]!=-1)
                {
                    dp[i][mask]=dp[i-1][mask]+a[x];
                    pr[i][mask]=mask;
                }
            }
            else
            {
                if(dp[i-1][mask]!=-1)
                {
                    dp[i][mask]=dp[i-1][mask];
                    pr[i][mask]=mask;
                }
            }
            for(ll j=0;j<p;j++)
            {
                if((mask&(1<<j)) && dp[i-1][(mask^(1<<j))]!=-1)
                {
                    ll z=dp[i-1][(mask^(1<<j))]+skill[x][j];
                    if(z>dp[i][mask])
                    {
                        dp[i][mask]=z;
                        pr[i][mask]=(mask^(1<<j));
                    }
                }
            }
        }
    }
    cout<<dp[n][(1<<p)-1]<<"\n";
    std::vector<ll> ans(n+1,-1);
    ll mask=(1<<p)-1;
    ll val=0;
    for(ll i=n;i>=1;i--)
    {
        ll z=pr[i][mask];
        if(z!=mask)
        {
            ll t=(z^mask);
            ll j;
            for(j=0;j<p;j++)
                if((t&(1<<j)))
                    break;
            ans[ind[i]]=(j+1);
            val+=skill[ind[i]][(j)];
            mask=z;
        }
        else
        {
            ll ct=0;
            for(ll j=0;j<p;j++)
                if((mask&(1<<j)))
                    ct++;
            if(i-ct<=k)
            {
                ans[ind[i]]=0;
                val+=a[ind[i]];
            }
        }
    }
    for(ll j=1;j<=n;j++)
        cout<<ans[j]<<" ";
    cout<<"\n";
    return 0;
}