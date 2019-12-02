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
ll arr[810][810],pre[810];
ll get(ll a,ll i,ll b)
{
    return pre[b]-pre[a-1]+(a==i? 0:1)*(arr[a][i])+(b==i+1? 0:1)*(arr[i+1][b]);
}
ll find(ll a,ll b)
{
    ll i,mini=1e18;
    for(i=a;i<b;i++)
    {
        mini=min(mini,get(a,i,b));
    }
    return mini;
}
int main(void)
{
    fastio
    ll T,i,j,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(i=0;i<2*N+3;i++)
        {
            pre[i]=0;
            for(j=0;j<2*N+3;j++)
            {
                arr[i][i]=0;
            }
        }
        for(i=1;i<=N;i++)
        {
            cin>>arr[i][i];
            pre[i]=arr[i][i];
        }
        if(N==1)
        {
            cout<<"0\n";
            continue;
        }
        for(i=N+1;i<=2*N;i++)
        {
            arr[i][i]=arr[i-N][i-N];
            pre[i]=pre[i-N];
        }
        for(i=2;i<=2*N;i++)
        {
            pre[i]+=pre[i-1];
        }
        for(i=1;i<N;i++)
        {
            for(j=1;j+i<=2*N;j++)
            {
                // cout<<j<<" "<<j+i<<"\n";
                arr[j][j+i]=find(j,j+i);
            }
        }
        // for(i=1;i<=2*N;i++)
        // {
        //  for(j=1;j<=2*N;j++)
        //  {
        //      cout<<arr[i][j]<<" ";
        //  }
        //  cout<<"\n";
        // }
        j=1e18;
        for(i=1;i<=N;i++)
        {
            j=min(j,arr[i][i+N-1]);
        }
        cout<<j<<"\n";
    }
    return 0;
}