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
ll deg[300005],cnt[300005],my[300005],vis[300005],arr[300005],size;
ll findcnt(ll root, mv *adj)
{
    if(vis[root])
    {
        return 0;
    }
    vis[root]=1;
    ll i,c=1;
    for(i=0;i<adj[root].size();i++)
    {
        c+=findcnt(adj[root][i],adj);
    }
    cnt[root]=c;
    return c;
}
void findmy(ll root,ll s,mv *adj)
{
    if(vis[root])
    {
        return ;
    }
    vis[root]=1;
    my[root]=s;
    ll i,c=0,tmp;
    for(i=0;i<adj[root].size();i++)
    {
        if(vis[adj[root][i]]==0)
        {
            c+=cnt[adj[root][i]];
        }
    }
    tmp=c;
    ll ss=1+c+s;
    for(i=0;i<adj[root].size();i++)
    {
        if(vis[adj[root][i]]==0)
        {
            tmp-=cnt[adj[root][i]];
            ss+=(tmp*cnt[adj[root][i]]);
        }
    }
    for(i=0;i<adj[root].size();i++)
    {
        if(vis[adj[root][i]]==0)
        {
            findmy(adj[root][i],ss-(cnt[adj[root][i]]*(1+c-cnt[adj[root][i]])),adj);
        }
    }
}
void conlca(mv *adj,mv *nbs,ll root,ll cc)
{
    if(vis[root])
    {
        return ;
    }
    vis[root]=1;
    deg[root]=cc++;
    ll i=1;
    while(i<=size)
    {
        nbs[root].push_back(arr[size-i]);
        i*=2;
    }
    arr[size++]=root;
    for(i=0;i<adj[root].size();i++)
    {
        conlca(adj,nbs,adj[root][i],cc);
    }
    size--;
}
ll findkth(ll root,mv *nbs,string s,ll pos)
{
    if(pos==-1)
    {
        return root;
    }
    while(s[pos]==0)
    {
        pos--;
        if(pos==-1)
        {
            return root;
        }
    }
    return findkth(nbs[root][pos],nbs,s,pos-1);
}
void doround(mv *adj,ll root,ll N)
{
    if(vis[root])
    {
        return ;
    }
    vis[root]=1;
    ll s=N,c=N-1,i;
    for(i=0;i<adj[root].size();i++)
    {
        if(vis[adj[root][i]]==0)
        {
            c-=cnt[adj[root][i]];
            s+=(cnt[adj[root][i]]*c);
        }
    }
    arr[root]=s;
    for(i=0;i<adj[root].size();i++)
    {
        doround(adj,adj[root][i],N);
    }
}
ll findanc(ll u,ll v,mv *nbs)
{
    ll i=min(nbs[u].size()-1,nbs[v].size()-1);
    if(i<0)
    {
        return u;
    }
    while(nbs[u][i]==nbs[v][i])
    {
        i--;
        if(i==-1)
        {
            return nbs[u][0];
        }
    }
    return findanc(nbs[u][i],nbs[v][i],nbs);
}
int main(void)
{
    fastio
    ll root,i,T,N,Q,u,v,anc,ou,ov,tmp,ans;
    string s;
    cin>>T;
    while(T--)
    {
        cin>>N>>Q;
        mv adj[N+5],nbs[N+5];
        for(i=0;i<N+2;i++)
        {
            deg[i]=vis[i]=0;
        }
        for(i=0;i<N-1;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        for(i=1;i<=N;i++)
        {
            if(deg[i]==1)
            {
                root=i;
                break;
            }
        }
        findcnt(root,adj);
        for(i=0;i<N+2;i++)
        {
            vis[i]=0;
        }
        findmy(root,1,adj);
        for(i=0;i<N+2;i++)
        {
            deg[i]=vis[i]=0;
        }
        size=0;
        conlca(adj,nbs,root,0);
        for(i=0;i<N+2;i++)
        {
            vis[i]=0;
        }
        doround(adj,root,N);
        while(Q--)
        {
            cin>>u>>v;
            if(u==v)
            {
                cout<<arr[u]<<"\n";
                continue;
            }
            if(deg[u]>deg[v])
            {
                tmp=u;
                u=v;
                v=tmp;
            }
            tmp=deg[v]-deg[u];
            s="";
            while(tmp>0)
            {
                s+=tmp%2;
                tmp/=2;
            }
            tmp=findkth(v,nbs,s,s.size()-1);
            if(u==tmp)
            {
                tmp=deg[v]-deg[u]-1;
                s="";
                while(tmp>0)
                {
                    s+=tmp%2;
                    tmp/=2;
                }
                ou=u;
                u=findkth(v,nbs,s,s.size()-1);
                ans=my[v]-my[u]+arr[ou]+arr[v]-cnt[u]*(N-cnt[u])-cnt[v]*(N-cnt[v]);
            }
            else
            {
                anc=findanc(u,tmp,nbs);
                tmp=deg[v]-deg[anc]-1;
                s="";
                while(tmp>0)
                {
                    s+=tmp%2;
                    tmp/=2;
                }
                ov=findkth(v,nbs,s,s.size()-1);
                tmp=deg[u]-deg[anc]-1;
                s="";
                while(tmp>0)
                {
                    s+=tmp%2;
                    tmp/=2;
                }
                ou=findkth(u,nbs,s,s.size()-1);
                ans=my[u]-my[ou]+my[v]-my[ov]+arr[u]+arr[v]+arr[anc]-cnt[u]*(N-cnt[u])-cnt[v]*(N-cnt[v])-cnt[ou]*(N-cnt[ou])-cnt[ov]*(N-cnt[ou]-cnt[ov]);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}