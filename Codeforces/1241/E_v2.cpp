    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    using namespace __gnu_pbds;
    using namespace std;
    #define gcd(a,b) __gcd(a,b)
    #define ll long long int
    #define ld double
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
     
    ll vi[500001]={0};
    ll ans=0,k;
     
    pi dfs(auto &ar, ll x){

        vi[x]=1;
        ll cnt=0;
        pi f;
        priority_queue<ll>pq;
        for(auto i:ar[x]){
            if(vi[i.se]==1){
                continue;
            }
            f=dfs(ar,i.se);
            if(f.fi<k){
                pq.push(i.fi);

                cout << "* " << i.fi << " *" << x << " * "<< endl;
            }
            else{
                if(i.fi-f.se>0)
                {
                    cout << "** " << i.fi-f.se << " **" << endl;
                    pq.push(i.fi-f.se);
                }
            }
        }
        ll t;
        f.se=INF;
        while(!pq.empty()){
            cnt++;
            t=pq.top();pq.pop();
            ans+=t;
            f.se=min(f.se,t);
            if(cnt==k)break;
        }
        f.fi=cnt;
        cout << x << " " << ans << endl;
        return f;
    }
     
        int main(){
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            ll q;
            cin>>q;
            while(q--){
                ll n;
                cin>>n>>k;
                ve<ve<pi>>ar(n+1);
                for(ll i=1,u,v,w;i<n;i++){
                    cin>>u>>v>>w;
                    ar[u].pb(mk(w,v));
                    ar[v].pb(mk(w,u));
                }
                ans=0;
                lr(n+1)
                    vi[i]=0;
                dfs(ar,1);
                cout << ans << "\n";
            }
            return 0;
        }
     