//Mobius_Treap
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI >    VVI;
typedef long long int   LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(2e5)+10;
const int LOGN = 22;
VII g[N];
VI tree[N];
int arr[N],dep[N],T,level[N],DP[LOGN][N];
LL dist[N];
int Q[N],k,cnt[N];
int n,q;
LL total;
inline void dfs0(int u,int p)
{
    DP[0][u]=p;
    arr[u]=T++;
    for(int i=0;i<SZ(g[u]);i++)
    {
        int w = g[u][i].F;
        int weight = g[u][i].S;
        if(w==p)continue;
        level[w]=level[u]+1;
        dist[w]=dist[u]+weight;
        dfs0(w,u);
    }
    dep[u]=T++;
}
inline void pre_process()
{
    dfs0(1,1);
    for(int i=1;i<LOGN;i++)
        for(int j=1;j<=n;j++)
            DP[i][j] = DP[i-1][DP[i-1][j]];
}
inline int lca(int a,int b)
{
    if(level[a]>level[b])swap(a,b);
    int d = level[b]-level[a];
    for(int i=0;i<LOGN;i++)
        if((1<<i)&d)
            b = DP[i][b];
    if(a==b)return a;
    for(int i=LOGN-1;i>=0;i--)
        if(DP[i][a]!=DP[i][b])
            a = DP[i][a],b=DP[i][b];
    return DP[0][a];
}
inline bool anc(int p,int u)
{
    return (arr[p]<arr[u] && dep[p]>dep[u]);
}
inline bool cmp(int u,int v)
{
    return arr[u]<arr[v];
}
inline int create_tree()
{
    set<int> S;
    for(int i=0;i<k;i++)
        S.insert(Q[i]);
    k=0;
    for(auto it=S.begin();it!=S.end();it++)
        Q[k++]=*it;
    sort(Q,Q+k,cmp);
    int kk = k;
    for(int i=0;i<kk-1;i++)
    {
        int x = lca(Q[i],Q[i+1]);
        if(S.count(x))continue;
        Q[k++]=x;
        S.insert(x);
    }
    sort(Q,Q+k,cmp);
    stack<int> s;
    s.push(Q[0]);
    for(int i=1;i<k;i++)
    {
        while(!anc(s.top(),Q[i]))
            s.pop();
        tree[s.top()].PB(Q[i]);
        tree[Q[i]].PB(s.top());
        s.push(Q[i]);
    }
    return Q[0];
}
LL ans;
inline LL dfs(int u,int p)
{
    LL ret = cnt[u];
    for(int i=0;i<SZ(tree[u]);i++)
        if(tree[u][i]!=p)
            ret+=dfs(tree[u][i],u);
    ans += (dist[u] - dist[p]) * ret * (total-ret);
    return ret;
}
int main()
{
    si(n);si(q);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        si(u);si(v);si(w);
        g[u].PB(MP(v,w));
        g[v].PB(MP(u,w));
    }
    pre_process();
    while(q--)
    {
        si(k);
        total=0;
        for(int i=0;i<k;i++)
        {
            si(Q[i]);
            cnt[Q[i]]++;
            total++;
        }
        int root = create_tree();
        ans=0;
        dfs(root,root);
        lldout(ans);
        for(int i=0;i<k;i++)
        {
            tree[Q[i]].clear();
            cnt[Q[i]]=0;
        }
    }
    return 0;
}
