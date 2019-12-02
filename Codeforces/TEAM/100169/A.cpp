#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
#define INF 1e16
typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

ve<ll>path(4000,0);
ve<ll>out(4000,0);
ve<ll>vi(4000,0);

struct node{
    ll v,w,o;
};

struct Compare{
    bool operator()(const node &a, const node &b){
        if(a.o==b.o)
            return a.w<=b.w;
        return a.o<=b.o;
    }
};

void dijk(auto &ar, ll u){
    priority_queue<node, ve<node>, Compare>pq;
    path[u]=0;
    node t;t.v=u;t.w=0;t.o=0; 
    pq.push(t);
    vi[u]=1;

    while(!pq.empty()){
        t = pq.top();pq.pop();
        if(vi[t.v]==1)continue;
        path[t.v]=t.w;
        out[t.v]=t.o;
        for(auto i:ar[t.v]){
            // if(vi[i.v]==1){
            //     continue;
            // }
            vi[i.v]=1;
            node x;
            x=i;
            x.w+=t.w;
            x.o+=t.o;

            if(out[i.v] > x.o)
            {
                out[i.v] = x.o;
                path[i.v] = x.w;
                pq.push(x);
            }

            else if(out[i.v] == x.o && path[i.v] > x.w)
            {
                out[i.v] = x.o;
                path[i.v] = x.w;
                pq.push(x);
            }

            // if(path[i.v] > path[u] + )
        }
    }
}

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ll n,m,p;
        cin>>n>>m>>p;
        ve<ve<node>>ar(n);
        for(ll i=0,u,v;i<m;i++){
            node no;char c;
            cin>>u>>v>>no.w>>c;
            no.o=0;
            if(c!='I')no.o=no.w;
            no.v=v;
            ar[u].pb(no);no.v=u;
            ar[v].pb(no);
        }
        while(p--){
            ll u,v;
            cin>>u>>v;
            lr(n){
                vi[i]=0;path[i]=INF;out[i]=INF;
            }
            dijk(ar, u);
            if(path[v]==INF){
                cout << "IMPOSSIBLE\n";
            }
            else{
                cout << out[v] << " " << path[v] << "\n";
            }
        }
        return 0;
    }