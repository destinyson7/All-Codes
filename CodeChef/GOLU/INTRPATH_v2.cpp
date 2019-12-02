#include<bits/stdc++.h>
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define ll long long int
#define ld unsigned long long int
#define pi pair<ll,ll>
#define pb push_back
#define pf push_front
#define pu push
#define po pop
#define fi first
#define se second
#define mk make_pair
#define ve vector
#define lr(n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define be begin

struct LCA {
    vector<ll> height, euler, first, segtree;
    vector<bool> visited;
    ll n;

    LCA(vector<list<ll>> &adj, ll root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<list<ll>> &adj, ll node, ll h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(ll node, ll b, ll e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            ll mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            ll l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    ll query(ll node, ll b, ll e, ll L, ll R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        ll mid = (b + e) >> 1;

        ll left = query(node << 1, b, mid, L, R);
        ll right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    ll lca(ll u, ll v) {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

ll start[300001];
ll finish[300001];
ll ran[300001];

void dfs(ve<list<ll> > &ar,ve<ll> &visit,ll x,ll &s, auto &arr,ll n){
    visit[x]=1;
    start[x]=s;
    queue<ll>q;
    ll cnt=0;
    for(auto i:ar[x]){
        if(visit[i]==1)
            continue;
        s++;
        cnt++;
        q.push(i);
        dfs(ar,visit,i,s,arr,n);
    }
    s++;
    finish[x]=s;
    ran[x]=n;
    ll y=n-1;
    arr[x] = new pi [cnt+1];
    arr[x][0]=mk(cnt,0);
    ll sum=0;
    for(ll i=1;i<=cnt;i++){
        ll a=q.front();
        ll z=(finish[a]-start[a]-1)/2+1;
        y-=z;
        sum+=z;
        ran[x]+=z*y;
        arr[x][i]=mk(finish[a],a);
        q.pop();
    }
    arr[x][0].se=sum;
}

ll bi(auto &ar,ll y,ll w){
    ll l=1,r=ar[0].fi,b=(l+r)/2;
    if(y==w)
        return w;
    ll x=finish[y];
    while(l<=r){
        b=(l+r)/2;
        if(ar[b].fi==x || (ar[b].fi>x && (b==l || ar[b-1].fi<x)))
            return ar[b].se;
        else if(ar[b].fi>x)
            r=b-1;
        else
            l=b+1;
    }
}

ll rang[300001];

void dfs1(auto &ar,auto &visit,ll x,auto &arr,ll n){
    visit[x]=1;
    for(auto i:ar[x]){
        if(visit[i]==1)
            continue;
        ll y=(finish[i]-start[i]-1)/2+1;
        rang[i]=rang[x]-(arr[x][0].se-y)*y-y+ ran[i]-(n-1-arr[i][0].se)-(arr[i][0].se)*(n-1-arr[i][0].se);
        dfs1(ar,visit,i,arr,n);
    }
}

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ll t;
        cin>>t;
        while(t--){
            ll n,q;
            cin>>n>>q;
            ve<ll>visit(n,0);
            ve<list<ll> >ar(n);
            for(ll i=0,u,v;i<n-1;i++){
                cin>>u>>v;
                u--,v--;
                ar[u].pb(v);
                ar[v].pb(u);
            }
            ve<pi *> arr(n);
            ll s=0;
            dfs(ar,visit,0,s,arr,n);
            lr(n)
                visit[i]=0;
            rang[0]=ran[0];
            dfs1(ar,visit,0,arr,n);
            LCA  obj(ar);
            
            while(q--){
                ll u,v;
                cin>>u>>v;
                u--,v--;
                if(u==0){
                    cout << rang[v] << "\n";
                    continue;
                }
                if(v==0){
                    cout << rang[u] << "\n";
                    continue;
                }
                if(u==v){
                    cout << ran[v] << "\n";
                    continue;
                }
                ll x = obj.lca(u,v);
                if(u==x){
                    ll a=bi(arr[x],v,x);
                    ll y=(finish[a]-start[a]-1)/2+1;
                    ll ans=rang[v]-rang[x]+ran[x]-y*(n-1-arr[x][0].se);
                    cout << ans << "\n";
                    continue;
                }
                if(v==x){
                    ll a=bi(arr[x],u,x);
                    ll y=(finish[a]-start[a]-1)/2+1;
                    ll ans=rang[u]-rang[x]+ran[x]-y*(n-1-arr[x][0].se);
                    cout << ans << "\n";
                    continue;
                }
                ll a=bi(arr[x],u,x);
                ll b=bi(arr[x],v,x);
    
                ll y=(finish[a]-start[a]-1)/2+1;
                ll z=(finish[b]-start[b]-1)/2+1;
                ll ans=rang[u]-rang[x]+ran[x]-(n-1-arr[x][0].se)*y+rang[v]-rang[x]-(n-1-arr[x][0].se)*z+y*z;
                cout << ans << "\n";
            }
        }
        return 0;
    }