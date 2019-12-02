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
    #define sz(a) (ll)a.size()
    #define INF 1e18
     
    typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    // order_of_key(val): returns the number of values less than val
    // find_by_order(k): returns an iterator to the kth largest element (0-based)
     
    ll vi[100001];
    ll vis[100001];
    priority_queue<ll>pq;
     
    pi dfs(auto &ar, ll x){
        vi[x]=1;
        pi mx=mk(0,x);
        for(auto i:ar[x]){
            if(vi[i]==1)continue;
            pi cnt=dfs(ar,i);
            if(cnt.fi+1>mx.fi){
                mx.fi=cnt.fi+1;
                mx.se=cnt.se;
            }
        }
        return mx;
    }
     
    ll dfs1(auto &ar, ll x){
        vis[x]=1;
        ll mx=0;
        for(auto i:ar[x]){
            if(vis[i]==1)continue;
            ll cnt=dfs1(ar,i);
            mx=max(mx,cnt+1);
        }
        return mx;
    }
     
        int main(){
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            ll n,m;
            cin>>n>>m;
            ve<ve<ll>>ar(n);
            for(ll i=0,u,v;i<m;i++){
                cin>>u>>v;
                ar[u].pb(v);
                ar[v].pb(u);
            }

            ll cnt = 0;
            for(ll i=0;i<n;i++){
                if(vi[i]==0){
                    cnt++;
                // cout << i << "s\n";
                    pi x=dfs(ar,i);
                    ll a=dfs1(ar,x.se);
                    // cout << x.fi << "\n";
                    // cout << a << "\n";
                    // if(a%2==1)a++;
                    pq.push(a);
                }
            }
            ll ans=0,a=0,b=0;

            if(!pq.empty()){
                ans+=pq.top();pq.pop();
                a=ans;
                if(a%2==1)a++;
            }

            if(cnt>=3)
            {
                ans = max(ans, 2LL);
            }
            // cout << ans << "\n";
            if(!pq.empty()){
                b+=pq.top();pq.pop();
                // cout << b << "\n";
                if(b%2==1)b++;
                ans=max(ans,(a+b)/2+1);
            }
            cout << ans << "\n";
            return 0;
        }
     