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
ll par[520],vis[520];
vector <pair <ll,ll> > removee;
map <pair <ll,ll>,pair <ll,ll> > mapp;
map <pair <ll,ll>,ll> mapp2;
void BFS(ll x,mv *adj)
{
    if(vis[x])
    {
        return ;
    }
    vis[x]=1;
    ll i;
    for(i=0;i<adj[x].size();i++)
    {
        if(par[adj[x][i]]==-1)
        {
            par[adj[x][i]]=!par[x];
            mapp2[{min(x,adj[x][i]),max(x,adj[x][i])}]=1;
        }
        else
        {
            if(mapp2.find({min(x,adj[x][i]),max(x,adj[x][i])})==mapp2.end() && par[adj[x][i]]==par[x])
            {
                mapp2[{min(x,adj[x][i]),max(x,adj[x][i])}]=1;
                removee.push_back(mapp[{min(x,adj[x][i]),max(x,adj[x][i])}]);
            }
        }
    }
    for(i=0;i<adj[x].size();i++)
    {
        BFS(adj[x][i],adj);
    }
}
int main(void)
{
    ll i,N,M,u,v,x,ans;
    cin>>N>>M;
    ll stab[N+5],cost[M+5];
    mv adj[N+5];
    for(i=1;i<=N;i++)
    {
        cin>>stab[i];
    }
    for(i=1;i<=M;i++)
    {
        cin>>cost[i];
    }
    for(i=0;i<M;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mapp[{min(u,v),max(u,v)}]={cost[i],i+1};
    }
    for(i=1;i<=N;i++)
    {
        par[i]=-1;
        vis[i]=0;
    }
    par[1]=0;
    BFS(1,adj);
    sort(removee.begin(),removee.end());
    ans=0;
    for(i=0;i<removee.size();i++)
    {
        cout<<removee[i].second<<"\n";
        flush
        ans+=cost[removee[i].second];
        cin>>x;
        if(x!=2)
        {
            cin>>u>>v;
            if(x)
            {
                cost[u]=v;
            }
        }
    }
    cout<<"-1\n";
    flush
    for(i=1;i<=N;i++)
    {
        if(par[i])
        {
            cout<<"C";
        }
        else
        {
            cout<<"G";
        }
    }
    flush
    return 0;
}